#ifndef BSP_HPP
# define BSP_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"

class BSP {

private:
public:
	BSP(void);
	BSP(BSP const &src);
	~BSP(void);
	BSP &operator=(BSP const &rhs);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
std::string result(Point const a, Point const b, Point const c, Point const point);

#endif
