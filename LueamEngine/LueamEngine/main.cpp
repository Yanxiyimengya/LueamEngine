#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "lua.h"
// ÒıÓÃ»ù´¡¿â

#include "Core/Core.h"
#include <iostream>

int main()
{
	MainLoop main_loop;
	Window* main_window = main_loop.create_window(Vector2(640, 480));
	glfwMakeContextCurrent(main_window->handle);
	gladLoadGL();
	main_loop.run();
	

	return 0;
}