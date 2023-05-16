#pragma once

#include "Character.hpp"


using namespace std;

namespace ariel
{
    class Ninja : public Character
    {
    
    public:
        int speed;
        int hits;
        Ninja(string name_, Point P);
        Ninja();
        void move(Character* enemy);
        void slash(Character* enemy);
        string print() override;
    };
}