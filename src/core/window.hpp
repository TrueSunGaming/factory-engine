#pragma once

#include "../macros.hpp"

#define GLFW_DLL

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <vector>

std::vector<std::function<void(GLFWwindow*)>> loopCallbackBuffer;
std::vector<std::function<void(GLFWwindow*)>> renderCallbackBuffer;

void framebufferSizeCallback(GLFWwindow* window, int width, int height);

GLFWwindow* DLL_EXPORT createWindow();
void DLL_EXPORT startWindowLoop(GLFWwindow* window);
size_t DLL_EXPORT addLoopCallback(std::function<void(GLFWwindow*)> callback);
size_t DLL_EXPORT addRenderCallback(std::function<void(GLFWwindow*)> callback);