#pragma once
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <string>
// #include "Point.hpp"
// #include "Character.hpp"
#include "Ninja.hpp"



using namespace std;
namespace ariel
{
class TrainedNinja: public Ninja 
    {
    public:
        TrainedNinja(string name_, Point p) ;

};
}