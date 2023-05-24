#include <iostream>
#include "OldNinja.hpp"

namespace ariel
{
//oldninja

   OldNinja::OldNinja(const std::string &name, const Point &location)
    : Ninja(name, location, 150, 8)
{
}

OldNinja::OldNinja(OldNinja &other)
    : Ninja(other)
{
}


}