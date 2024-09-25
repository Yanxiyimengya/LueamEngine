#include "Color.h"

Color::Color() = default;

Color::Color(float r_value, float g_value, float b_value)
{
	this->r = r_value;
	this->g = g_value;
	this->b = b_value;
	this->a = 1.0f;
}

Color::Color(float r_value, float g_value, float b_value, float a_value)
{
	this->r = r_value;
	this->g = g_value;
	this->b = b_value;
	this->a = a_value;
}
