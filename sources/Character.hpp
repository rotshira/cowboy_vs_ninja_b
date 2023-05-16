#pragma once
#include <stdio.h>
#include <fstream>
#include <cmath>
#include <string>
#include "Point.hpp"



namespace ariel
{
    
class Character
{
    private:
    string name;
    Point location;

public:
int hits;
// string name;
// Point location;

Character();
Character(string name_, Point location_);
Character(Point location_,int live_,string name_);
bool isAlive()const;
double distance(Character* player);
void hit(int n);
string getName();
Point getLocation();
string getLocationString();
bool operator==(const Character& other) const;
virtual string print();



};
}