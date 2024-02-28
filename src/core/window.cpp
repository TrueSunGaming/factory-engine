#include "window.hpp"
#include <iostream>

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
} 

GLFWwindow* createWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback); 

    return window;
}

void startWindowLoop(GLFWwindow* window) {
    while(!glfwWindowShouldClose(window)) {
        for (std::function<void(GLFWwindow*)> i : loopCallbackBuffer) i(window);

        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        for (std::function<void(GLFWwindow*)> i : renderCallbackBuffer) i(window);

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
}

size_t addLoopCallback(std::function<void(GLFWwindow*)> callback) {
    loopCallbackBuffer.push_back(callback);
    return loopCallbackBuffer.size() - 1;
}

size_t addRenderCallback(std::function<void(GLFWwindow*)> callback) {
    renderCallbackBuffer.push_back(callback);
    return renderCallbackBuffer.size() - 1;
}