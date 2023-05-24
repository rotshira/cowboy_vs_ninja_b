#pragma once

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cmath>

using namespace std;

namespace ariel {

    class Point {
    private:
        double x;
        double y;

    public:
        // Constructors
        Point(double newX, double newY);
        Point();

        // Member functions
        double get_x();
        double get_y();
        void set_x(double newX);
        void set_y(double newY);
        double distance(const Point& other) const;
        bool operator==(const Point& other) const;
        void print();
        static Point moveTowards(Point point1, Point point2, double dist);
    };

}  // namespace ariel
