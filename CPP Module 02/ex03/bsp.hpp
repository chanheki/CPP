#ifndef BSP_HPP
# define BSP_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::string result(Point const a, Point const b, Point const c, Point const point);

#endif
