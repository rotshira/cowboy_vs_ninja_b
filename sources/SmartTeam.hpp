#pragma once
#include <string>
#include "Team.hpp"

namespace ariel {

    class SmartTeam : public Team {
    public:
        //constructor
        SmartTeam(Character* leader);

        ///function
        void add(Character* other);
        Character* getRandomAliveMember() const;
        void attack(Team* enemyTeam);
        ~SmartTeam();
    };

}
