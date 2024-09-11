#pragma once
#include "Core/Buffer.h"
#include "Core/Math/Vector/Vector.h"

class VertexBuffer : Buffer
{
	int buffer_size = 0;
	BUFFER_TYPE type = FIXED;
	void* buffer_ptr = nullptr;
	unsigned short seek_offset = 0;

	unsigned int gl_vertex_buffer_id = 0;
	unsigned int gl_vertex_array_id = 0;
	unsigned char gl_attribute_flag = 0;

public:

	VertexBuffer();

	void vertex_begin();
	void vertex_end();

	void add_vertex_position_2d(Vector2 vec);
	void add_vertex_position_3d();
	void add_vertex_color();
	void add_vertex_uv();

	unsigned int get_vao();
};


