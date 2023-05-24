#pragma once

#include <stdio.h>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

using namespace std;

namespace ariel {

    class Team {
    private:
        Character* leader;
        std::vector<Character*> members;

    public:
        // Constructor
        Team(Character* leader);

        // Destructor
        ~Team();

        // Member functions
        void addToMembers(Character* member);
        const std::vector<Character*>& getMembers() const;
        std::vector<Character*>& getMembers();
        Character* find_leader(const Point& location) const;
        Character* findClosestEnemy(const Character* attacker) const;
        void add(Character* enemy);
        void attack(const Team* enemy);
        int stillAlive() const;
        void print();
    };

}  // namespace ariel
