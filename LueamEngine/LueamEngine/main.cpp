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
	main_loop.renderer = new Renderer();
	Window* main_window = main_loop.create_window(Vector2(640, 480));
	main_loop.create_window(Vector2(640, 480));
	main_loop.run();
	

	return 0;
}