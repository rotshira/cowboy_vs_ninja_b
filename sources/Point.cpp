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
namespace ariel
{
//constructor
Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(double _x,double _y)
{
    x = _x;
    y = _y;
}

double Point::get_x()
{
return x;
}

double Point::get_y()
{
return y;
}

void Point::set_x(double x_)
{
this->x = x_;
}

void Point::set_y(double y_)
{
this->y = y_;
}

double Point::distance(Point P)
{
    double dx = x - P.get_x();
    double dy = y - P.get_y();
    return sqrt(dx*dx + dy*dy);
}



void Point::print()
{
cout << "(" << x << "," << y << ")" << endl;
}



   Point Point::moveTowards(Point p1, Point p2, double dist)
{
     if (dist < 0) 
    {
        throw std::invalid_argument("Distance cannot be negative");
    }

    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double distance = sqrt(dx * dx + dy * dy);
    
    if (distance <= dist)
    {
        // The destination point is within or at the given distance
        return p2;
    }
    else
    {
        // Calculate the ratio of dx and dy to the distance
        double ratio = dist / distance;

        // Calculate the new point coordinates based on the ratio
        double newX = p1.x + ratio * dx;
        double newY = p1.y + ratio * dy;

        // Create and return the new point
        return Point(newX, newY);
    }
}
}


