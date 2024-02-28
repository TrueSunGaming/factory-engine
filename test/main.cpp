#include "../src/core/window.hpp"
#include "../src/core/file.hpp"
#include <iostream>

int main() {
    GLFWwindow* window = createWindow();
    startWindowLoop(window);
}