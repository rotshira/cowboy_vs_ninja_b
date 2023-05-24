#include <iostream>
#include "YoungNinja.hpp"

using namespace std;

namespace ariel
{
    // Default constructor
    YoungNinja::YoungNinja(const std::string &name, const Point &location)
    : Ninja(name, location, 100, 14)
{
}

YoungNinja::YoungNinja(YoungNinja &other)
    : Ninja(other)
{
}

}