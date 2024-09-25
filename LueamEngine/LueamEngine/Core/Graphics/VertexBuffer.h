#pragma once
#include <vector>
#include "Core/Buffer.h"
#include "Core/Graphics/Color.h"
#include "Core/Graphics/VertexBufferFormat.h"
#include "Core/Math/Vector/Vector.h"

class VertexBuffer
{
	std::vector<float> data;
public:

	VertexBuffer(VertexBufferFormat& fromat);
	VertexBufferFormat* fromat = nullptr;
	unsigned int buffer = 0;
	unsigned int vertex_count = 0;

	void begin();
	void end();
	void add_position_2d(Vector2 vec);
	void add_position_3d();
	void add_color(Color col);
	void add_uv();
};


