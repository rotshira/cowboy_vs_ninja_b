#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include<limits>
#include <vector>
#include <typeinfo>

#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"

using namespace ariel;
using namespace std;
namespace ariel
{

//constructor
Character::Character()
{
this->location=Point();
this->hits = 0;
this->name = "";
}

Character::Character(const string name_,const Point location_)
{
this->name = name_;
this->location = location_;
this->hits=1;
}

Character::Character(const Point location_,int hits,const string name_): location(location_), hits(hits), name(name_)  
{

}

bool Character::isAlive() const
{
  return hits > 0;
}

double Character::distance(Character* player)
{
return location.distance(player->location);
}

void Character::hit(int n)
{
 hits -= n;
    if (hits < 0) 
    {
        hits = 0;
    }
}

string Character::getName()
{
return this->name;
}

Point Character::getLocation()
{
return this->location;
}

string Character::getLocationString()
{
    // Convert the x and y coordinates to strings
    string xCoord = to_string(location.get_x());
    string yCoord = to_string(location.get_y());

    // Construct the location string
    return "(" + xCoord + ", " + yCoord + ")";
}
bool Character::operator==(const Character& other) const
{
    // Compare characters based on their unique identifiers or other attributes
    return (name == other.name);
}

string Character::print() {
    if (!isAlive()) {
        return "(name: " + name + ")";
    } else {
        string locationString = getLocationString();
        return "name: " + name + "\nhits: " + to_string(hits) + "\nlocation: " + locationString + "\n";
    }
}



}