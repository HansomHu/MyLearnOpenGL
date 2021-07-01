#include <iostream>
#include <random> // for random engine

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other includes
#include <helper/camera.h>
#include <helper/resource.h>
#include <helper/shader.h>

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void do_movement(GLfloat deltaTime);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// Camera parameters
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 2.0f);

GLfloat lastX = WIDTH / 2.0;
GLfloat lastY = HEIGHT / 2.0;

// make the camera look at a point that is between the light & object
Camera camera(cameraPos, cameraUp, -65.0f, 25.0f);

// a keyboard array to store the pressed/released status, true-pressed, false-released
bool keyboard[1024] = { false };

// The MAIN function, from here we start the application and run the game loop
int main() {
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    // make all the configs above valid for mac OS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // GLFW Options
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    // Define the viewport dimensions
    glViewport(0, 0, WIDTH, HEIGHT);

    // Build and compile our shader program
    const std::string lightVshFile = std::string(GLSL_ROOT_DIR) + "/lighting/colors/light.vsh";
    const std::string lightFshFile = std::string(GLSL_ROOT_DIR) + "/lighting/colors/light.fsh";
    Shader lightShader(lightVshFile.c_str(), lightFshFile.c_str());

    const std::string objectVshFile = std::string(GLSL_ROOT_DIR) + "/lighting/colors/object.vsh";
    const std::string objectFshFile = std::string(GLSL_ROOT_DIR) + "/lighting/colors/object.fsh";
    Shader objectShader(objectVshFile.c_str(), objectFshFile.c_str());

    // clang-format off
    // Set up vertex data (and buffer(s)) and attribute pointers
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
    // clang-format on
    // configure the light VAO
    GLuint VBO, lightVAO;
    glGenVertexArrays(1, &lightVAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(lightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0); // Unbind VAO

    // configure the object VAO
    GLuint objectVAO;
    glGenVertexArrays(1, &objectVAO);

    glBindVertexArray(objectVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0); // Unbind VAO

    std::mt19937 randomEngine = std::mt19937(static_cast<std::mt19937::result_type>(10)); // setup seed
    // clang-format off
    // we want to render 10 different cubes each locates at specific position
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    // clang-format on

    // rotate axis
    glm::vec3 rotateAxis[] = {
        glm::vec3(float(randomEngine() % 10), float(randomEngine() % 10), float(randomEngine() % 10)),
        glm::vec3(float(randomEngine() % 10), float(randomEngine() % 10), float(randomEngine() % 10)),
        glm::vec3(float(randomEngine() % 10), float(randomEngine() % 10), float(randomEngine() % 10)),
        glm::vec3(float(randomEngine() % 10), float(randomEngine() % 10), float(randomEngine() % 10)),
        glm::vec3(float(randomEngine() % 10), float(randomEngine() % 10), float(randomEngine() % 10)),
        glm::vec3(float(randomEngine() % 10), float(randomEngine() % 10), float(randomEngine() % 10)),
        glm::vec3(float(randomEngine() % 10), float(randomEngine() % 10), float(randomEngine() % 10)),
        glm::vec3(float(randomEngine() % 10), float(randomEngine() % 10), float(randomEngine() % 10)),
        glm::vec3(float(randomEngine() % 10), float(randomEngine() % 10), float(randomEngine() % 10)),
        glm::vec3(float(randomEngine() % 10), float(randomEngine() % 10), float(randomEngine() % 10)),
    };

    GLfloat deltaTime = 0.0f; // interval
    GLfloat lastFrame = glfwGetTime(); // last frame time point
    // Game loop
    while (!glfwWindowShouldClose(window)) {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response
        // functions
        glfwPollEvents();
        // enable depth test to avoid overlay
        glEnable(GL_DEPTH_TEST);
        // Render
        // Clear the colorbuffer & Z-buffer
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        deltaTime = glfwGetTime() - lastFrame;
        lastFrame = glfwGetTime();

        do_movement(deltaTime);

        // be sure to activate shader when setting uniforms/drawing objects
        objectShader.use();
        objectShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
        objectShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);

        // Create MVP matrices
        auto view = camera.GetViewMatrix();
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), 1.0f * WIDTH / HEIGHT, 0.1f, 100.0f);
        objectShader.setMat4("projection", projection);
        objectShader.setMat4("view", view);
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(float(glfwGetTime()) * 50.0f), rotateAxis[0]);
        objectShader.setMat4("model", model);

        // Draw object
        glBindVertexArray(objectVAO);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / sizeof(GLfloat));
        glBindVertexArray(0);

        // Draw light
        lightShader.use();
        lightShader.setMat4("projection", projection);
        lightShader.setMat4("view", view);
        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f));
        lightShader.setMat4("model", model);
        glBindVertexArray(lightVAO);
        glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / sizeof(GLfloat));
        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &lightVAO);
    glDeleteVertexArrays(1, &objectVAO);
    glDeleteBuffers(1, &VBO);

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (action == GLFW_PRESS) {
        keyboard[key] = true;
    } else if (action == GLFW_RELEASE) {
        keyboard[key] = false;
    }
}

// do movement by key
void do_movement(GLfloat deltaTime) {
    if (keyboard[GLFW_KEY_W] || keyboard[GLFW_KEY_UP]) {
        camera.ProcessKeyboard(CameraMovement::FORWARD, deltaTime);
    }
    if (keyboard[GLFW_KEY_S] || keyboard[GLFW_KEY_DOWN]) {
        camera.ProcessKeyboard(CameraMovement::BACKWARD, deltaTime);
    }
    if (keyboard[GLFW_KEY_A] || keyboard[GLFW_KEY_LEFT]) {
        camera.ProcessKeyboard(CameraMovement::LEFT, deltaTime);
    }
    if (keyboard[GLFW_KEY_D] || keyboard[GLFW_KEY_RIGHT]) {
        camera.ProcessKeyboard(CameraMovement::RIGHT, deltaTime);
    }
}

bool firstMouse = true;
void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos; // Reversed since y-coordinates go from bottom to left
    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera.ProcessMouseScroll(yoffset);
}