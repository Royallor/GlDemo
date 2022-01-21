#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <shader_m.h>
#include <filesystem.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // ----------------------
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //glad: load all OpenGL function pointers
    //---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //configure global opengl state
    // ----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // -------------------------------------
    Shader ourSHader("7.1.camera.vs", "7.1.camera.fs");

    // set up vertex data (and buffers(s)) and configure vertex attributes
    // -------------------------------------------------------------------
    float vertices[] = {-0.5f,
                        -0.5f,
                        -0.5f,
                        0.0f,
                        0.0f,
                        0.5f,
                        -0.5f,
                        -0.5f,
                        1.0f,
                        0.0f,
                        0.5f,
                        0.5f,
                        -0.5f,
                        1.0f,
                        1.0f,
                        0.5f,
                        0.5f,
                        -0.5f,
                        1.0f,
                        1.0f,
                        -0.5f,
                        0.5f,
                        -0.5f,
                        0.0f,
                        1.0f,
                        -0.5f,
                        -0.5f,
                        -0.5f,
                        0.0f,
                        0.0f,

                        -0.5f,
                        -0.5f,
                        0.5f,
                        0.0f,
                        0.0f,
                        0.5f,
                        -0.5f,
                        0.5f,
                        1.0f,
                        0.0f,
                        0.5f,
                        0.5f,
                        0.5f,
                        1.0f,
                        1.0f,
                        0.5f,
                        0.5f,
                        0.5f,
                        1.0f,
                        1.0f,
                        -0.5f,
                        0.5f,
                        0.5f,
                        0.0f,
                        1.0f,
                        -0.5f,
                        -0.5f,
                        0.5f,
                        0.0f,
                        0.0f,

                        -0.5f,
                        0.5f,
                        0.5f,
                        1.0f,
                        0.0f,
                        -0.5f,
                        0.5f,
                        -0.5f,
                        1.0f,
                        1.0f,
                        -0.5f,
                        -0.5f,
                        -0.5f,
                        0.0f,
                        1.0f,
                        -0.5f,
                        -0.5f,
                        -0.5f,
                        0.0f,
                        1.0f,
                        -0.5f,
                        -0.5f,
                        0.5f,
                        0.0f,
                        0.0f,
                        -0.5f,
                        0.5f,
                        0.5f,
                        1.0f,
                        0.0f,

                        0.5f,
                        0.5f,
                        0.5f,
                        1.0f,
                        0.0f,
                        0.5f,
                        0.5f,
                        -0.5f,
                        1.0f,
                        1.0f,
                        0.5f,
                        -0.5f,
                        -0.5f,
                        0.0f,
                        1.0f,
                        0.5f,
                        -0.5f,
                        -0.5f,
                        0.0f,
                        1.0f,
                        0.5f,
                        -0.5f,
                        0.5f,
                        0.0f,
                        0.0f,
                        0.5f,
                        0.5f,
                        0.5f,
                        1.0f,
                        0.0f,

                        -0.5f,
                        -0.5f,
                        -0.5f,
                        0.0f,
                        1.0f,
                        0.5f,
                        -0.5f,
                        -0.5f,
                        1.0f,
                        1.0f,
                        0.5f,
                        -0.5f,
                        0.5f,
                        1.0f,
                        0.0f,
                        0.5f,
                        -0.5f,
                        0.5f,
                        1.0f,
                        0.0f,
                        -0.5f,
                        -0.5f,
                        0.5f,
                        0.0f,
                        0.0f,
                        -0.5f,
                        -0.5f,
                        -0.5f,
                        0.0f,
                        1.0f,

                        -0.5f,
                        0.5f,
                        -0.5f,
                        0.0f,
                        1.0f,
                        0.5f,
                        0.5f,
                        -0.5f,
                        1.0f,
                        1.0f,
                        0.5f,
                        0.5f,
                        0.5f,
                        1.0f,
                        0.0f,
                        0.5f,
                        0.5f,
                        0.5f,
                        1.0f,
                        0.0f,
                        -0.5f,
                        0.5f,
                        0.5f,
                        0.0f,
                        0.0f,
                        -0.5f,
                        0.5f,
                        -0.5f,
                        0.0f,
                        1.0f};
    // world space positions of our cubes
    glm::vec3 cubePositions[] = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(2.0f, 5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f, 2.0f, -2.5f),
        glm::vec3(1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)};
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));

    // load and create a texture
    // -------------------------
    unsigned int texture1, texture2;
    // texture1
    // --------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis
    unsigned char *data = stbi_load(FileSystem::getPath(""));
}