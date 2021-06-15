#include <stdio.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main(int argc, char** argv) {
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    glm::mat4 trans = glm::translate(glm::mat4(1.f), glm::vec3(1.0f, 1.0f, 0.0f));
    // the matrix has a column-major layout
    printf("trans: \n%.2f %.2f %.2f %.2f\n%.2f %.2f %.2f %.2f\n%.2f %.2f %.2f %.2f\n%.2f %.2f %.2f %.2f\n", 
        trans[0][0], trans[0][1], trans[0][2], trans[0][3],
        trans[1][0], trans[1][1], trans[1][2], trans[1][3],
        trans[2][0], trans[2][1], trans[2][2], trans[2][3],
        trans[3][0], trans[3][1], trans[3][2], trans[3][3]);
    vec = trans * vec;
    std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
    return 0;
}