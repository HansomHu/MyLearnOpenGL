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

add_executable(Transform2D Transform2D.cpp)
target_link_libraries(Transform2D ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(Transform3D Transform3D.cpp)
target_link_libraries(Transform3D ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(Transform3DMove Transform3DMove.cpp)
target_link_libraries(Transform3DMove ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(Transform3DMoveKeyboard Transform3DMoveKeyboard.cpp)
target_link_libraries(Transform3DMoveKeyboard ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(Transform3DMoveMouse Transform3DMoveMouse.cpp)
target_link_libraries(Transform3DMoveMouse ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(Transform3DMoveCameraClass Transform3DMoveCameraClass.cpp)
target_link_libraries(Transform3DMoveCameraClass ${OPENGL_LIBRARIES} glfw GLEW::GLEW)
