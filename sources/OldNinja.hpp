#pragma once
#include "Ninja.hpp"

using namespace std;
namespace ariel
{
class OldNinja:public Ninja
{

public:
OldNinja(const std::string &name, const Point &location);
OldNinja(OldNinja &other);

};
}