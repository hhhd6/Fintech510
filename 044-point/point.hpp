#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>

class Point {
private:
    double x, y;

public:
    Point();

    Point(double x_val, double y_val);

    void move(double dx, double dy);

    double distanceFrom(const Point& other) const;
};

#endif
