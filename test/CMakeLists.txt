add_executable(TestStbImage TestStbImage.cpp)
target_link_libraries(TestStbImage ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(TestGLM TestGLM.cpp)