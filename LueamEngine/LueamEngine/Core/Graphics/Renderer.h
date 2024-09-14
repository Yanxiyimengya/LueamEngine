#pragma once
#include <vector>
#include "Core/Graphics/VertexBuffer.h"
#include "Core/Window/Window.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void draw_line(Vector2 start, Vector2 end);
	void draw_buffer(VertexBuffer &buffer);
};

