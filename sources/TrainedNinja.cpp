

#include "Ninja.hpp"
#include "TrainedNinja.hpp"

using namespace std;
namespace ariel
{
//constructor
TrainedNinja::TrainedNinja(string name_,Point p):Ninja(name_,p)
{
this->speed = 12;
this-> hits=120;
}

}