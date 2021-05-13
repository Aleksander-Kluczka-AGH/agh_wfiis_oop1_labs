cmake_minimum_required(VERSION 3.1)

project (main)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COLOR_MAKEFILE   ON)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

set(PROJECT_LINK_DIRECTORY ${PROJECT_SOURCE_DIR})
add_compile_options(${CMAKE_CXX_FLAGS})

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

add_custom_target(run ./main)
add_custom_target(check valgrind ./main)