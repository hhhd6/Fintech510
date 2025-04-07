
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "point.hpp"
#include <cmath>

class Circle {
private:
    Point center;
    const double radius;

public:
    Circle(const Point& p, double r);
    void move(double dx, double dy);
    double intersectionArea(const Circle& otherCircle) const;
};

#endif
