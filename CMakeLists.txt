cmake_minimum_required(VERSION 3.0.0)
project(MyOpenGL VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(GLEW REQUIRED)

find_path(ASSIMP_INCLUDE_DIR
    NAMES assimp/Importer.hpp
    HINTS ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/assimp/include
)

find_library(ASSIMP_LIBRARY
    NAMES libassimp assimp
    HINTS ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/assimp/lib
)
message(STATUS "ASSIMP_INCLUDE_DIR: ${ASSIMP_INCLUDE_DIR}")
message(STATUS "ASSIMP_LIBRARY: ${ASSIMP_LIBRARY}")

set(THIRD_PARTY_INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glm
    ${ASSIMP_INCLUDE_DIR}
)

set(THIRDPARTY_LIBRARIES
    ${OPENGL_LIBRARIES}
    glfw
    GLEW::GLEW
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${THIRD_PARTY_INCLUDE_DIR}
)

set(RESOURCE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data)
set(GLSL_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glsl)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/resource.h.in
               ${CMAKE_CURRENT_SOURCE_DIR}/helper/resource.h @ONLY
)

add_subdirectory(samples)
add_subdirectory(test)