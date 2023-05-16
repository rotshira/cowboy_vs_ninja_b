#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Team.hpp"

#include "Ninja.hpp"
#include "YoungNinja.hpp"

using namespace std;
namespace ariel
{
//constructor
YoungNinja::YoungNinja(string name_, Point l) : Ninja(name_,l) {
    this->speed = 14;
    this->hits = 100;
}

}