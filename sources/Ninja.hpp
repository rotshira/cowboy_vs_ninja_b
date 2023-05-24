#pragma once

#include "Character.hpp"

using namespace std;

namespace ariel {

    class Ninja : public Character {
    public:
        // Member variables
        int speed;
        int life;

        // Constructors
        Ninja(const std::string& name, const Point& location, int hitPoints, int speed);
        Ninja(Ninja& other);

        // Functions
        void move(Character* enemy);
        void slash(Character* enemy);
        void checkEnemyAlive(Character* enemy);
        string print() override;
    };
    
}  // namespace ariel
