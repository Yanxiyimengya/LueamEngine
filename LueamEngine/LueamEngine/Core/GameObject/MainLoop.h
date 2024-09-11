#pragma once
#include <vector>
#include "Core/GameObject/GameObject.h"
#include "Core/Graphics/Renderer.h"

class MainLoop
{
	std::vector<GameObject> object_list;
	std::vector<Window> window_list;

	bool quitting = false;
	GLFWwindow* main_window;

public :
	Renderer* renderer;

	void run();
	Window* create_window(Vector2 size);
	bool is_quitting();
	void quit();
};

