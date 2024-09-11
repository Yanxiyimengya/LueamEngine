#include "glad/glad.h"
#include "glfw/glfw3.h";
#include "Renderer.h"

Renderer::Renderer() {
	glfwInit();
}

Renderer::~Renderer() {
	glfwTerminate();
}
