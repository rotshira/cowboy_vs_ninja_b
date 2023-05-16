#pragma once
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cmath>


using namespace std;
namespace ariel
{
class Point
{
private:

 double x;
 double y;

public:
double get_x();
double get_y();
void set_x(double x_);
void set_y(double y_);
Point(double x_,double y_);
Point();
double distance(Point P);
void print();
static Point moveTowards(Point p1, Point p2, double dist);
};
}