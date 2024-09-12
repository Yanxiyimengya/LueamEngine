#include "glad/glad.h"
#include "VertexBufferFormat.h"

VertexBufferFormat::~VertexBufferFormat()
{
}

void VertexBufferFormat::begin()
{
	this->attributes.clear();

}

void VertexBufferFormat::end()
{
}

void VertexBufferFormat::add_position_2d()
{
	this->attributes.push_back(POSITION_2D);
	this->vertex_size += sizeof(float) * 2;
}

void VertexBufferFormat::add_position_3d()
{
	this->attributes.push_back(POSITION_3D);
	this->vertex_size += sizeof(float) * 3;
}

void VertexBufferFormat::add_color()
{
	this->attributes.push_back(COLOR);
	this->vertex_size += sizeof(float) * 4;
}

void VertexBufferFormat::add_uv()
{
	this->attributes.push_back(TEXCOORD);
	this->vertex_size += sizeof(float) * 2;
}
