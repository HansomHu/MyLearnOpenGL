add_executable(colors colors.cpp)
target_link_libraries(colors ${OPENGL_LIBRARIES} glfw GLEW::GLEW)