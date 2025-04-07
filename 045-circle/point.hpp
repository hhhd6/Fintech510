#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>

class Point {
private:
    double x, y;

public:
    Point(double x_val = 0.0, double y_val = 0.0);
    void move(double dx, double dy);
    double distanceFrom(const Point& other) const;

    // Getter methods for x and y
    double getX() const { return x; }
    double getY() const { return y; }
};

#endif
