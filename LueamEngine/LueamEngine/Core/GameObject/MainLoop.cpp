//#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "MainLoop.h"
#include "lua.hpp"

void MainLoop::run() {

	for (const GameObject& _obj : this->object_list) {
		if (_obj.lua_state != NULL) {

		}
	}

	while (!this->quitting) {
		Window* window;
		for (int i = 0; i < this->window_list.size();i ++) {
			window = &this->window_list[i];
			if (!glfwWindowShouldClose(window->handle)) {
				glfwMakeContextCurrent(window->handle);

				glBegin(GL_TRIANGLES);
				glColor3f(1.0f, 0.0f, 0.0f);  // 设置顶点颜色为红色
				glVertex3f(-1.0f, -1.0f, 0.0f);  // 设置第一个顶点
				glColor3f(0.0f, 1.0f, 0.0f);  // 设置顶点颜色为绿色
				glVertex3f(1.0f, -1.0f, 0.0f);  // 设置第二个顶点
				glColor3f(0.0f, 0.0f, 1.0f);  // 设置顶点颜色为蓝色
				glVertex3f(0.0f, 1.0f, 0.0f);  // 设置第三个顶点
				glEnd();

				glfwSwapBuffers(window->handle);
				glfwPollEvents();
			}
			else {
				if (window->handle == this->main_window) {
					return;
				}
				else {
					this->window_list.erase(this->window_list.begin() + i);
					glfwDestroyWindow(window->handle);
					continue;
				}
			}
		};
		window = NULL;
	}
}

Window* MainLoop::create_window(Vector2 size) {
	Window* window = new Window();
	window->handle = glfwCreateWindow((int)size.x, (int)size.y, window->title, nullptr, nullptr);
	if (this->window_list.empty()) {
		this->main_window = window->handle;
	}
	window->size = size;
	this->window_list.push_back(*window);
	//gladLoadGL();
	return window;
};

bool MainLoop::is_quitting() {
	return this->quitting;
}

void MainLoop::quit() {
	this->quitting = true;
}