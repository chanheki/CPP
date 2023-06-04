#include "bsp.hpp"

Point::Point( void ) : x(0), y(0) {}

Point::~Point( void ) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::Point(int const x, int const y) : x(x), y(y) {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point& Point::operator=(const Point& other) {
	if (this != &other) {
		const_cast<Fixed&>(x) = other.x;
		const_cast<Fixed&>(y) = other.y;
	}
	return *this;
}

Fixed Point::getX( void ) const {
	return this->x;
}

Fixed Point::getY( void ) const {
	return this->y;
}
