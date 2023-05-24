#pragma once
#include <stdio.h>
#include <vector>
#include <stdexcept>
#include <cmath>

#include "Team.hpp"



namespace ariel
{
    class Team2 : public Team
    {
    public:
        using Team::Team; 

        void add(Character* member);
    };
}
