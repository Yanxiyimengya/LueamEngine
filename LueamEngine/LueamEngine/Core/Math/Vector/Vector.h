#pragma once

class Vector2
{
public :
	double x = 0.0f;
	double y = 0.0f;

	Vector2();
	Vector2(double value_x, double value_y);
	Vector2(const Vector2& vector);

	double dot(Vector2& vec);
	double cross(Vector2& vec);

	Vector2 operator+(Vector2& other);
	Vector2 operator-(Vector2& other);
};
