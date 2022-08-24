cmake_minimum_required(VERSION 3.13)

cmake_policy(SET CMP0076 NEW)

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

if(NOT WIN32)
#option(TARGET_RPATH "target rpath list (separator is ';') (default:)" "")
set(TARGET_RPATH "" CACHE STRING "target rpath list (separator is ';') (default:)")
option(ENABLE_COVERAGE "enable code coverage (ON or OFF. default:OFF)" OFF)
option(ENABLE_RPATH "enable rpath (ON or OFF. default:ON)" ON)
else()
set(TARGET_RPATH "")
set(ENABLE_COVERAGE FALSE)
set(ENABLE_RPATH off)
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
set(ENABLE_DEBUG  TRUE)
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS $<$<CONFIG:Debug>:DEBUGBUILD>)
set(OPTION_BIGOBJ  "/bigobj")
else()
set(ENABLE_DEBUG  FALSE)
set(OPTION_BIGOBJ  "")
endif() # CMAKE_BUILD_TYPE

####################
# common setting
####################
set(WORK_WINDOWS_BINARY_DIR_NAME  $<IF:$<CONFIG:Debug>,Debug,Release>)
if(NOT CFD_DLC_OBJ_BINARY_DIR)
set(CFD_DLC_OBJ_BINARY_DIR   ${CMAKE_BINARY_DIR}/${WORK_WINDOWS_BINARY_DIR_NAME})
set(CFD_DLC_ROOT_BINARY_DIR  ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${CFD_DLC_OBJ_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CFD_DLC_OBJ_BINARY_DIR}) # for linux
endif()

if(NOT CFD_DLC_SRC_ROOT_DIR)
set(CFD_DLC_SRC_ROOT_DIR   ${CMAKE_SOURCE_DIR})
endif()

if(NOT WIN32)
if(ENABLE_RPATH)
set(CMAKE_SKIP_BUILD_RPATH  FALSE)
if(APPLE)
set(CMAKE_MACOSX_RPATH 1)
else()
set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)
endif()
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

if(TARGET_RPATH)
if(APPLE)
string(REPLACE "\$\$ORIGIN" "." TEMP_RPATH1 "${TARGET_RPATH}")
string(REPLACE "\$ORIGIN" "." TEMP_RPATH2 "${TEMP_RPATH1}")
string(REPLACE "\$\${ORIGIN}" "." TEMP_RPATH3 "${TEMP_RPATH2}")
string(REPLACE "\${ORIGIN}" "." MODIFIED_RPATH "${TEMP_RPATH3}")
set(CMAKE_INSTALL_RPATH "${MODIFIED_RPATH};./;./build/${RPATH_TARGET};@rpath")
else()
string(REPLACE "\$\${ORIGIN}" "$$ORIGIN" TEMP_RPATH1 "${TARGET_RPATH}")
string(REPLACE "\${ORIGIN}" "$ORIGIN" MODIFIED_RPATH "${TEMP_RPATH1}")
set(CMAKE_INSTALL_RPATH "${MODIFIED_RPATH};$ORIGIN/;./;./build/${RPATH_TARGET};@rpath")
endif()
else(TARGET_RPATH)
if(APPLE)
set(CMAKE_INSTALL_RPATH "./;./build/${RPATH_TARGET};@rpath")
else()
set(CMAKE_INSTALL_RPATH "$ORIGIN/;./;./build/${RPATH_TARGET};@rpath")
endif()
endif(TARGET_RPATH)
else()
set(CMAKE_SKIP_BUILD_RPATH  TRUE)
endif()
endif()

if(ENABLE_DEBUG AND ENABLE_COVERAGE)
set(COLLECT_COVERAGE ON)
set(PROFILE_ARCS_OPT -fprofile-arcs)
set(TEST_COVERAGE_OPT -ftest-coverage)
set(GCOV_LIBRARY gcov)
set(COVERAGE 1)
else()
set(PROFILE_ARCS_OPT  "")
set(TEST_COVERAGE_OPT "")
set(GCOV_LIBRARY  "")
endif()

####################
# cfddlcjs build
####################
# cfd-dlc-js-api
project(cfddlcjs_api CXX)
set(CFDDLC_LIBRARY cfddlc)
set(CFD_LIBRARY cfd)
set(CFDCORE_LIBRARY cfdcore)
# set(LIBWALLY_LIBRARY wally)
set(UNIVALUE_LIBRARY univalue)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od /Zi")
else()
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb")
endif()

find_package(univalue QUIET CONFIG)
find_package(wally QUIET CONFIG)
find_package(cfdcore QUIET CONFIG)
find_package(cfd QUIET CONFIG)
find_package(cfddlc QUIET CONFIG)
if((NOT cfddlc_FOUND) OR (NOT ${cfddlc_FOUND}))
set(USE_INSTALLED_LIBRARY  FALSE)

if((NOT cfd_FOUND) OR (NOT ${cfd_FOUND}))
set(USE_INSTALLED_CFD_LIBRARY  FALSE)
set(INSTALLED_LIBRARY_DIR  ".")
set(INSTALLED_INCLUDE_DIR  ".")
else()
message(STATUS "[cfd_FOUND]=${cfd_FOUND}")
message(STATUS "[cfd_DIR]=${cfd_DIR}")
set(USE_INSTALLED_CFD_LIBRARY  TRUE)
set(INSTALLED_LIBRARY_DIR "${cfd_DIR}/../lib")
set(INSTALLED_INCLUDE_DIR  "${cfd_DIR}/../include")
endif()

else()
message(STATUS "[cfddlc_FOUND]=${cfddlc_FOUND}")
message(STATUS "[cfddlc_DIR]=${cfddlc_DIR}")

set(USE_INSTALLED_LIBRARY  TRUE)
set(USE_INSTALLED_CFD_LIBRARY  TRUE)
set(INSTALLED_LIBRARY_DIR "${cfddlc_DIR}/../lib")
set(INSTALLED_INCLUDE_DIR  "${cfddlc_DIR}/../include")
endif()


# js-api library
if(ENABLE_SHARED)
add_library(${PROJECT_NAME} SHARED)
else()
add_library(${PROJECT_NAME} STATIC)
endif()

target_sources(${PROJECT_NAME}
  PRIVATE
    cfddlcjs_json_mapping_api.cpp
    cfddlcjs_transactions.cpp
    cfddlcapi_error_json.cpp
    cfddlcjs_utility.cpp
    autogen/cfd_dlc_js_api_json_autogen.cpp
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
    $<IF:$<CXX_COMPILER_ID:MSVC>,
      /LD /source-charset:utf-8 /Wall ${OPTION_BIGOBJ}
      /wd4061 /wd4244 /wd4251 /wd4365 /wd4464 /wd4514 /wd4571 /wd4574 /wd4623 /wd4625 /wd4626 /wd4710 /wd4711 /wd4774 /wd4820 /wd4946 /wd5026 /wd5027 /wd5039 /wd5045 /wd5052,
      -Wall
    >
)
#     -fstack-protector
if(ENABLE_SHARED)
target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    CFD_DLC_JS_API_BUILD=1
    CFDDLC_SHARED=1
    CFD_SHARED=1
    CFD_CORE_SHARED=1
)
else()
target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    CFD_DLC_JS_API_BUILD=1
)
endif()

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    .
    ./autogen
    ${INSTALLED_INCLUDE_DIR}
    ${CFD_DLC_SRC_ROOT_DIR}/external/cfd-core/src/include
)
target_link_directories(${PROJECT_NAME}
  PRIVATE
    ./
    ${INSTALLED_LIBRARY_DIR}
)

if(NOT USE_INSTALLED_LIBRARY)
add_dependencies(${PROJECT_NAME} ${CFDDLC_LIBRARY})
endif(NOT USE_INSTALLED_LIBRARY)

target_link_libraries(${PROJECT_NAME}
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:MSVC>>:winmm.lib>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:MSVC>>:ws2_32.lib>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:GNU>>:-static-libgcc>
  PRIVATE $<$<BOOL:$<CXX_COMPILER_ID:GNU>>:-static-libstdc++>
  PRIVATE $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:pthread>
  PRIVATE $<IF:$<OR:$<PLATFORM_ID:Darwin>,$<CXX_COMPILER_ID:MSVC>>,,rt>
  PRIVATE
    ${CFDDLC_LIBRARY}
    ${CFD_LIBRARY}
    ${CFDCORE_LIBRARY}
    ${UNIVALUE_LIBRARY}
)

if(USE_INSTALLED_CFD_LIBRARY)
if(ENABLE_SHARED)
set(LIB_PREFIX  ${CMAKE_SHARED_LIBRARY_PREFIX})
set(LIB_SUFFIX  ${CMAKE_SHARED_LIBRARY_SUFFIX})
else()
set(LIB_PREFIX  ${CMAKE_STATIC_LIBRARY_PREFIX})
set(LIB_SUFFIX  ${CMAKE_STATIC_LIBRARY_SUFFIX})
endif()

set(LIBWALLY_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}wally${LIB_SUFFIX})
set(UNIVALUE_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}univalue${LIB_SUFFIX})
set(CFDCORE_LIB_PATH   ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfdcore${LIB_SUFFIX})
set(CFD_LIB_PATH       ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfd${LIB_SUFFIX})

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${LIBWALLY_LIB_PATH} ${CFD_DLC_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${UNIVALUE_LIB_PATH} ${CFD_DLC_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${CFDCORE_LIB_PATH} ${CFD_DLC_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${CFD_LIB_PATH} ${CFD_DLC_OBJ_BINARY_DIR}
)

if(NOT ENABLE_SHARED)
set(LIB_PREFIX  ${CMAKE_SHARED_LIBRARY_PREFIX})
set(LIB_SUFFIX  ${CMAKE_SHARED_LIBRARY_SUFFIX})
set(LIBWALLY_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}wally${LIB_SUFFIX})
set(UNIVALUE_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}univalue${LIB_SUFFIX})
set(CFDCORE_LIB_PATH   ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfdcore${LIB_SUFFIX})
set(CFD_LIB_PATH       ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfd${LIB_SUFFIX})

if(EXISTS ${CFD_LIB_PATH})
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${LIBWALLY_LIB_PATH} ${CFD_DLC_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${UNIVALUE_LIB_PATH} ${CFD_DLC_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${CFDCORE_LIB_PATH} ${CFD_DLC_OBJ_BINARY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy ${CFD_LIB_PATH} ${CFD_DLC_OBJ_BINARY_DIR}
)
endif(EXISTS ${CFD_LIB_PATH})
endif(NOT ENABLE_SHARED)
endif()   # USE_INSTALLED_CFD_LIBRARY


if(USE_INSTALLED_LIBRARY)
if(ENABLE_SHARED)
set(LIB_PREFIX  ${CMAKE_SHARED_LIBRARY_PREFIX})
set(LIB_SUFFIX  ${CMAKE_SHARED_LIBRARY_SUFFIX})
else()
set(LIB_PREFIX  ${CMAKE_STATIC_LIBRARY_PREFIX})
set(LIB_SUFFIX  ${CMAKE_STATIC_LIBRARY_SUFFIX})
endif()
set(CFDDLC_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfddlc${LIB_SUFFIX})

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CFDDLC_LIB_PATH} ${CFD_DLC_OBJ_BINARY_DIR}
)

if(NOT ENABLE_SHARED)
set(LIB_PREFIX  ${CMAKE_SHARED_LIBRARY_PREFIX})
set(LIB_SUFFIX  ${CMAKE_SHARED_LIBRARY_SUFFIX})
set(CFDDLC_LIB_PATH  ${INSTALLED_LIBRARY_DIR}/${LIB_PREFIX}cfddlc${LIB_SUFFIX})

if(EXISTS ${CFDDLC_LIB_PATH})
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CFDDLC_LIB_PATH} ${CFD_DLC_OBJ_BINARY_DIR}
)
endif(EXISTS ${CFDDLC_LIB_PATH})
endif(NOT ENABLE_SHARED)
endif()   # USE_INSTALLED_LIBRARY


####################
# install & export
####################
include(GNUInstallDirs)

install(TARGETS       ${PROJECT_NAME}
        EXPORT        ${PROJECT_NAME}-export
        ARCHIVE       DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY       DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME       DESTINATION ${CMAKE_INSTALL_LIBDIR}
        OBJECTS       DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
# https://cmake.org/cmake/help/latest/command/install.html

export(TARGETS ${PROJECT_NAME}
       APPEND FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-export.cmake
       EXPORT_LINK_INTERFACE_LIBRARIES)

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../include/cfddlcjs"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
        FILES_MATCHING PATTERN "*.h")
