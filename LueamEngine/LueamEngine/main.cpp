#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "lua.h"
// ���û�����

#include "Core/Core.h"
#include <iostream>

/* ��д������λ������ɫ */
GLfloat vertices_1[] =
{	// position				// color
	0.0f, 0.5f, 0.0f,		1.0f, 0.0f, 0.0f,		// �϶���(��ɫ)
	-0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,		// �󶥵�(��ɫ)
	0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f		// �Ҷ���(��ɫ)
};

int main()
{
	MainLoop main_loop;
	Window* main_window = main_loop.create_window(Vector2(640, 480));
	glfwMakeContextCurrent(main_window->handle);
	gladLoadGL();
	main_loop.run();
	

	return 0;
}