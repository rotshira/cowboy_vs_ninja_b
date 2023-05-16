#include "Character.hpp"
#include "Team.hpp"
#include <stdexcept>


using namespace std;
namespace ariel
{
//constructor
// Team::Team()
// {
//     this->leader = Character();
// }

Team::Team(Character *lead): leader(*lead) 
{
 for (Character* member : members) {
        if (member->getName() == lead->getName()) {
            throw std::runtime_error("Captain is already assigned to another team");
        }
    }
    members.push_back(lead);
}

  void Team::add(Character* member)
{
    if (members.size() >= 10)
    {
        throw std::runtime_error("Maximum number of teammates exceeded.");
    }

    for (Character* teamMember : members)
    {
        if (*teamMember == *member)
        {
            throw std::runtime_error(member->getName() + " is already in a team.");
        }
    }

    members.push_back(member);
}



void Team::attack(const Team *enemy)
{
;
}

int Team::stillAlive()
{

    return 0 ;
}


void Team::print()
{
;
}

Team::~Team()
{

}



}
