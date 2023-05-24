#pragma once
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <string>
#include "Ninja.hpp"



using namespace std;
namespace ariel
{
class TrainedNinja: public Ninja 
    {
    public:
    // TrainedNinja() ;
      TrainedNinja(const std::string &name, const Point &location);
      TrainedNinja(TrainedNinja &other);

       

};
}