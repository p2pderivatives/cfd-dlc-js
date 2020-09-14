/* eslint-disable @typescript-eslint/no-explicit-any */
/* eslint-disable require-jsdoc */
'use strict';
import fs from 'fs';
import path from 'path';
import {Project} from 'ts-morph';
// FIXME(k-matsuzawa): Consider splitting the file.

interface JsonObjectCommonType {
  namespace: string | string[];
  commonHeader: string;
};

interface ClassMapType {
  [key: string]: DetailClassParameterType;
};

interface ClassParameterType {
  name: string;
  comment: string;
};

interface CollectMapDataResponse {
  type: string;
  comment: string;
};

interface DetailClassParameterType {
  data: JsonMappingData;
  childList: DetailParameterType[];
  parentList: string[];
};

interface DetailParameterType {
  param: ParameterType;
  data: JsonMappingData;
};

interface ParameterType {
  name: string;
  type: string;
  comment: string;
};

interface TsAppendFunctionData {
  name: string;
  parameters: ParameterType[];
  returnType: string;
  comment: string;
};

interface ReferenceClassInfo {
  name: string;
  references: Set<string>;
  weight: number;
};

// ----------------------------------------------------------------------------
// debug log function
// ----------------------------------------------------------------------------
// eslint-disable-next-line @typescript-eslint/no-unused-vars
let debugLog = function(...args: any | any[]) {
  // do nothing
};

// eslint-disable-next-line prefer-const
let requireOptionFunc = function(requireInfo: string) {
  return requireInfo !== 'optional';
};

// ----------------------------------------------------------------------------
// json data class
// ----------------------------------------------------------------------------
class JsonMappingData {
  name: string;
  methodName: string;
  variableName: string;
  initValue: string | number | boolean;
  className: string;
  classComment: string;
  childList: {[key: string]: JsonMappingData};
  parent: null;
  isOutputStruct: boolean;
  isArray: boolean;
  isObject: boolean;
  isRequire: boolean;
  comment: string;
  type: string;
  structType: string;
  constructor(name: string, type: string, initValue: string | number | boolean,
      className: string, isOutputStruct = true) {
    this.name = name;
    this.methodName = (() => {
      const replacedMethodName = this.name.replace(/-/gi, '_');
      return replacedMethodName.charAt(0).toUpperCase() +
        replacedMethodName.slice(1);
    })();
    this.variableName = (() => {
      const replacedVariableName = this.name.replace(/-/gi, '_');
      return replacedVariableName.split(/(?=[A-Z])/).join('_').toLowerCase();
    })();
    this.type = type;
    this.structType = `${type}Struct`;
    this.setType(type);
    this.initValue = initValue;
    this.className = className;
    this.childList = {};
    this.parent = null;
    this.isOutputStruct = isOutputStruct;
    this.isArray = false;
    this.isObject = false;
    this.isRequire = false;
    this.comment = '';
    this.classComment = '';
    // Reserved word support.
    // TODO(k-matsuzawa): If the number increases, make a list.
    if (this.variableName == 'asm') this.variableName = `${this.variableName}_`;
  }

  setType(type: string) {
    this.type = type;
    this.structType = `${type}Struct`;
    if (type.startsWith('JsonValueVector')) {
      const typeName = type.split('<')[1].split('>')[0];
      this.structType = `std::vector<${typeName}>`;
    } else if (type.startsWith('JsonObjectVector')) {
      const typeName = type.split('<')[1].split(',')[0].split('>')[0];
      this.structType = `std::vector<${typeName}Struct>`;
    }
  }

  setRequired(requireInfo: string) {
    this.isRequire = requireOptionFunc(requireInfo);
  }
  setComment(comment: string, hint: string) {
    if (comment) {
      this.comment = comment;
      if (hint) {
        this.comment = `${comment} (${hint})`;
      }
    }
  }

  setTypeStruct(type: string, structType: any) {
    this.type = type;
    this.structType = structType;
    if (type.startsWith('JsonValueVector')) {
      const typeName = type.split('<')[1].split('>')[0];
      this.structType = `std::vector<${typeName}>`;
    } else if (type.startsWith('JsonObjectVector')) {
      const typeName = type.split('<')[1].split(',')[0].split('>')[0];
      this.structType = `std::vector<${typeName}Struct>`;
    }
  }

  join(data: JsonMappingData) {
    const newList: {[key: string]: JsonMappingData} = {};
    for (const key2 in this.childList) {
      if (this.childList[key2]) {
        newList[key2] = this.childList[key2];
      }
    }
    for (const key1 in data.childList) {
      if (data.childList[key1]) {
        let exist = false;
        for (const key2 in this.childList) {
          if (key1 == key2) {
            exist = true;
            break;
          }
        }
        if (exist) {
          newList[key1] = data.childList[key1];
        }
      }
    }

    const obj = new JsonMappingData(
        this.name, this.type, this.initValue, this.className);
    obj.name = this.name;
    obj.methodName = this.methodName;
    obj.variableName = this.variableName;
    obj.initValue = this.initValue;
    obj.className = this.className;
    obj.classComment = this.classComment;
    obj.childList = newList;
    obj.parent = this.parent;
    obj.isOutputStruct = this.isOutputStruct;
    obj.isArray = this.isArray;
    obj.isObject = this.isObject;
    obj.isRequire = this.isRequire;
    obj.comment = this.comment;
    obj.type = this.type;
    obj.structType = this.structType;
    return obj;
  }

  toString() {
    const str = `[JsonMappingData] ${this.name}:${this.type}:${this.className}`;
    // for debug code.
    // for (const key in this.childList) {
    //   str += "\n - "
    //   str += this.childList[key].toString()
    // }
    return str;
  }

  collectMapData(map: ClassMapType, list: ClassParameterType[],
      isRequest: boolean, parentInfo: JsonMappingData): CollectMapDataResponse {
    if (this.type.startsWith('JsonValueVector') ||
        this.type.startsWith('JsonObjectVector')) {
      for (const key in this.childList) {
        if (!{}.hasOwnProperty.call(this.childList, key)) continue;
        if (this.childList[key]) {
          const ret = this.childList[key].collectMapData(
              map, list, isRequest, parentInfo);
          return {
            type: ret['type'] + '[]',
            comment: ret['comment'],
          };
        }
        break;
      }
      throw Error('Illegal state.');
    } else if (this.type === 'ErrorResponseBase') {
      const clsName = 'ErrorResponse';
      const props: DetailParameterType[] = [];
      for (const key in this.childList) {
        if (this.childList[key]) {
          const name = this.childList[key].name + (this.childList[key].isRequire ? '' : '?');
          const ret = this.childList[key].collectMapData(
              map, list, isRequest, parentInfo);
          const type = ret['type'];
          const comment = ret['comment'];
          if (name === 'isOutputStruct') {
            continue;
          }
          props.push({
            param: {name: name, type: type, comment},
            data: this.childList[key],
          });
        }
      }
      map[clsName] = {data: this, childList: props, parentList: []};
      list.push({name: clsName, comment: this.classComment});
      return {
        type: clsName,
        comment: this.classComment,
      };
    } else if (Object.keys(this.childList).length > 0) {
      // my class name
      const props: DetailParameterType[] = [];
      for (const key in this.childList) {
        if (this.childList[key]) {
          let name = this.childList[key].name + (this.childList[key].isRequire ? '' : '?');
          const ret = this.childList[key].collectMapData(
              map, list, isRequest, this);
          debugLog('prop : ', ret);
          const type = ret['type'];
          const comment = ret['comment'];
          if (name.indexOf('-') > 0) {
            name = '\'' + name + '\'';
          }
          props.push({
            param: {name: name, type: type, comment},
            data: this.childList[key],
          });
        }
      }
      debugLog(`type = ${this.type}, comment = ${this.comment}`);
      debugLog(`class = ${this.className}, clsComment = ${this.classComment}`);
      debugLog('props = ', props);
      if (map[this.type]) {
        // property check
        const appendProps = [];
        const existDataProps = map[this.type].childList;
        for (const newProp of props) {
          let exist = false;
          const srcName = newProp.param.name.replace('?', '');
          for (const prop of existDataProps) {
            const dstName = prop.param.name.replace('?', '');
            if (newProp.param.name == prop.param.name) {
              if (newProp.data.isRequire != prop.data.isRequire) {
                throw new Error(`unmatch require. caller:${this.type}, name=${prop.param.name} type=${prop.param.type},${newProp.param.type}`);
              }
              if (newProp.param.type != prop.param.type) {
                if ((newProp.param.type.indexOf('bigint') >= 0) &&
                    (prop.param.type.indexOf('bigint') >= 0)) {
                  if (prop.param.type == 'bigint') {
                    prop.param.type = newProp.param.type;
                  }
                  break;
                }
                throw new Error(`unmatch type. caller:${this.type}, name=${prop.param.name} type=${prop.param.type},${newProp.param.type}`);
              }
              exist = true;
              break;
            } else if (newProp.param.type == prop.param.type) {
              if (srcName == dstName) {
                throw new Error(`unmatch option. caller:${this.type}, name=${prop.param.name} type=${prop.param.type},${newProp.param.type}`);
              }
            } else if (srcName == dstName) {
              throw new Error(`unmatch option. caller:${this.type}, name=${prop.param.name} type=${prop.param.type},${newProp.param.type}`);
            }
          }
          if (!exist) appendProps.push(newProp);
        }
        if (appendProps) {
          const parentList = map[this.type].parentList;
          if (parentInfo != null) {
            parentList.push(parentInfo.type);
          }
          const joinData = map[this.type].data.join(this);
          for (const prop of appendProps) {
            existDataProps.push(prop);
          }
          map[this.type] = {
            data: joinData, childList: existDataProps,
            parentList: parentList,
          };
        }
      } else {
        let parentName = '';
        if (parentInfo != null) parentName = parentInfo.type;
        map[this.type] = {
          data: this, childList: props, parentList: [parentName],
        };
        list.push({name: this.type, comment: this.classComment});
      }
      return {
        type: this.type,
        comment: this.comment || this.classComment,
      };
    } else {
      let type = '';
      if (this.type === 'std::string') {
        type = 'string';
      } else if (this.type === 'bool') {
        type = 'boolean';
      } else if ((this.type === 'int64_t') || (this.type === 'uint64_t')) {
        type = (isRequest) ? 'bigint | number' : 'bigint';
      } else {
        type = 'number';
      }
      return {type: type, comment: this.comment};
    }
  }

  getFunctionName() {
    let result = '';
    if (this.type.indexOf('Request') >= 0) {
      result = this.type.substring(0, this.type.indexOf('Request'));
    } else if (this.type.indexOf('Response') >= 0) {
      result = this.type.substring(0, this.type.indexOf('Response'));
    }
    // ignore target
    if (result === 'Error') {
      return '';
    }
    return result;
  }
}

// ----------------------------------------------------------------------------
// json data class
// ----------------------------------------------------------------------------
class JsonData {
  filename: string;
  inputJsonData: any;
  requestData: JsonMappingData | null | undefined;
  responseData: JsonMappingData | null | undefined;
  constructor(filename: string, inputJsonData: any,
      requestData: JsonMappingData | null | undefined,
      responseData: JsonMappingData | null | undefined) {
    this.filename = filename.split('.').shift() || '';
    this.inputJsonData = inputJsonData;
    this.requestData = requestData;
    this.responseData = responseData;
  }
}

interface ClassCache {
  cache: Map<string, JsonMappingData>;
};

// ----------------------------------------------------------------------------
// array check function
// ----------------------------------------------------------------------------
function isArray(obj: any) {
  return (obj instanceof Array);
  // return Object.prototype.toString.call(obj) === '[object Array]';
}

// ----------------------------------------------------------------------------
// analyze function
// ----------------------------------------------------------------------------
function analyzeJson(jsonObj: any | any[],
    objName = '', arrayType = '') {
  debugLog(`analyzeJson obj=${objName}`);
  let result: JsonMappingData;
  if (typeof jsonObj == 'string') {
    return new JsonMappingData(objName, 'std::string', jsonObj, '');
  } else if (typeof jsonObj == 'number') {
    return new JsonMappingData(objName, 'int64_t', jsonObj, '');
  } else if (typeof jsonObj == 'boolean') {
    return new JsonMappingData(objName, 'boolean', jsonObj, '');
  } else if (jsonObj) {
    const objKey = Object.keys(jsonObj);
    const objValues = Object.values(jsonObj);
    // if (objKey == 0) { // array
    if (isArray(jsonObj)) {
      debugLog(`read arr = ${objValues}`);
      let pastType = '';
      let firstMap: JsonMappingData | null = null;
      for (const item in jsonObj) {
        if (!{}.hasOwnProperty.call(jsonObj, item)) continue;
        const tempChild = analyzeJson(jsonObj[item], objName);
        if (!tempChild) {
          // error
        } else if (pastType == '') {
          firstMap = tempChild;
          pastType = tempChild.type;
        } else if (pastType != tempChild.type) {
          console.log('illegal list elements. fail.');
          throw new Error('illegal list elements. fail.');
        }
      }
      debugLog(`pastType = ${pastType}`);
      if (pastType == '') {
        // field and class name is set by the caller.
        result = new JsonMappingData('', '', '', '');
      } else {
        if ((typeof objValues[0] == 'string') || (typeof objValues[0] == 'number') ||
          (typeof objValues[0] == 'boolean')) {
          // array of string or number.
          if ((typeof objValues[0] == 'number') && (arrayType)) {
            result = new JsonMappingData(objName, `JsonValueVector<${arrayType}>`, '', '');
            if (firstMap !== null) firstMap.setType(arrayType);
          } else {
            result = new JsonMappingData(objName, `JsonValueVector<${pastType}>`, '', '');
          }
        } else {
          // array of object
          result = new JsonMappingData(objName, `JsonObjectVector<${pastType}, ${pastType}Struct>`, '', '');
        }
      }
      if (firstMap !== null) {
        result.childList[0] = firstMap;
      }
      result.isArray = true;
      debugLog(`list_type = ${result.type}`);
      debugLog(`childList_type = ${result.childList[0].type}`);
      return result;
    } else { // object
      debugLog(`read keys = ${objKey}`);
      let className = objName;
      let classComment = '';
      if (':class' in jsonObj) {
        if (typeof jsonObj[':class'] === 'string') {
          className = jsonObj[':class'];
          debugLog(`read className = ${className}`);
        }
      }
      if (':class:comment' in jsonObj) {
        if (typeof jsonObj[':class:comment'] === 'string') {
          classComment = jsonObj[':class:comment'];
          debugLog(`read classComment = ${classComment}`);
        }
      }
      let isOutputStruct = true;
      if (':isOutputStruct' in jsonObj) {
        if (typeof jsonObj[':isOutputStruct'] === 'boolean') {
          isOutputStruct = jsonObj[':isOutputStruct'];
          debugLog(`set ${className}, isOutputStruct=${isOutputStruct}`);
        }
      }
      // Class name is set by the caller.
      result = new JsonMappingData(objName, className, '', '', isOutputStruct);
      result.isObject = true;
      result.classComment = classComment;
      // Stored in temporary map to maintain sort order.
      const tmpMap: {[key: string]: JsonMappingData} = {};
      const requireMap: {[key: string]: string} = {};
      const clsCommentMap: {[key: string]: string} = {};
      const commentMap: {[key: string]: string} = {};
      const hintMap: {[key: string]: string} = {};
      const arrayTypeMap: {[key: string]: string} = {};
      for (const key in jsonObj) {
        if (!{}.hasOwnProperty.call(jsonObj, key)) continue;
        if ((key != ':class') && (key != ':class:comment')) {
          if (key.lastIndexOf(':type') >= 0) {
            const keyName = key.split(':')[0];
            if (tmpMap[keyName]) {
              tmpMap[keyName].setType(jsonObj[key]);
            } else {
              const data = new JsonMappingData(keyName, jsonObj[key], '', className, isOutputStruct);
              data.classComment = classComment;
              tmpMap[keyName] = data;
              debugLog(`set JsonMappingData = ${keyName}`);
            }
          }
          if (key.lastIndexOf(':require') >= 0) {
            const keyName = key.split(':')[0];
            requireMap[keyName] = jsonObj[key];
          }
          if (key.lastIndexOf(':arraytype') >= 0) {
            const keyName = key.split(':')[0];
            arrayTypeMap[keyName] = jsonObj[key];
          }
          if (key.lastIndexOf(':comment') >= 0) {
            const keyName = key.split(':')[0];
            commentMap[keyName] = jsonObj[key];
          }
          if (key.lastIndexOf(':hint') >= 0) {
            const keyName = key.split(':')[0];
            hintMap[keyName] = jsonObj[key];
          }
        } else {
          if (key == ':class:comment') {
            const tmpKeyName = jsonObj[':class'];
            clsCommentMap[tmpKeyName] = jsonObj[key];
          }
        }
      }

      for (const key in jsonObj) {
        if (!{}.hasOwnProperty.call(jsonObj, key)) continue;
        if (key.indexOf(':') == -1) {
          debugLog(`read key = ${key}`);
          const value = jsonObj[key];
          if (tmpMap[key]) {
            result.childList[key] = tmpMap[key];
            result.childList[key].initValue = value;
          } else {
            // type check
            let typeStr = '';
            if (typeof value == 'string') {
              typeStr = 'std::string';
            } else if (typeof value == 'number') {
              typeStr = 'int64_t';
            } else if (typeof value == 'boolean') {
              typeStr = 'bool';
            } else if (value) {
              const objKey2 = Object.keys(value);
              if ((typeof objKey2 === 'number') && (objKey2 == 0)) { // array
                // Should I examine the element first?
                typeStr = '';
              } else { // object
                typeStr = '';
              }
            }
            result.childList[key] = new JsonMappingData(
                key, typeStr, value, className);
          }
          // if (requireMap[key]) {
          //   result.childList[key].setRequired(requireMap[key]);
          // }
          result.childList[key].setRequired(requireMap[key]);
          if (commentMap[key]) {
            result.childList[key].setComment(commentMap[key], hintMap[key]);
          }
          const tempChild = analyzeJson(value, key, arrayTypeMap[key]);
          if (tempChild) {
            if (result.childList[key].type == '') {
              result.childList[key].setTypeStruct(
                  tempChild.type, tempChild.structType);
              if ((result.childList[key].type.indexOf('JsonObjectVector') >= 0) ||
                (result.childList[key].type.indexOf('JsonValueVector') >= 0)) {
                result.childList[key].isArray = true;
              } else {
                result.childList[key].isObject = true;
                result.childList[key].classComment = tempChild.classComment;
              }
            }
            result.childList[key].childList = tempChild.childList;
            result.childList[key].className = className;
          }
        }
      }
    }
    return result;
  } else {
    console.log('empty value.');
    throw new Error('empty value.');
  }
};

// ----------------------------------------------------------------------------
// analyze child class function
// ----------------------------------------------------------------------------
function getChildClasses(jsonMapData: JsonMappingData,
    list: JsonMappingData[]) {
  if (!jsonMapData) {
    // do nothing
  } else if (jsonMapData.isObject) {
    for (const key in jsonMapData.childList) {
      if (jsonMapData.childList[key]) {
        if (jsonMapData.childList[key].isObject ||
            jsonMapData.childList[key].isArray) {
          getChildClasses(jsonMapData.childList[key], list);
        }
      }
    }
    list.push(jsonMapData);
  } else if (jsonMapData.isArray) {
    getChildClasses(jsonMapData.childList[0], list);
  }
};

// ----------------------------------------------------------------------------
// generate cpp file source function
// ----------------------------------------------------------------------------
function generateFileSource(copyright: string, filename: string,
    headerName: string | string[],
    classList: any[], jsonSetting: JsonObjectCommonType | undefined) {
  const result = [];
  const namespace = (!jsonSetting) ? '' : jsonSetting.namespace;
  const includeNolint = (headerName.indexOf('/') >= 0) ? '' : '  // NOLINT';

  // header
  const sourceFileHeader = `// ${copyright}
/**
 * @file ${filename}
 *
 * @brief JSON mapping file (auto generate)
 */
#include <set>
#include <string>
#include <vector>

#include "${headerName}"${includeNolint}
`;
  result.push(sourceFileHeader);

  if (isArray(namespace)) {
    for (let idx = 0; idx < namespace.length; ++idx) {
      result.push(`namespace ${namespace[idx]} {`);
    }
  } else {
    result.push(`namespace ${namespace} {`);
  }

  const sourceFileHeader2 = `
using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;
// clang-format off
// @formatter:off\
`;
  const sourceFileFooter = `
// @formatter:on
// clang-format on
`;
  result.push(sourceFileHeader2);

  if (classList) {
    for (const data in classList) {
      if (!{}.hasOwnProperty.call(classList, data)) continue;
      result.push(classList[data]);
    }
  }

  result.push(sourceFileFooter);

  if (isArray(namespace)) {
    for (let idx = namespace.length - 1; idx >= 0; --idx) {
      result.push(`}  // namespace ${namespace[idx]}`);
    }
  } else {
    result.push(`}  // namespace ${namespace}`);
  }
  result.push('');

  return result.join('\n');
};

// ----------------------------------------------------------------------------
// generate cpp class source direct function
// ----------------------------------------------------------------------------
function generateClassSourceDirect(mapData: JsonMappingData,
    responseList: string[] | undefined) {
  const result = [];
  const sourceClassHeader = `
// ------------------------------------------------------------------------
// ${mapData.type}
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<${mapData.type}>
  ${mapData.type}::json_mapper;
std::vector<std::string> ${mapData.type}::item_list;

void ${mapData.type}::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<${mapData.type}> func_table;  // NOLINT
`;
  result.push(sourceClassHeader);

  for (const childKey in mapData.childList) {
    if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
    const childData = mapData.childList[childKey];
    // start
    const addJsonMapperComment = `\
  func_table = {
    ${mapData.type}::Get${childData.methodName}String,
    ${mapData.type}::Set${childData.methodName}String,
    ${mapData.type}::Get${childData.methodName}FieldType,
  };
  json_mapper.emplace("${childData.name}", func_table);
  item_list.push_back("${childData.name}");\
`;
    // end
    result.push(addJsonMapperComment);
  }
  result.push('}');

  if (mapData.isOutputStruct) {
    result.push('');
    result.push(`void ${mapData.type}::ConvertFromStruct(`);
    result.push(`    const ${mapData.structType}& data) {`);
    for (const childKey in mapData.childList) {
      if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
      const childData = mapData.childList[childKey];
      if (childData.isObject || childData.isArray) {
        const str = `  ${childData.variableName}_.ConvertFromStruct(data.${childData.variableName});`;
        if (str.length > 80) {
          result.push(`  ${childData.variableName}_.ConvertFromStruct(`);
          result.push(`      data.${childData.variableName});`);
        } else {
          result.push(`  ${childData.variableName}_.ConvertFromStruct(data.${childData.variableName});`);
        }
      } else {
        result.push(`  ${childData.variableName}_ = data.${childData.variableName};`);
      }
    }
    result.push(`  ignore_items = data.ignore_items;`);
    result.push('}');

    result.push('');
    result.push(`${mapData.structType} ${mapData.type}::ConvertToStruct() const {  // NOLINT`);
    result.push(`  ${mapData.structType} result;`);
    for (const childKey in mapData.childList) {
      if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
      const childData = mapData.childList[childKey];
      if (childData.isObject || childData.isArray) {
        const str = `  result.${childData.variableName} = ${childData.variableName}_.ConvertToStruct();`;
        if (str.length > 80) {
          result.push(`  result.${childData.variableName} = ${childData.variableName}_.ConvertToStruct();  // NOLINT`);
        } else {
          result.push(`  result.${childData.variableName} = ${childData.variableName}_.ConvertToStruct();`);
        }
      } else {
        result.push(`  result.${childData.variableName} = ${childData.variableName}_;`);
      }
    }
    result.push(`  result.ignore_items = ignore_items;`);
    result.push('  return result;');
    result.push('}');
  }

  if (responseList) {
    for (const str of result) {
      responseList.push(str);
    }
  }
  return result.join('\n');
}


// ----------------------------------------------------------------------------
// generate cpp class source function
// ----------------------------------------------------------------------------
function generateClassSource(req: JsonMappingData | null | undefined,
    res: JsonMappingData | null | undefined,
    outputList: Set<string>) {
  const result: string[] = [];

  if (req || res) {
    const list: JsonMappingData[] = [];
    if (req) list.push(req);
    if (res) list.push(res);
    for (const data of list) {
      if (!data) continue;
      // sort by class name
      // for child elements
      const mapList: JsonMappingData[] = [];
      getChildClasses(data, mapList);
      debugLog(`mapList = ${mapList}`);

      for (const mapKey in mapList) {
        if (!{}.hasOwnProperty.call(mapList, mapKey)) continue;
        const mapData = mapList[mapKey];
        if (outputList.has(mapData.type)) continue;

        generateClassSourceDirect(mapData, result);

        outputList.add(mapData.type);
      }
    }
  }

  return result.join('\n');
};


// ----------------------------------------------------------------------------
// generate class header function
// ----------------------------------------------------------------------------
function generateClassHeaderData(mapData: JsonMappingData,
    exportDefine: string) {
  const classHeader = `
// ------------------------------------------------------------------------
// ${mapData.type}
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (${mapData.type}) class
 */
class ${exportDefine}${mapData.type}
  : public cfd::core::JsonClassBase<${mapData.type}> {
 public:
  ${mapData.type}() {
    CollectFieldName();
  }
  virtual ~${mapData.type}() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();
`;
  return classHeader;
};


// ----------------------------------------------------------------------------
// generate object function by header
// ----------------------------------------------------------------------------
function generateObjectFunctionByHeader(mapData: JsonMappingData,
    childData: JsonMappingData) {
  // Rename method name because equals windows macro's function.
  const methodName = (childData.methodName === 'KValue') ?
      'K_Value' : childData.methodName;

  const objectFunctions = `\
  /**
   * @brief Get of ${childData.name}.
   * @return ${childData.name}
   */
  ${childData.type}& Get${methodName}() {  // NOLINT
    return ${childData.variableName}_;
  }
  /**
   * @brief Set to ${childData.name}.
   * @param[in] ${childData.variableName}    setting value.
   */
  void Set${methodName}(  // line separate
      const ${childData.type}& ${childData.variableName}) {  // NOLINT
    this->${childData.variableName}_ = ${childData.variableName};
  }
  /**
   * @brief Get data type of ${childData.name}.
   * @return Data type of ${childData.name}.
   */
  static std::string Get${childData.methodName}FieldType() {
    return "${childData.type}";  // NOLINT
  }
  /**
   * @brief Get json string of ${childData.name} field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string Get${childData.methodName}String(  // line separate
      const ${mapData.type}& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.${childData.variableName}_.Serialize();
  }
  /**
   * @brief Set json object to ${childData.name} field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void Set${childData.methodName}String(  // line separate
      ${mapData.type}& obj,  // NOLINT
      const UniValue& json_value) {
    obj.${childData.variableName}_.DeserializeUniValue(json_value);
  }
`;
  return objectFunctions;
};

// ----------------------------------------------------------------------------
// generate value function by header
// ----------------------------------------------------------------------------
function generateValueFunctionByHeader(mapData: JsonMappingData,
    childData: JsonMappingData) {
  // Rename method name because equals windows macro's function.
  const methodName = (childData.methodName === 'KValue') ?
      'K_Value' : childData.methodName;

  const valueFunctions = `\
  /**
   * @brief Get of ${childData.name}
   * @return ${childData.name}
   */
  ${childData.type} Get${methodName}() const {
    return ${childData.variableName}_;
  }
  /**
   * @brief Set to ${childData.name}
   * @param[in] ${childData.variableName}    setting value.
   */
  void Set${methodName}(  // line separate
    const ${childData.type}& ${childData.variableName}) {  // NOLINT
    this->${childData.variableName}_ = ${childData.variableName};
  }
  /**
   * @brief Get data type of ${childData.name}
   * @return Data type of ${childData.name}
   */
  static std::string Get${childData.methodName}FieldType() {
    return "${childData.type}";
  }
  /**
   * @brief Get json string of ${childData.name} field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string Get${childData.methodName}String(  // line separate
      const ${mapData.type}& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.${childData.variableName}_);
  }
  /**
   * @brief Set json object to ${childData.name} field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void Set${childData.methodName}String(  // line separate
      ${mapData.type}& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.${childData.variableName}_, json_value);
  }
`;
  return valueFunctions;
};

// ----------------------------------------------------------------------------
// generate class field by header
// ----------------------------------------------------------------------------
function generateClassFieldByHeader(mapData: JsonMappingData) {
  let structConvertFunction = '';
  if (mapData.isOutputStruct) {
    structConvertFunction = `\
  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const ${mapData.structType}& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  ${mapData.structType} ConvertToStruct()  const;`;
  }

  const commonFields = `\
  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

${structConvertFunction}

 protected:
  /**
   * @brief definition type of Map table.
   */
  using ${mapData.type}MapTable =
    cfd::core::JsonTableMap<${mapData.type}>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ${mapData.type}MapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static ${mapData.type}MapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;
`;
  return commonFields;
};

// ----------------------------------------------------------------------------
// generate header function
// ----------------------------------------------------------------------------
function generateFileHeader(copyright: string, filename: string,
    dirname: string, classList: any[],
    jsonSetting: JsonObjectCommonType | undefined, appendHeaderName = '') {
  const result = [];

  const namespace = (!jsonSetting) ? '' : jsonSetting.namespace;
  const commonHeader = (!jsonSetting) ? '' : jsonSetting.commonHeader;
  let path = `${dirname}/${filename}_`;
  if (path.startsWith(__dirname)) {
    path = path.substr(__dirname.length);
  }
  while (path.indexOf('/', 0) == 0) {
    path = path.substr(1);
  }
  while (path.indexOf('../') >= 0) {
    path = path.replace('../', '');
  }
  while (path.indexOf('./') >= 0) {
    path = path.replace('./', '');
  }
  while (path.indexOf('//') >= 0) {
    path = path.replace('//', '/');
  }
  while (path.indexOf('external/') >= 0) {
    path = path.replace('external/', '');
  }
  while (path.indexOf('/') >= 0) {
    path = path.replace('/', '_');
  }
  while (path.indexOf('.') >= 0) {
    path = path.replace('.', '_');
  }
  while (path.indexOf('-') >= 0) {
    path = path.replace('-', '_');
  }
  const defName = path.toUpperCase();
  const includeHeader = (commonHeader) ? `#include "${commonHeader}"\n` : '';
  const includeHeader2 = (appendHeaderName.length > 0) ? `#include "${appendHeaderName}"\n` : '';

  // header
  const headerFileHeader = `// ${copyright}
/**
 * @file ${filename}
 *
 * @brief JSON mapping file. (auto generate)
 */
#ifndef ${defName}
#define ${defName}

#include <set>
#include <string>
#include <vector>

#include "cfdcore/cfdcore_json_mapping_base.h"
${includeHeader}
${includeHeader2}`;

  result.push(headerFileHeader);

  if (typeof namespace !== 'string') {
    for (let idx = 0; idx < namespace.length; ++idx) {
      result.push(`namespace ${namespace[idx]} {`);
    }
  } else {
    result.push(`namespace ${namespace} {`);
  }

  const headerFileHeader2 = `
using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;
// clang-format off
// @formatter:off\
`;

  const headerFileFooter = `
// @formatter:on
// clang-format on
`;
  const headerFileFooter2 = `
#endif  // ${defName}
`;
  result.push(headerFileHeader2);

  if (classList) {
    for (const data in classList) {
      if (!{}.hasOwnProperty.call(classList, data)) continue;
      result.push(classList[data]);
    }
  }

  result.push(headerFileFooter);
  if (typeof namespace !== 'string') {
    for (let idx = namespace.length - 1; idx >= 0; --idx) {
      result.push(`}  // namespace ${namespace[idx]}`);
    }
  } else {
    result.push(`}  // namespace ${namespace}`);
  }
  result.push(headerFileFooter2);
  return result.join('\n');
};

// ----------------------------------------------------------------------------
// generate class header direct function
// ----------------------------------------------------------------------------
function generateClassHeaderDirect(
    mapData: JsonMappingData,
    jsonSetting: { export: any },
    responseList: string[] | undefined) {
  const result = [];
  const exportDefine = (jsonSetting && jsonSetting.export) ? `${jsonSetting.export} ` : '';
  const classHeader = generateClassHeaderData(mapData, exportDefine);
  result.push(classHeader);

  for (const childKey in mapData.childList) {
    if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
    const childData = mapData.childList[childKey];
    if (childData.isObject || childData.isArray) {
      const objectFunctions = generateObjectFunctionByHeader(
          mapData, childData);
      result.push(`${objectFunctions}`);
    } else {
      const valueFunctions = generateValueFunctionByHeader(
          mapData, childData);
      result.push(valueFunctions);
    }
  }
  const commonFields = generateClassFieldByHeader(mapData);
  result.push(commonFields);

  for (const childKey in mapData.childList) {
    if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
    const childData = mapData.childList[childKey];
    const objectFields = `\
  /**
   * @brief JsonAPI(${childData.name}) value
   */`;
    result.push(objectFields);
    if (childData.isObject || childData.isArray) {
      result.push(`  ${childData.type} ${childData.variableName}_;  // NOLINT`);
    } else if (childData.type == 'std::string') {
      // string
      result.push(`  ${childData.type} ${childData.variableName}_ = "${childData.initValue}";`);
    } else {
      result.push(`  ${childData.type} ${childData.variableName}_ = ${childData.initValue};`);
    }
  }

  result.push('};');
  if (responseList) {
    for (const str of result) {
      responseList.push(str);
    }
  }
  return result.join('\n');
}

// ----------------------------------------------------------------------------
// generate class header function
// ----------------------------------------------------------------------------
function generateClassHeader(req: JsonMappingData | null | undefined,
    res: JsonMappingData | null | undefined,
    jsonSetting: { export: any },
    outputList: Set<string>) {
  const result: string[] = [];

  // header
  if (req || res) {
    const list: JsonMappingData[] = [];
    if (req) list.push(req);
    if (res) list.push(res);
    for (const data of list) {
      if (!data) continue;
      // sort by generate class
      // Child element in order
      const mapList: JsonMappingData[] = [];
      getChildClasses(data, mapList);
      debugLog(`mapList = ${mapList}`);

      for (const mapKey in mapList) {
        if (!{}.hasOwnProperty.call(mapList, mapKey)) continue;
        const mapData = mapList[mapKey];
        if (outputList.has(mapData.type)) continue;

        generateClassHeaderDirect(mapData, jsonSetting, result);

        outputList.add(mapData.type);
      }
    }
  }

  return result.join('\n');
};

// ----------------------------------------------------------------------------
// generate reference class list function
// ----------------------------------------------------------------------------
function generateReferenceClassList(
    jsonClassMap: ClassMapType,
    rootFuncList: TsAppendFunctionData[],
    referenceSet: Set<string>) {
  const refList: Map<string, ReferenceClassInfo> = new Map();
  const list: ReferenceClassInfo[] = [];
  for (const key in jsonClassMap) {
    if (jsonClassMap[key]) {
      const data = jsonClassMap[key];
      if (data.data.isObject) {
        for (const cKey of data.parentList) {
          if (!cKey) {
            // do nothing
          } else if (jsonClassMap[cKey]) {
            if (refList.has(key)) {
              // add ref list
              const obj = refList.get(key);
              if (obj) {
                obj.references.add(cKey);
                refList.set(key, obj);
              }
            } else {
              const obj: ReferenceClassInfo = {
                name: key,
                references: new Set(),
                weight: 1,
              };
              obj.references.add(cKey);
              refList.set(key, obj);
              referenceSet.add(key);
            }
          } else if (cKey == 'ErrorResponseBase') {
            // do nothing
          } else {
            console.log(`unknown key: ${cKey}`);
          }
        }
      }
    }
  }

  /*
  for (const func of rootFuncList) {
    if (!func) continue;
    if (func.parameters.length > 0 &&
      refList.has(func.parameters[0].type)) {
      const obj = refList.get(func.parameters[0].type);
      if (obj && obj.references.keys.length > 1) {
        obj.weight += 1;
        refList.set(func.parameters[0].type, obj);
      }
    }
    if (func.returnType && refList.has(func.returnType)) {
      const obj = refList.get(func.returnType);
      if (obj && obj.references.keys.length > 1) {
        obj.weight += 1;
        refList.set(func.returnType, obj);
      }
    }
  }
  */

  let changeWeight = true;
  let refKeyList: string[] = [];
  while (changeWeight) {
    changeWeight = false;
    const newRefKeyList = [];
    if (refKeyList.length == 0) {
      for (const [key] of refList) {
        if (key) refKeyList.push(key);
      }
    }
    for (const key of refKeyList) {
      if (refList.get(key)) {
        const src = refList.get(key);
        let targetCount = 0;
        if (src) {
          for (const ref of src.references) {
            if (key == ref) continue;
            if (refList.get(ref)) {
              const dst = refList.get(ref);
              if (dst && (dst.references.size > 1) &&
                  dst.weight >= src.weight) {
                src.weight = dst.weight + 1;
                changeWeight = true;
                targetCount += 1;
                console.log(`update weight: ${key} weight=${src.weight}`);
              }
            }
          }
          if (targetCount > 0) {
            refList.set(key, src);
            newRefKeyList.push(key);
          }
        }
      }
    }
    refKeyList = newRefKeyList;
  }

  for (const [key, value] of refList) {
    if (value) {
      if ((value.references.size > 1) || (value.weight > 1)) {
        list.push(value);
        console.log('multiple reference type:', key);
      }
    }
  }

  list.sort((a, b) => {
    if (a.weight == b.weight) {
      return a.name.localeCompare(b.name);
    }
    return (a.weight > b.weight) ? -1 : 1;
  });

  // console.log(list);
  return list;
};


// ----------------------------------------------------------------------------
// generate struct header function
// ----------------------------------------------------------------------------
function generateStructHeaderArea(mapData: { structType: any }) {
  const structHeader = `
// ------------------------------------------------------------------------
// ${mapData.structType}
// ------------------------------------------------------------------------
/**
 * @brief ${mapData.structType} struct
 */
struct ${mapData.structType} {`;
  return structHeader;
}


// ----------------------------------------------------------------------------
// generate struct item data function
// ----------------------------------------------------------------------------
function generateStructItemDataDirect(textArray: string[],
    mapData: JsonMappingData, hasErrorOutput: boolean,
    namespace: string, libNamespace: string,
    responseTypeSet: Set<string>) {
  const structHeader = generateStructHeaderArea(mapData);
  textArray.push(structHeader);

  let nameLengthMax = 0;
  for (const childKey in mapData.childList) {
    if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
    const childData = mapData.childList[childKey];
    let nameLength = childData.type.length +
      childData.variableName.length;
    if (childData.isObject || childData.isArray) {
      nameLength = childData.structType.length +
        childData.variableName.length;
    } else if (childData.type == 'std::string') {
      if (typeof childData.initValue === 'string') {
        nameLength += childData.initValue.length + 5;
      }
    } else {
      const stringText = `${childData.initValue}`;
      nameLength += stringText.length + 3;
    }
    if (nameLengthMax < nameLength) nameLengthMax = nameLength;
  }

  for (const childKey in mapData.childList) {
    if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
    const childData = mapData.childList[childKey];
    let nameLength = childData.type.length +
      childData.variableName.length;
    if (childData.isObject || childData.isArray) {
      nameLength = childData.structType.length +
        childData.variableName.length;
    } else if (childData.type == 'std::string') {
      if (typeof childData.initValue === 'string') {
        nameLength += childData.initValue.length + 5;
      }
    } else {
      const stringText = `${childData.initValue}`;
      nameLength += stringText.length + 3;
    }
    let space = '';
    if (nameLengthMax > nameLength) {
      nameLength = nameLengthMax - nameLength;
      for (let i = 0; i < nameLength; ++i) space += ' ';
    }
    const comment = `${space}//!< ${childData.variableName}  // NOLINT`;

    if (childData.isObject || childData.isArray) {
      textArray.push(`  ${childData.structType} ${childData.variableName};  ${comment}`);
    } else if (childData.type == 'std::string') {
      // string
      textArray.push(`  ${childData.type} ${childData.variableName} = "${childData.initValue}";  ${comment}`);
    } else {
      textArray.push(`  ${childData.type} ${childData.variableName} = ${childData.initValue};  ${comment}`);
    }
  }

  if (hasErrorOutput && responseTypeSet.has(mapData.type)) {
    if (namespace == libNamespace) {
      textArray.push(`  InnerErrorResponseStruct error;       //!< error information`);
    } else {
      textArray.push(`  ${libNamespace}::InnerErrorResponseStruct error;   //!< error information`);
    }
  }
  textArray.push(`  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.`);
  textArray.push('};');
}


// ----------------------------------------------------------------------------
// generate struct item data function
// ----------------------------------------------------------------------------
function generateStructItemData(textArray: string[],
    req: JsonMappingData | null | undefined,
    res: JsonMappingData | null | undefined,
    inputJsonData: { namespace: string | string[] },
    lastNamespaces: string | any[], hasErrorOutput: boolean,
    processedList: Set<string>, libNamespace: string,
    responseTypeSet: Set<string>) {
  if (req || res) {
    let namespace = '';
    let lastNamespace = '';
    if (typeof inputJsonData.namespace === 'string') {
      namespace = inputJsonData.namespace;
    } else {
      for (let idx = 0; idx < inputJsonData.namespace.length; ++idx) {
        if (namespace.length > 0) {
          namespace += '::' + inputJsonData.namespace[idx];
        } else {
          namespace = inputJsonData.namespace[idx];
        }
      }
    }
    if (typeof lastNamespaces === 'string') {
      lastNamespace = lastNamespaces;
    } else {
      for (let idx = 0; idx < lastNamespaces.length; ++idx) {
        if (lastNamespace.length > 0) {
          lastNamespace += '::' + lastNamespaces[idx];
        } else {
          lastNamespace = lastNamespaces[idx];
        }
      }
    }

    if (namespace != lastNamespace) {
      if (lastNamespace.length > 0) {
        textArray.push('');
        if (typeof lastNamespaces !== 'string') {
          for (let idx = lastNamespaces.length - 1; idx >= 0; --idx) {
            if (lastNamespaces[idx] != 'json') {
              textArray.push(`}  // namespace ${lastNamespaces[idx]}`);
            }
          }
        } else {
          textArray.push(`}  // namespace ${lastNamespace}`);
        }
        textArray.push('');
      }

      if (typeof inputJsonData.namespace !== 'string') {
        for (let idx = 0; idx < inputJsonData.namespace.length; ++idx) {
          if (inputJsonData.namespace[idx] != 'json') {
            textArray.push(`namespace ${inputJsonData.namespace[idx]} {`);
          }
        }
      } else {
        textArray.push(`namespace ${namespace} {`);
      }
    }

    const list: JsonMappingData[] = [];
    if (req) list.push(req);
    if (res) list.push(res);
    for (const data in list) {
      if (!data) continue;
      const mapList: JsonMappingData[] = [];
      getChildClasses(list[data], mapList);

      for (const mapKey in mapList) {
        if (!{}.hasOwnProperty.call(mapList, mapKey)) continue;
        const mapData = mapList[mapKey];
        if (!mapData.isOutputStruct) {
          console.log(`skip output struct: ${mapData.structType}`);
          continue;
        }
        if (processedList.has(mapData.structType)) {
          continue;
        }
        generateStructItemDataDirect(textArray,
            mapData, hasErrorOutput, namespace, libNamespace,
            responseTypeSet);

        processedList.add(mapData.structType);
      }
    }
  }
}

// ----------------------------------------------------------------------------
// generate struct header function
// ----------------------------------------------------------------------------
function generateStructHeader(copyright: string, dirname: string,
    filename: string, jsonList: any[], libNamespace: string,
    referenceList: ReferenceClassInfo[], jsonClassMap: ClassMapType,
    responseTypeSet: Set<string>) {
  const result = [];
  const processedStructTypes: Set<string> = new Set();

  let path = `${dirname}/${filename}_`;
  if (path.startsWith(__dirname)) {
    path = path.substr(__dirname.length);
  }
  while (path.indexOf('/', 0) == 0) {
    path = path.substr(1);
  }
  while (path.indexOf('../') >= 0) {
    path = path.replace('../', '');
  }
  while (path.indexOf('./') >= 0) {
    path = path.replace('./', '');
  }
  while (path.indexOf('//') >= 0) {
    path = path.replace('//', '/');
  }
  while (path.indexOf('external/') >= 0) {
    path = path.replace('external/', '');
  }
  while (path.indexOf('/') >= 0) {
    path = path.replace('/', '_');
  }
  while (path.indexOf('.') >= 0) {
    path = path.replace('.', '_');
  }
  while (path.indexOf('-') >= 0) {
    path = path.replace('-', '_');
  }
  const defName = path.toUpperCase();

  // header
  const headerFileHeader = `// ${copyright}
/**
 * @file ${filename}
 *
 * @brief Struct mapping file. (auto generate)
 */
#ifndef ${defName}
#define ${defName}

#include <cstdint>
#include <set>
#include <string>
#include <vector>

// clang-format off
// @formatter:off\
`;
  const headerFileFooter = `
// @formatter:on
// clang-format on

#endif  // ${defName}
`;
  result.push(headerFileHeader);

  let lastNamespace = '';
  for (const jsonDataIndex in jsonList) {
    if (!{}.hasOwnProperty.call(jsonList, jsonDataIndex)) continue;
    if (('priority' in jsonList[jsonDataIndex].inputJsonData) &&
      (jsonList[jsonDataIndex].inputJsonData['priority'] == 'high')) {
      const req = jsonList[jsonDataIndex].requestData;
      const res = jsonList[jsonDataIndex].responseData;
      generateStructItemData(result, req, res,
          jsonList[jsonDataIndex].inputJsonData, lastNamespace, false,
          processedStructTypes, libNamespace, responseTypeSet);
      lastNamespace = jsonList[jsonDataIndex].inputJsonData.namespace;
    }
  }

  // multiple reference target list
  for (const refData of referenceList) {
    if (refData && jsonClassMap[refData.name]) {
      generateStructItemDataDirect(result,
          jsonClassMap[refData.name].data, true,
          lastNamespace, libNamespace, responseTypeSet);
      processedStructTypes.add(jsonClassMap[refData.name].data.structType);
    }
  }

  for (const jsonDataIndex in jsonList) {
    if (!{}.hasOwnProperty.call(jsonList, jsonDataIndex)) continue;
    if (('priority' in jsonList[jsonDataIndex].inputJsonData) &&
      (jsonList[jsonDataIndex].inputJsonData['priority'] == 'high')) {
      // do nothing
    } else {
      const req = jsonList[jsonDataIndex].requestData;
      const res = jsonList[jsonDataIndex].responseData;
      generateStructItemData(result, req, res,
          jsonList[jsonDataIndex].inputJsonData, lastNamespace, true,
          processedStructTypes, libNamespace, responseTypeSet);
      // const inputJsonData = jsonList[jsonDataIndex].inputJsonData;
      lastNamespace = jsonList[jsonDataIndex].inputJsonData.namespace;
    }
  }
  result.push('');
  if (isArray(lastNamespace)) {
    for (let idx = lastNamespace.length - 1; idx >= 0; --idx) {
      if (lastNamespace[idx] != 'json') {
        result.push(`}  // namespace ${lastNamespace[idx]}`);
      }
    }
  } else {
    result.push(`}  // namespace ${lastNamespace}`);
  }

  result.push(headerFileFooter);
  return result.join('\n');
};


// ----------------------------------------------------------------------------
// generate typescript data file function
// ----------------------------------------------------------------------------
function generateTsData(dirname: string, filename: string,
    jsonClassMap: ClassMapType, jsonTypeList: ClassParameterType[],
    functionList: TsAppendFunctionData[], loadCfdjsIndexFile: fs.PathLike,
    promiseMode: boolean, tsClassName: string,
    insertFunctions: TsAppendFunctionData[],
    errorClassName: string,
    insertErrorFunctions: TsAppendFunctionData[]) {
  let outPath = `${dirname}/${filename}`;
  if (outPath.startsWith(__dirname)) {
    outPath = outPath.substr(__dirname.length);
  }
  while (outPath.indexOf('/', 0) == 0) {
    outPath = outPath.substr(1);
  }
  while (outPath.indexOf('//') >= 0) {
    outPath = outPath.replace('//', '/');
  }
  const classCommentMap: {[key: string]: string} = {};
  for (const typeData of jsonTypeList) {
    classCommentMap[typeData.name] = typeData.comment;
  }
  jsonTypeList.sort((a, b) => a.name.localeCompare(b.name));
  functionList.sort((a, b) => a.name.localeCompare(b.name));

  // initialize
  const project = new Project({
    tsConfigFilePath: `${__dirname}/../tsconfig.json`,
    addFilesFromTsConfig: false,
  });

  if (loadCfdjsIndexFile) {
    fs.copyFileSync(loadCfdjsIndexFile, outPath);
  }

  // add source files
  const file = (!loadCfdjsIndexFile) ? project.createSourceFile(outPath, '\n') :
      project.addSourceFileAtPath(outPath);

  if (loadCfdjsIndexFile) {
    const internalErrorObj = file.getInterface('InnerErrorResponse');
    if (internalErrorObj !== undefined) {
      internalErrorObj.remove();
    }
    const errorObj = file.getInterface('ErrorResponse');
    if (errorObj !== undefined) {
      errorObj.remove();
    }
  } else {
    file.insertStatements(0, '/* eslint-disable max-len */');
    file.insertStatements(1, '/* eslint-disable indent */');
  }

  for (let i = 0; i < jsonTypeList.length; ++i) {
    const clsName = jsonTypeList[i].name;
    const comment = jsonTypeList[i].comment || classCommentMap[clsName];
    const props: DetailParameterType[] = jsonClassMap[clsName].childList;
    const properties = [];
    const tags = [];
    const docs = [];
    for (const prop of props) {
      if (prop && prop.param.comment) {
        const type = prop.param.type;
        const name = prop.param.name;
        tags.push({tagName: 'property', text: `\{${type}\} ${name} - ${prop.param.comment}`});
      }
      properties.push(prop.param);
    }
    debugLog(`${clsName} = `, props);
    if ((tags.length > 0) || comment) {
      docs.push({
        description: comment,
        tags,
      });
    }
    file.addInterface({
      name: clsName,
      isExported: true,
      properties,
      docs,
    });
  }

  let classObj = undefined;
  if (tsClassName !== '') {
    classObj = file.addClass({
      name: tsClassName,
      isExported: true,
      docs: [{
        description: 'function definition class.',
      }],
    });
  }

  for (let i = 0; i < functionList.length; ++i) {
    // manipulate
    const funcName = functionList[i].name;
    const funcComment = functionList[i].comment || '';
    const params = functionList[i].parameters;
    const reqType = (params.length > 0) ? params[0].type : '';
    const reqName = (params.length > 0) ? params[0].name : '';
    const resName = functionList[i].returnType;
    const resDataName = (promiseMode) ? `Promise<${resName}>` : resName;
    const retType = (resName in jsonClassMap) ? resDataName : undefined;
    const inputDoc = {tagName: 'param', text: `\{${reqType}\} ${reqName} - request data.`};
    const returnDoc = {tagName: 'return', text: `\{${retType}\} - response data.`};
    const tags = [];
    const docs = [];
    if (params.length > 0) tags.push(inputDoc);
    if (resName in jsonClassMap) tags.push(returnDoc);
    if ((tags.length > 0) || funcComment) {
      docs.push({
        description: funcComment,
        tags,
      });
    }
    if (classObj === undefined) {
      file.addFunction({
        name: funcName,
        isExported: true,
        parameters: params,
        returnType: retType,
        docs,
      });
    } else {
      classObj.addMethod({
        name: funcName,
        parameters: params,
        returnType: retType,
        docs,
      });
    }
  }

  for (let i = 0; i < insertFunctions.length; ++i) {
    const funcName = insertFunctions[i].name;
    const params = insertFunctions[i].parameters;
    const retType = insertFunctions[i].returnType;
    const comment = insertFunctions[i].comment;
    const tags = [];
    const docs = [];
    for (const prop of params) {
      if (prop && prop.comment) {
        const type = prop.type;
        const name = prop.name;
        tags.push({tagName: 'param', text: `\{${type}\} ${name} - ${prop.comment}`});
      }
    }
    if (retType && retType != 'void') {
      tags.push({tagName: 'return', text: `\{${retType}\} - ${retType} data.`});
    }
    if ((tags.length > 0) || comment) {
      docs.push({
        description: comment,
        tags,
      });
    }
    file.addFunction({
      name: funcName,
      isExported: true,
      parameters: params,
      returnType: retType,
      docs,
    });
  }

  if (errorClassName) {
    const errorClassObj = file.addClass({
      name: errorClassName,
      isExported: true,
      docs: [{
        description: 'error class.',
      }],
    });
    errorClassObj.setExtends('Error');
    for (let i = 0; i < insertErrorFunctions.length; ++i) {
      const funcName = insertErrorFunctions[i].name;
      const params = insertErrorFunctions[i].parameters;
      const retType = insertErrorFunctions[i].returnType;
      const comment = insertErrorFunctions[i].comment;
      const tags = [];
      const docs = [];
      for (const prop of params) {
        if (prop) {
          const type = prop.type;
          const name = prop.name;
          tags.push({tagName: 'param', text: `\{${type}\} ${name} - ${prop.comment}`});
        }
      }
      if (funcName == 'constructor') {
        if ((tags.length > 0) || comment) {
          docs.push({
            description: 'constructor.',
            tags,
          });
        }
        errorClassObj.addConstructor({
          parameters: params,
          returnType: retType,
          docs,
        });
      } else {
        if (retType) {
          tags.push({tagName: 'return', text: `\{${retType}\} - ${retType} data.`});
        }
        if ((tags.length > 0) || comment) {
          docs.push({
            description: comment,
            tags,
          });
        }
        errorClassObj.addMethod({
          name: funcName,
          parameters: params,
          returnType: retType,
          docs,
        });
      }
    }
  }

  // asynchronously save all the changes above
  project.save().then(() => console.log(`output: ${outPath}`));
};


// ----------------------------------------------------------------------------
// search file
// ----------------------------------------------------------------------------
function convertFile() {
  // const today = new Date();
  // const year = today.getFullYear();
  const year = 2020;
  const copyright = `Copyright ${year} CryptoGarage`;

  // const fileList = [];
  let cfdBaseDir: string;
  const libraryName = 'cfd-dlc-js';
  const libPrefix = 'cfddlcjs';
  const libNamespace = 'cfd::dlc::js::api';
  const errorClassName = 'CfdDlcError';
  const cfdPath = `${__dirname}/../external/${libraryName}/`;
  const cfdPath2 = `${__dirname}/../../${libraryName}/`;
  let folderPath = `src/input_json_format/`;
  const outJsonSourceFolderPath = `${__dirname}/../../${libraryName}/src/autogen/`;
  const outJsonHeaderFolderPath = `${__dirname}/../../${libraryName}/src/autogen/`;
  let outStructDirPath = `include/${libPrefix}/`;
  const loadCfdjsIndexFile = '';
  let outTsFolderPath = ``;
  const outStructFileName = `${libPrefix}_struct.h`;
  const outTsFileName = `index.d.ts`;
  const promiseMode = false;
  const tsClassName = '';
  const classHeaderList: string[] = [];
  const classSourceList: string[] = [];
  const jsonDataList: JsonData[] = [];
  const jsonClassMap: ClassMapType = {};
  const jsonTypeList: ClassParameterType[] = [];
  const functionList: TsAppendFunctionData[] = [];
  const responseTypeSet: Set<string> = new Set();
  const insertFunctions: TsAppendFunctionData[] = [];
  const insertErrorFunctions: TsAppendFunctionData[] = [{
    name: 'constructor',
    parameters: [{
      name: 'message',
      type: 'string',
      comment: 'Error message.',
    }, {
      name: 'errorInformation',
      type: 'InnerErrorResponse',
      comment: 'Error information data.',
    }, {
      name: 'cause',
      type: 'Error',
      comment: 'Cause of the error.',
    }],
    returnType: 'void',
    comment: 'constructor.',
  }, {
    name: 'toString',
    parameters: [],
    returnType: 'string',
    comment: 'get error string.',
  }, {
    name: 'getErrorInformation',
    parameters: [],
    returnType: 'InnerErrorResponse',
    comment: 'get error information.',
  }, {
    name: 'getCause',
    parameters: [],
    returnType: 'Error',
    comment: 'get error cause.',
  }];

  if (fs.existsSync(cfdPath) && fs.statSync(cfdPath).isDirectory()) {
    cfdBaseDir = cfdPath;
    outTsFolderPath = cfdPath + outTsFolderPath;
    folderPath = cfdPath + folderPath;
    outStructDirPath = cfdPath + outStructDirPath;
  } else {
    cfdBaseDir = cfdPath2;
    outTsFolderPath = `${__dirname}/`; // relative path from tsconfig.json
    folderPath = cfdPath2 + folderPath;
    outStructDirPath = cfdPath2 + outStructDirPath;
  }

  let jsonObjectCommon: JsonObjectCommonType | undefined = undefined;
  fs.readdir(folderPath, (err, files) => {
    if (err) throw err;
    files.filter(function(file) {
      // filter
      return fs.statSync(`${folderPath}${file}`).isFile() && /.*\.json$/.test(file);
    }).forEach(function(file) {
      console.log(`file = ${file}`);
      const inFile = `${folderPath}${file}`;
      // const outFile = file.replace(/\.json$/i, '_json');
      // const outHeaderFile = `${outFile}.h`;
      // const outSourceFile = `${outFile}.cpp`;

      // read json
      const jsonObject = JSON.parse(fs.readFileSync(inFile, 'utf8'));
      const reqData = (jsonObject.request) ? analyzeJson(jsonObject.request, 'root') : null;
      const resData = (jsonObject.response) ? analyzeJson(jsonObject.response, 'root') : null;
      let funcName = (jsonObject.functionName) ? jsonObject.functionName : '';
      let reqType = '';
      let resType = '';
      if (reqData != null) {
        reqData.collectMapData(jsonClassMap, jsonTypeList, true, reqData);
        if (funcName == '') funcName = reqData.getFunctionName();
        reqType = reqData.type;
      }
      if (resData != null) {
        resData.collectMapData(jsonClassMap, jsonTypeList, false, resData);
        resType = resData.type;
        responseTypeSet.add(resData.type);
        if (funcName == '') funcName = resData.getFunctionName();
      }
      if (funcName != '') {
        const comm = jsonObject.comment || '';
        const param = [];
        if (reqType) {
          param.push({
            name: 'jsonObject',
            type: reqType,
            comment: '',
          });
        }
        functionList.push({
          name: funcName,
          comment: comm,
          returnType: resType,
          parameters: param,
        });
      }
      debugLog(`reqData = ${reqData}`);
      debugLog(`resData = ${resData}`);
      jsonDataList.push(new JsonData(file, jsonObject, reqData, resData));

      if (jsonObjectCommon === undefined) {
        jsonObjectCommon = jsonObject;
      } else {
        if (jsonObject.namespace && jsonObject.namespace.length > 0) {
          jsonObjectCommon['namespace'] = jsonObject.namespace;
        }
        if (jsonObject.commonHeader && jsonObject.commonHeader.length > 0) {
          jsonObjectCommon['commonHeader'] = jsonObject.commonHeader;
        }
      }
    });

    const referenceSet: Set<string> = new Set();
    const referenceList = generateReferenceClassList(
        jsonClassMap, functionList, referenceSet);
    if (jsonDataList.length > 0) {
      jsonDataList.sort((a, b) => a.filename.localeCompare(b.filename));
      const classHeaderSet: Set<string> = new Set();
      const classSourceSet: Set<string> = new Set();
      const dummyJson = {export: ''};
      for (const refData of referenceList) {
        if (jsonClassMap[refData.name]) {
          const headerStr = generateClassHeaderDirect(
              jsonClassMap[refData.name].data, dummyJson, undefined);
          classHeaderList.push(headerStr);
          const srcStr = generateClassSourceDirect(
              jsonClassMap[refData.name].data, undefined);
          classSourceList.push(srcStr);
          classHeaderSet.add(refData.name);
          classSourceSet.add(refData.name);
        }
      }
      for (const data of jsonDataList) {
        const headerStr = generateClassHeader(
            data.requestData, data.responseData, data.inputJsonData,
            classHeaderSet);
        classHeaderList.push(headerStr);
        const srcStr = generateClassSource(
            data.requestData, data.responseData, classSourceSet);
        classSourceList.push(srcStr);
      }
    }

    {
      let namespaceName = '';
      const namespace = (jsonObjectCommon) ? jsonObjectCommon.namespace : '';
      if (typeof namespace !== 'string') {
        for (let idx = 0; idx < namespace.length; ++idx) {
          if (idx !== 0) namespaceName += '_';
          namespaceName += namespace[idx];
        }
      } else {
        namespaceName += namespace;
      }

      if (outStructFileName !== '') {
        const outHeaderFile = `${namespaceName}_autogen.h`;
        const outSourceFile = `${namespaceName}_autogen.cpp`;
        const headerStr = generateFileHeader(copyright, outHeaderFile,
            outJsonHeaderFolderPath,
            classHeaderList, jsonObjectCommon, `${libPrefix}/${outStructFileName}`);
        fs.writeFileSync(`${outJsonHeaderFolderPath}${outHeaderFile}`, headerStr);
        const srcStr = generateFileSource(copyright, outSourceFile,
            outHeaderFile, classSourceList, jsonObjectCommon);
        fs.writeFileSync(`${outJsonSourceFolderPath}${outSourceFile}`, srcStr);
      }
    };

    if ((jsonDataList.length > 0) && (outStructFileName !== '')) {
      const headerStr = generateStructHeader(copyright, outStructDirPath,
          outStructFileName, jsonDataList, libNamespace,
          referenceList, jsonClassMap, responseTypeSet);
      fs.writeFileSync(path.resolve(`${outStructDirPath}${outStructFileName}`), headerStr);
      console.log(`output: ${outStructFileName}`);
    }

    if (jsonTypeList.length > 0) {
      try {
        fs.unlinkSync(path.resolve(`${cfdBaseDir}${outTsFileName}`));
      } catch (err) {
        // do nothing
      }
      generateTsData(outTsFolderPath, outTsFileName, jsonClassMap,
          jsonTypeList, functionList, loadCfdjsIndexFile, promiseMode,
          tsClassName, insertFunctions, errorClassName, insertErrorFunctions);
    }
  });
};


const main = function() {
  for (let i = 2; i < process.argv.length; i++) {
    if (process.argv[i]) {
      if (process.argv[i] === 'mode=debug') {
        debugLog = function(...args: any | any[]) {
          if (!isArray(args)) {
            console.log(args);
            return;
          }
          switch (args.length) {
            case 1:
              console.log(args[0]);
              break;
            case 2:
              console.log(args[0], args[1]);
              break;
            case 3:
              console.log(args[0], args[1], args[2]);
              break;
            default:
              console.log(Array.prototype.join.call(args));
              break;
          }
        };
      }
    }
  }

  convertFile();
};
main();
