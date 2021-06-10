cmake_minimum_required(VERSION 3.0.0)
project(MyOpenGL VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(GLEW REQUIRED)
message(STATUS "glew include: ${GLEW_INCLUDE_DIRS}")

add_executable(HelloTriangle HelloTriangle.cpp)
target_link_libraries(HelloTriangle ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(HelloEBO HelloEBO.cpp)
target_link_libraries(HelloEBO ${OPENGL_LIBRARIES} glfw GLEW::GLEW)
