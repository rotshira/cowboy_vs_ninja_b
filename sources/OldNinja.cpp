#include <stdio.h>
#include <iostream>

#include "OldNinja.hpp"


using namespace std;
namespace ariel
{
//constructor
OldNinja::OldNinja(string name_,Point location_) : Ninja(name_,location_)
{
this->speed = 8;
this-> hits=150;
}

}