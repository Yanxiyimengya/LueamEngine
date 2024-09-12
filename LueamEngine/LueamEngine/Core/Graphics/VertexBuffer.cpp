#include "VertexBuffer.h"
#include "glad/glad.h"

#include <iostream>

VertexBuffer::VertexBuffer(VertexBufferFormat& fromat)
{
	this->fromat = &fromat;
}

void VertexBuffer::begin()
{
	if (this->buffer != 0) {
		glDeleteBuffers(1, &this->buffer);
	}
	this->buffer = 0;
}

void VertexBuffer::end()
{
	this->buffer = 0;
	glGenBuffers(1, &this->buffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->buffer);

	unsigned int vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	unsigned char count = 0;
	unsigned char pointer = 0;
	for (const Format& vertex_fromat : this->fromat->attributes) {
		switch (vertex_fromat)
		{
		case TEXCOORD:
		case POSITION_2D:
			glVertexAttribPointer(count, 2, GL_FLOAT, GL_FALSE, 0, (void*)pointer);
			pointer += sizeof(float) * 2;
			break;
		case POSITION_3D:
			glVertexAttribPointer(count, 3, GL_FLOAT, GL_FALSE, 0, (void*)pointer);
			pointer += sizeof(float) * 3;
			break;
		case COLOR:
			glVertexAttribPointer(count, 4, GL_FLOAT, GL_FALSE, 0, (void*)pointer);
			pointer += sizeof(float) * 4;
			break;
		}
		glEnableVertexAttribArray(count);
		count++;
	}

	unsigned int vertex_size = this->data.size();
	unsigned int memory_size = vertex_size * sizeof(float);
	glBindVertexArray(vao);
 
	glBufferData(GL_ARRAY_BUFFER, memory_size, this->data.data(), GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void VertexBuffer::add_position_2d(Vector2 vec)
{
	this->data.push_back(vec.x);
	this->data.push_back(vec.y);
	vertex_count += 1;
}

void VertexBuffer::add_position_3d()
{
}

void VertexBuffer::add_color()
{
}

void VertexBuffer::add_uv()
{
}
