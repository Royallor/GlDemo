cmake_minimum_required(VERSION 3.10.2)

project(GLDemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++14 -lstdc++ -lm")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/includes)
set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCLUDE_PATH})

file(GLOB_RECURSE SRC_FILES ${SRC_PATH}/*.cpp)

add_executable(GLDemo ${SRC_FILES})

target_link_libraries(GLDemo glfw)