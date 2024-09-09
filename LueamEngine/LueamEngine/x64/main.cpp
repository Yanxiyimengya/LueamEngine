#include "lua.hpp"
#include "glad/glad.h"
#include "glfw/glfw3.h"


int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(800, 600, "Game Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); //´´½¨Context
    gladLoadGL();

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}