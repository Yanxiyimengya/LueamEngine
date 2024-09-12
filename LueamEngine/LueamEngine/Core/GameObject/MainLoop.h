#pragma once
#include "Core/GameObject/GameObject.h"
#include "Core/Graphics/Renderer.h"
#include <vector>

class MainLoop
{
	std::vector<GameObject> object_list;
	std::vector<Window> window_list;

	bool closed = false;
	GLFWwindow* main_window = nullptr;

public :
	Renderer* renderer;

	MainLoop();
	~MainLoop();

	void run();
	Window* create_window(Vector2 size);
	bool is_closed();
	void close();
};

