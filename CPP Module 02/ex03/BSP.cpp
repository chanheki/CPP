#include "bsp.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

    d1 = (point.getX() - a.getX()) * (b.getY() - a.getY()) - (b.getX() - a.getX()) * (point.getY() - a.getY());
    d2 = (point.getX() - b.getX()) * (c.getY() - b.getY()) - (c.getX() - b.getX()) * (point.getY() - b.getY());
    d3 = (point.getX() - c.getX()) * (a.getY() - c.getY()) - (a.getX() - c.getX()) * (point.getY() - c.getY());

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    if (d1 == 0 || d2 == 0 || d3 == 0)
        return false;
    return !(has_neg && has_pos);
}

std::string result(Point const a, Point const b, Point const c, Point const point) {
    if (bsp(a, b, c, point))
        return "inside";
    else
        return "outside";
}
