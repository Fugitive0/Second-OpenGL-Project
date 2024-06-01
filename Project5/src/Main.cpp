#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <glad/glad.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>


#include <GLFW/glfw3.h>


#include <cstdlib>
#include <iostream>

#include "shader.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;



int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    Shader firstShader("src/3.3vShader.vs", "src/3.3fShader.fs");


    /*
    
    Psuedocode:

    We first want to create a vertex buffer object. A VBO is responsible for holding our vertex data.
    When creating a vbo, we first want to create one (ofc) and imply the usage of the vbo. The vbo can either be a buffer which
    that is only created and modified once (Gl_STATIC_DRAW) or imply whether or not the buffer will be modified several times (GL_DYNAMIC_DRAW)

    After we set up our vbo, we then want to create a vertex array object. The VAO is responsible for taking the vertex buffer object and
    telling opengl what to do with it. 

    In order, it is the responsible thing to create the VAO before creating the VBO.
    */

#pragma region Vertices
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
#pragma endregion
#pragma region Cube Locations

    glm::vec3 cubeLocations[] =
    {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(2.0f,  5.0f, -15.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 0.0f)
    };





#pragma endregion


    unsigned int VBO, VAO;
   

    glGenVertexArrays(1, &VAO); // Here we generate the vertex array object
    glGenBuffers(1, &VBO); // Then we generate the Vertex Buffer object


    glBindVertexArray(VAO); // We now bind the VAO to the VBO

    glBindBuffer(GL_ARRAY_BUFFER, VBO); // The below code will now affect the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // We give our vertex buffer array data.

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // ImGUI vars
    
    float viewX = 0.0f;
    float viewY = 0.0f;
    float viewZ = 0.0f;
    float colorR = 0.0f;
    float colorG = 0.0f;
    float colorB = 0.0f;
    float colorA = 0.0f;
    float rotate = 0.0f;
    float cubeRotateSpeed = 0.0f;
    bool isTimeRotate = false;

    // Adjusts all of the triangles in the scene
    glEnable(GL_DEPTH_TEST);
    // render loop
    while (!glfwWindowShouldClose(window))
    {

        processInput(window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        firstShader.use();
        // Adjusts all of the triangles in the scene
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);
        glm::vec4 color = glm::vec4(colorR, colorG, colorB, colorA);

        view = glm::translate(view, glm::vec3(0.0f + viewX, 0.0f + viewY, -3.0f + viewZ));
        view = glm::rotate(view, 20.0f, glm::vec3(0.0f, 1.0f, 0.0f));
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);




        // retrieve the matrix uniform locations

        // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        firstShader.setMat4("projection", projection);
        firstShader.setMat4("view", view);
        firstShader.setVec4("color", color);


        // render boxes 
        glBindVertexArray(VAO);

        // Draw first cube

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubeLocations[0]);
        if (!isTimeRotate)
        {
            model = glm::rotate(model, glm::radians(rotate), glm::vec3(1.0f, 0.3f, 0.5f));
        }
        else
        {
            model = glm::rotate(model, (float)glfwGetTime() * cubeRotateSpeed, glm::vec3(1.0f, 0.3f, 0.5f));
        }

        firstShader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLES, 0, 36);
        
        // Draw second cube

        model = glm::mat4(1.0f);
        model = glm::translate(model, cubeLocations[1]);
        model = glm::rotate(model, glm::radians(20.0f), glm::vec3(1.0f, 0.3f, 0.5f));
        firstShader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        ImGui::Begin("Tool Palette");
        ImGui::Text("Camera Coordinates");
        ImGui::SliderFloat("x", &viewX, 0.0f, 2.0f);
        ImGui::SliderFloat("y", &viewY, 0.0f, 2.0f);
        ImGui::SliderFloat("z", &viewZ, 0.0f, 2.0f);
        ImGui::SliderFloat("rotate", &rotate, 0, 100);
        ImGui::Text("Cube Colors");
        ImGui::SliderFloat("R", &colorR, 0.0f, 1.0f);
        ImGui::SliderFloat("G", &colorG, 0.0f, 1.0f);
        ImGui::SliderFloat("B", &colorB, 0.0f, 1.0f);
        ImGui::SliderFloat("A", &colorA, 0.0f, 1.0f);
        ImGui::Text("cube rotation settings");
        ImGui::Checkbox("time rotate", &isTimeRotate);
        ImGui::SliderFloat("cube rotate speed", &cubeRotateSpeed, 0, 100);

        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(firstShader.ID);

    // clear all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
