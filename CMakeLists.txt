cmake_minimum_required(VERSION 2.8)

project(drought)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++1y")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")


#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(EXECUTABLE_NAME "Drought")
add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCE_DIR}/source/main.cpp)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})

include_directories(
  ${PROJECT_SOURCE_DIR}/source)

file(GLOB sources "source/*.cpp")

add_library(file STATIC ${sources})

# OpenGL
#find_package(OPENGL REQUIRED)
#include_directories(${OPENGL_INCLUDE_DIR})
#if (OPENGL_FOUND)
  #target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
  #target_link_libraries(${EXECUTABLE_NAME} m)
#endif()


find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

target_link_libraries(${EXECUTABLE_NAME} file)