#include "VertexBuffer.h"
#include "glad/glad.h"

VertexBuffer::VertexBuffer() {
	glGenBuffers(1, (unsigned int*)this->gl_vertex_buffer_id);
	glGenVertexArrays(1, (unsigned int*)this->gl_vertex_array_id);
}

void VertexBuffer::vertex_begin() {
	glBindBuffer(GL_ARRAY_BUFFER, this->gl_vertex_buffer_id);
	glBindVertexArray(this->gl_vertex_array_id);
};

void VertexBuffer::vertex_end() {
	glBufferData(GL_ARRAY_BUFFER, this->buffer_size, this->buffer_ptr, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
};

void VertexBuffer::add_vertex_position_2d(Vector2 vec) { 
	write((float)vec.x);
	write((float)vec.y);
};

unsigned int VertexBuffer::get_vao() {
	return this->gl_vertex_array_id;
}