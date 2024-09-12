#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "lua.h"
// 引用基础库

#include "Core/Core.h"
#include <iostream>

/* 编写各顶点位置与颜色 */
GLfloat vertices_1[] =
{	// position				// color
	0.0f, 0.5f, 0.0f,		1.0f, 0.0f, 0.0f,		// 上顶点(红色)
	-0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,		// 左顶点(绿色)
	0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f		// 右顶点(蓝色)
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