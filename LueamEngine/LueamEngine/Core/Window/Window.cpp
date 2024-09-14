#include "Window.h"
#include "glfw/glfw3.h"

Window::Window() { 
};

void Window::resize(Vector2 vec) {
	if (this->handle == nullptr) return;
	glfwSetWindowSize(this->handle, vec.x, vec.y);
}

void Window::set_position(Vector2 position)
{
	if (this->handle == nullptr) return;
	glfwSetWindowPos(this->handle, position.x, position.y);
}
