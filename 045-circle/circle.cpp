#include "circle.hpp"
#include <cmath>
#include <algorithm>

Circle::Circle(const Point& p, double r) : center(p), radius(r) {}

void Circle::move(double dx, double dy) {
    center.move(dx, dy);
}

double Circle::intersectionArea(const Circle& otherCircle) const {
    double distance = center.distanceFrom(otherCircle.center);
    if (distance >= (radius + otherCircle.radius)) {
        return 0.0;
    } else if (distance <= fabs(radius - otherCircle.radius)) {
        double smallerRadius = std::min(radius, otherCircle.radius);
        return M_PI * smallerRadius * smallerRadius;
    } else {
        double r1 = radius;
        double r2 = otherCircle.radius;
        double part1 = r1 * r1 * acos((distance * distance + r1 * r1 - r2 * r2) / (2 * distance * r1));
        double part2 = r2 * r2 * acos((distance * distance + r2 * r2 - r1 * r1) / (2 * distance * r2));
        double part3 = 0.5 * sqrt((-distance + r1 + r2) * (distance + r1 - r2) * (distance - r1 + r2) * (distance + r1 + r2));
        return part1 + part2 - part3;
    }
}
