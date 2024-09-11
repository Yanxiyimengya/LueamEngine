#include "Vector.h";

Vector2::Vector2() = default;

Vector2::Vector2(const Vector2& vector) 
{
	this->x = vector.x;
	this->y = vector.y;
};
Vector2::Vector2(double value_x, double value_y)
{
	this->x = value_x;
	this->y = value_y;
};

double Vector2::dot(Vector2& vec) {
	return this->x * vec.x + this->y * vec.y;
}

double Vector2::cross(Vector2& vec) {
	return this->x * vec.y + this->y * vec.x;
}

Vector2 Vector2::operator+(Vector2& other) {
	return Vector2(this->x + other.x, this->y + other.y);
};
Vector2 Vector2::operator-(Vector2& other) {
	return Vector2(this->x - other.x, this->y - other.y);
};