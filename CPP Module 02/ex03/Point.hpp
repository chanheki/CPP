#include "bsp.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point( void );
	~Point( void );
	Point(int const x, int const y);
	Point(float const x, float const y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	Fixed getX( void ) const;
	Fixed getY( void ) const;
};
