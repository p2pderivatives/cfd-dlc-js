project(external_download NONE)

# load file
set(EXTERNAL_DEBUG_FILENAME  external_project_debug.config)
set(DEBUG_VERSION_FILE  ${CMAKE_SOURCE_DIR}/${EXTERNAL_DEBUG_FILENAME})
if(EXISTS ${DEBUG_VERSION_FILE})
transform_makefile_srclist(${DEBUG_VERSION_FILE} "${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_DEBUG_FILENAME}.cmake")
include(${CMAKE_CURRENT_BINARY_DIR}/${EXTERNAL_DEBUG_FILENAME}.cmake)
endif()

# cfd-dlc
if(CFD_DLC_TARGET_VERSION)
set(CFD_DLC_TARGET_TAG  ${CFD_DLC_TARGET_VERSION})
message(STATUS "[external project debug] cfd dlc target=${CFD_DLC_TARGET_VERSION}")
else()
set(CFD_DLC_TARGET_TAG  "v0.0.5")
endif()
if(CFD_DLC_TARGET_URL)
set(CFD_DLC_TARGET_REP  ${CFD_DLC_TARGET_URL})
message(STATUS "[external project debug] cfddlc url=${CFD_DLC_TARGET_URL}")
else()
set(CFD_DLC_TARGET_REP  https://github.com/p2pderivatives/cfd-dlc)
endif()

set(TEMPLATE_PROJECT_NAME           cfd-dlc)
set(TEMPLATE_PROJECT_GIT_REPOSITORY ${CFD_DLC_TARGET_REP})
set(TEMPLATE_PROJECT_GIT_TAG        ${CFD_DLC_TARGET_TAG})
set(PROJECT_EXTERNAL  "${CMAKE_SOURCE_DIR}/external/${TEMPLATE_PROJECT_NAME}/external")
set(DIR_PATH "${CFD_DLC_ROOT_BINARY_DIR}/${TEMPLATE_PROJECT_NAME}")
set(DL_PATH "${CFD_DLC_ROOT_BINARY_DIR}/external/${TEMPLATE_PROJECT_NAME}/download")

get_property(PROP_VALUE  GLOBAL  PROPERTY ${TEMPLATE_PROJECT_NAME})
if(PROP_VALUE)
  message(STATUS "[exist directory] ${TEMPLATE_PROJECT_NAME} exist")
else()
configure_file(template_CMakeLists.txt.in ${DL_PATH}/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -S . -B ${DL_PATH}
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${DL_PATH} )
if(result)
  message(FATAL_ERROR "CMake step for ${TEMPLATE_PROJECT_NAME} failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build ${DL_PATH}
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${DL_PATH} )
if(result)
  message(FATAL_ERROR "Build step for ${TEMPLATE_PROJECT_NAME} failed: ${result}")
endif()
if(EXISTS ${PROJECT_EXTERNAL})
  message(STATUS "[check exist directory] exist ${PROJECT_EXTERNAL}")
  message(STATUS "[check exist directory] dirpath ${DIR_PATH}")
  add_subdirectory(${CMAKE_SOURCE_DIR}/external/${TEMPLATE_PROJECT_NAME}/external
                   ${CFD_DLC_ROOT_BINARY_DIR}/external/${TEMPLATE_PROJECT_NAME}/external)
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/external/${TEMPLATE_PROJECT_NAME}
                 ${DIR_PATH}/build)
set_property(GLOBAL PROPERTY ${TEMPLATE_PROJECT_NAME} 1)
endif()
