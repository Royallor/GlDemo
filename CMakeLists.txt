cmake_minimum_required(VERSION 3.16)

project(GLDemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++14 -lstdc++ -lm")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/includes)

include_directories(${INCLUDE_PATH})

add_executable(GLDemo src/triangle/triangle.cpp src/glad.c)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(GLDemo PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/includes>
                           $<INSTALL_INTERFACE:include>)
target_link_libraries(GLDemo PUBLIC glfw OpenGL::GL ${CMAKE_DL_LIBS})
