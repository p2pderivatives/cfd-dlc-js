cmake_minimum_required(VERSION 3.13)

# configure.ac: AC_INIT([cfd-dlc-js], [1.0]
set(PACKAGE_VERSION   0.0.1)

####################
# options
####################
if(CMAKE_JS_INC)
option(ENABLE_SHARED "enable shared library (ON or OFF. default:ON)" ON)
else()
option(ENABLE_SHARED "enable shared library (ON or OFF. default:OFF)" OFF)
endif()
# use "cmake -DCMAKE_BUILD_TYPE=Debug" or "cmake-js -D"
# option(ENABLE_DEBUG "enable debugging (ON or OFF. default:OFF)" OFF)
option(ENABLE_TESTS "enable code tests (ON or OFF. default:ON)" ON)
option(ENABLE_ELEMENTS "enable elements code (ON or OFF. default:ON)" ON)
option(ENABLE_BITCOIN  "enable bitcoin code (ON or OFF. default:ON)" ON)

if(NOT WIN32)
#option(TARGET_RPATH "target rpath list (separator is ';') (default:)" "")
set(TARGET_RPATH "" CACHE STRING "target rpath list (separator is ';') (default:)")
option(ENABLE_COVERAGE "enable code coverage (ON or OFF. default:OFF)" OFF)
else()
set(TARGET_RPATH "")
set(ENABLE_COVERAGE FALSE)
endif()

####################
# common setting
####################
set(WORK_WINDOWS_BINARY_DIR_NAME  $<IF:$<CONFIG:Debug>,Debug,Release>)
if(NOT CFD_DLC_OBJ_BINARY_DIR)
set(CFD_DLC_OBJ_BINARY_DIR   ${CMAKE_BINARY_DIR}/${WORK_WINDOWS_BINARY_DIR_NAME})
set(CFD_DLC_ROOT_BINARY_DIR  ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CFD_DLC_OBJ_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CFD_DLC_OBJ_BINARY_DIR}) # for linux
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CFD_DLC_OBJ_BINARY_DIR})
endif()


####################
# function
####################
function(transform_makefile_srclist INPUT_FILE OUTPUT_FILE)
  file(READ ${INPUT_FILE} MAKEFILE_INC_TEXT)

  string(REGEX REPLACE "\\\\\n" "@@@@LF@@@@" MAKEFILE_INC_TEXT ${MAKEFILE_INC_TEXT})
  string(REGEX REPLACE "([a-zA-Z_][a-zA-Z0-9_]*)[\t ]*=[\t ]*([^\n]*)" "SET(\\1 \\2)" MAKEFILE_INC_TEXT ${MAKEFILE_INC_TEXT})
  string(REPLACE "@@@@LF@@@@" "\n" MAKEFILE_INC_TEXT ${MAKEFILE_INC_TEXT})
  string(REGEX REPLACE "\\$\\(([a-zA-Z_][a-zA-Z0-9_]*)\\)" "\${\\1}" MAKEFILE_INC_TEXT ${MAKEFILE_INC_TEXT})
  string(REGEX REPLACE "@([a-zA-Z_][a-zA-Z0-9_]*)@" "\${\\1}" MAKEFILE_INC_TEXT ${MAKEFILE_INC_TEXT})
  file(WRITE ${OUTPUT_FILE} ${MAKEFILE_INC_TEXT})
endfunction()


####################
# test
####################
project(cfddlcjs_all_test CXX)
if(ENABLE_TESTS)
enable_testing()
endif()		# ENABLE_TESTS

####################
# install check
####################
set(EXTERNAL_FILENAME  external_project_local_setting.config)
set(EXTERNAL_LOCAL_FILENAME  local_resource/${EXTERNAL_FILENAME})
if(EXISTS ${EXTERNAL_LOCAL_FILENAME})
transform_makefile_srclist(${EXTERNAL_LOCAL_FILENAME} "${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_FILENAME}.cmake")
include(${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_FILENAME}.cmake)
endif()
if(CFDDLCJS_VERSION)
set(PACKAGE_VERSION    ${CFDDLCJS_VERSION})
else()
set(PACKAGE_VERSION    ${PACKAGE_VERSION})
endif()

find_package(PkgConfig)
if(PKG_CONFIG_FOUND AND (NOT WIN32) AND (NOT APPLE))
pkg_check_modules(CFDDLCJS_API cfd-dlc-js)
set(CFDDLCJS_API_INSTALLED   ${CFDJS_API_FOUND})
else()
set(CFDDLCJS_API_INSTALLED   FALSE)
endif()

####################
# subdirectories
####################
if(CFDDLCJS_API_INSTALLED)
message(STATUS "[CFDDLCJS_API] use installed library.")
else()
if(NOT CFD_DLC_SINGLE_BUILD)
add_subdirectory(external)
endif()  # CFD_DLC_SINGLE_BUILD
add_subdirectory(src)
endif()  # CFDDLCJS_API_INSTALLED
add_subdirectory(addon)


####################
# install & export
####################
if(NOT CFDDLCJS_API_INSTALLED)
set(prefix            ${CMAKE_INSTALL_PREFIX})
set(exec_prefix       ${prefix})
set(libdir            ${exec_prefix}/lib)
set(includedir        ${prefix}/include)

configure_file(pc/cfd-dlc-js.pc.in  cfd-dlc-js.pc  @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cfd-dlc-js.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

endif()  # CFDDLCJS_API_INSTALLED