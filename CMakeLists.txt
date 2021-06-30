cmake_minimum_required(VERSION 3.0.0)
project(MyOpenGL VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(GLEW REQUIRED)
message(STATUS "glew include: ${GLEW_INCLUDE_DIRS}")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glm
)

set(RESOURCE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data)
set(GLSL_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glsl)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/resource.h.in
               ${CMAKE_CURRENT_SOURCE_DIR}/helper/resource.h @ONLY
)

add_subdirectory(samples)
add_subdirectory(test)