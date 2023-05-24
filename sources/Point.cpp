#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include "Point.hpp"

using namespace ariel;
using namespace std;

namespace ariel {

    // Constructors

    Point::Point() {
        this->x = 0;
        this->y = 0;
    }

    Point::Point(double _x, double _y) {
        x = _x;
        y = _y;
    }

    // Member functions

    double Point::get_x() {
        return x;
    }

    double Point::get_y() {
        return y;
    }

    void Point::set_x(double newX) {
        this->x = newX;
    }

    void Point::set_y(double newY) {
        this->y = newY;
    }

    double Point::distance(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    bool Point::operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    void Point::print() {
        cout << "(" << x << "," << y << ")" << endl;
    }

    Point Point::moveTowards(Point point1, Point point2, double dist) {
        if (dist < 0) {
            throw std::invalid_argument("Distance cannot be negative");
        }
        double dx = point2.x - point1.x;
        double dy = point2.y - point1.y;
        double distance = sqrt(dx * dx + dy * dy);
        if (distance <= dist) {
            // The destination point is within or at the given distance
            return point2;
        } else {
            // Calculate the ratio of dx and dy to the distance
            double ratio = dist / distance;

            // Calculate the new point coordinates based on the ratio
            double newX = point1.x + ratio * dx;
            double newY = point1.y + ratio * dy;

            // Create and return the new point
            return Point(newX, newY);
        }
    }

}  // namespace ariel
