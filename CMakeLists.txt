include(CMakeForceCompiler)

cmake_minimum_required (VERSION 3.5)
set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MicroByteExample)

ADD_GLOBALDIR(${CMAKE_CURRENT_SOURCE_DIR})
ADD_GLOBALDIR(${CMAKE_CURRENT_SOURCE_DIR}/source)

FILE(GLOB MICROBYTE_EXAMPLE_SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp"
)

add_definitions(-DMICROBYTE_PROJECT_CONFIG_FILE="MicroByteProjectConfig.h")
add_definitions(-DTOOLCHAIN_GCC)
add_definitions(-DTOOLCHAIN_GCC_ARM)
add_definitions(-DMBED_OPERATORS)

CREATE_TEST_LIBRARY(microbyte_example "${MICROBYTE_EXAMPLE_SRCS}" "")
add_dependencies(microbyte_example PLATFORM_LIBS)
target_link_libraries(microbyte_example PLATFORM_LIBS)

ADDSUBDIRS()
