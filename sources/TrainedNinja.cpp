

#include "Ninja.hpp"
#include "TrainedNinja.hpp"

using namespace std;
namespace ariel
{


 TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
    : Ninja(name, location, 120, 12)
{
}

TrainedNinja::TrainedNinja(TrainedNinja &other)
    : Ninja(other)
{
}

}