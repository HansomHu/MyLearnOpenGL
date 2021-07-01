add_executable(colors colors.cpp)
target_link_libraries(colors ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(lightingDiffuse lightingDiffuse.cpp)
target_link_libraries(lightingDiffuse ${OPENGL_LIBRARIES} glfw GLEW::GLEW)