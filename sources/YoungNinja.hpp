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
class YoungNinja:public Ninja
{
private:

public:
YoungNinja(const std::string &name, const Point &location);
YoungNinja(YoungNinja &other);




};
}