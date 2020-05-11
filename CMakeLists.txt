cmake_minimum_required (VERSION 2.8)

project ( table )

set ( SAM_DIR ${PROJECT_SOURCE_DIR}/samples )

set ( APP_NAME table )

set( CMAKE_BUILD_TYPE RELEASE )

include_directories ( include )

list(APPEND SAM ${SAM_DIR}/sample_table.cpp )

add_executable ( ${APP_NAME} ${SAM} )
