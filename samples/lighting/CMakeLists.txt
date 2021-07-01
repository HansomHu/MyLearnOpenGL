add_executable(colors colors.cpp)
target_link_libraries(colors ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(lightingDiffuse lightingDiffuse.cpp)
target_link_libraries(lightingDiffuse ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_executable(lightingSpecular lightingSpecular.cpp)
target_link_libraries(lightingSpecular ${OPENGL_LIBRARIES} glfw GLEW::GLEW)