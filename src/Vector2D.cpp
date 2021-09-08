#include "Vector2D.hpp"
#include <cmath>

Vector2D::Vector2D() {
	x_ = 0;
	y_ = 0;
}

Vector2D::Vector2D(const int X, const int Y):x_(X), y_(Y){

}

double Vector2D::length() const {
	return sqrt(x_*x_ + y_*y_);
}

int Vector2D::get_x() const {
	return x_;
}

int Vector2D::get_y() const {
	return y_;
}

void Vector2D::set_x(const int new_x_){
	x_ = new_x_;
}


void Vector2D::set_y(const int new_y_){
	y_ = new_y_;
}

Vector2D Vector2D::operator+ (const Vector2D & other) const{
	Vector2D result(this->x_ + other.x_, this->y_ + other.y_);

	return result;
}

Vector2D & Vector2D::operator+= (const Vector2D & other){
	(*this) = (*this) + other;

	return (*this);
}


Vector2D Vector2D::operator - (const Vector2D & other) const{
	Vector2D result(this->x_ - other.x_, this->y_ - other.y_);

	return result;
}

Vector2D & Vector2D::operator -= (const Vector2D & other){
	(*this) = (*this) - other;

	return (*this);
}



Vector2D Vector2D::operator / (const double scalar) const {
	Vector2D result(this->x_ / scalar, this->y_ / scalar);

	return result;
}

Vector2D & Vector2D::operator /= (const double scalar){
	(*this) = (*this) / scalar;

	return (*this);
}


Vector2D operator * (const Vector2D & vector, const double scalar){
	Vector2D result(vector.x_ * scalar, vector.y_ * scalar);

	return result;
}

Vector2D operator * (const double scalar, const Vector2D & vector){
	return (vector * scalar);
}

Vector2D & Vector2D::operator *= (const double scalar){
	(*this) = (*this) * scalar;

	return (*this);
}


void Vector2D::normalize(){
	double len = length();

	if (len > 0){
		(*this) /= len;
	}
}
