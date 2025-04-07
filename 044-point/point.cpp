#include "point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(double x_value, double y_value) : x(x_value), y(y_value) {}

void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}

double Point::distanceFrom(const Point &p) const {
    double distance = std::sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    return distance;
}
