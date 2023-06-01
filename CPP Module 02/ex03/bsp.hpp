#ifndef BSP_HPP
# define BSP_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"

class BSP
{
public:
	static bool	bsp( Point const a, Point const b, Point const c, Point const point);
};


#endif

