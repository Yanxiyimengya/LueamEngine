#pragma once
#include <vector>
#include "Core/Graphics/VertexBuffer.h"
#include "Core/Window/Window.h"

class Renderer
{
public:
	Renderer();
	~Renderer();


	void draw_buffer(VertexBuffer &buffer);
};

