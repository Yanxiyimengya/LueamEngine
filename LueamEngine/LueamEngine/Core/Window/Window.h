#pragma once
#include "Core/Math/Vector/Vector.h"
#include "Core/UString.h"
#include "Core/GameObject/GameObject.h"
#include "glfw/glfw3.h"

class Window : GameObject {

public:
	GLFWwindow* handle = nullptr;

	Vector2 position;
	Vector2 size;
	String title = "1";

	Window();
};