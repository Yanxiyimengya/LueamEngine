#include "MainLoop.h"
#include "lua.hpp"
#include "../Core.h"

MainLoop::MainLoop() {
	this->renderer = new Renderer(); // 初始化渲染器对象
}

MainLoop::~MainLoop() {
	delete this->renderer; // 释放渲染器对象
}


void MainLoop::run() {
	for (const GameObject& _obj : this->object_list) {
		if (_obj.lua_state != NULL) {
			 
		}
	}

	VertexBufferFormat vbf;
	vbf.begin();
	vbf.add_position_2d();
	vbf.end();

	VertexBuffer vbo(vbf);
	vbo.begin();
	vbo.add_position_2d(Vector2(-1.0, -1.0));
	vbo.add_position_2d(Vector2(1.0, -1.0));
	vbo.add_position_2d(Vector2(0.0, 1.0));
	vbo.end();

	Shader shader(String(
	"#version 330 core\n"
	"layout(location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = vec4(aPos, 1.0);\n"
	"}\n"
	),String(
	"#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	//"	FragColor = ourColor;\n"
	"	FragColor.rgb = vec3(1.0, 0.0, 0.0);"
	"}\n"
	));
	shader.compile_shader();
	

	while (!this->closed) {
		Window* window;
		for (int i = 0; i < this->window_list.size();i ++) {
			window = &this->window_list[i];

			if (!glfwWindowShouldClose(window->handle)) {
				glfwMakeContextCurrent(window->handle);

				shader.use_shader();
				this->renderer->draw_buffer(vbo);
				
				glfwSwapBuffers(window->handle);
				glfwPollEvents();
			}
			else {
				if (window->handle == this->main_window) {
					this->close();
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

bool MainLoop::is_closed() {
	return this->closed;
}

void MainLoop::close() {
	this->closed = true;
}