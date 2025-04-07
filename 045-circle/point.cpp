#include "point.hpp"

// Default constructor
Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {}

// Move the point by dx and dy
void Point::move(double dx, double dy) {
    x += dx;
    y += dy;
}

// Calculate the distance between two points
double Point::distanceFrom(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}
