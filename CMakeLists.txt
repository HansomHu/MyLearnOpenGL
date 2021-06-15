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

add_executable(HelloTriangle HelloTriangle.cpp)
target_link_libraries(HelloTriangle ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(HelloEBO HelloEBO.cpp)
target_link_libraries(HelloEBO ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(MultiVertexAttribTriangle MultiVertexAttribTriangle.cpp)
target_link_libraries(MultiVertexAttribTriangle ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(ShaderClassDemo ShaderClassDemo.cpp)
target_link_libraries(ShaderClassDemo ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(Texture Texture.cpp)
target_link_libraries(Texture ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_subdirectory(test)