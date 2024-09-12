#pragma once
//#include "glad/glad.h"
#include "Core/Math/Vector/Vector.h"
#include <vector>

enum Format {
	POSITION_2D,
	POSITION_3D,
	COLOR,
	TEXCOORD
};

class VertexBufferFormat
{
public:
	unsigned int vertex_size = 0;
	std::vector<Format> attributes;
	~VertexBufferFormat();

	void begin();
	void end();
	void add_position_2d();
	void add_position_3d();
	void add_color();
	void add_uv();
};