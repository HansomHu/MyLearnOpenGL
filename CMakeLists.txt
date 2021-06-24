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

add_executable(HelloTriangle HelloTriangle.cpp)
target_link_libraries(HelloTriangle ${THIRDPARTY_LIBRARIES})

add_executable(HelloEBO HelloEBO.cpp)
target_link_libraries(HelloEBO ${THIRDPARTY_LIBRARIES})

add_executable(MultiVertexAttribTriangle MultiVertexAttribTriangle.cpp)
target_link_libraries(MultiVertexAttribTriangle ${THIRDPARTY_LIBRARIES})

add_executable(ShaderClassDemo ShaderClassDemo.cpp)
target_link_libraries(ShaderClassDemo ${THIRDPARTY_LIBRARIES})

add_executable(Texture Texture.cpp)
target_link_libraries(Texture ${THIRDPARTY_LIBRARIES})

add_executable(Transform2D Transform2D.cpp)
target_link_libraries(Transform2D ${THIRDPARTY_LIBRARIES})

add_executable(Transform3D Transform3D.cpp)
target_link_libraries(Transform3D ${THIRDPARTY_LIBRARIES})

add_executable(Transform3DMove Transform3DMove.cpp)
target_link_libraries(Transform3DMove ${THIRDPARTY_LIBRARIES})

add_executable(Transform3DMoveKeyboard Transform3DMoveKeyboard.cpp)
target_link_libraries(Transform3DMoveKeyboard ${THIRDPARTY_LIBRARIES})

add_executable(Transform3DMoveMouse Transform3DMoveMouse.cpp)
target_link_libraries(Transform3DMoveMouse ${THIRDPARTY_LIBRARIES})

add_subdirectory(test)