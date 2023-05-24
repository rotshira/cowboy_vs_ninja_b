#include "Team2.hpp"

namespace ariel
{
    void Team2::add(Character* member)
    {
         if (getMembers().size() >= 10)
    {
        throw std::runtime_error("Maximum number of teammates exceeded.");
    }
    if (member->get_in_group()) // Use the public getter function instead of accessing the private member directly
    {
        throw std::runtime_error(member->getName() + " is already in a team.");
    }

    addToMembers(member);
    }
}
