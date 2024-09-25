#pragma once
class Color
{
public:
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 1;

	Color();
	Color(float r_value, float g_value, float b_value);
	Color(float r_value, float g_value, float b_value, float a_value);
};

