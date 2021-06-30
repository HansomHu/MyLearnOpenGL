add_executable(TestStbImage TestStbImage.cpp)
target_link_libraries(TestStbImage ${THIRDPARTY_LIBRARIES})

add_executable(TestAssimp TestAssimp.cpp)
target_link_libraries(TestAssimp ${THIRDPARTY_LIBRARIES} ${ASSIMP_LIBRARY})

add_executable(TestGLM TestGLM.cpp)