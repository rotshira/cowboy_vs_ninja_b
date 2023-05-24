#pragma once

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cmath>

#include "Character.hpp"

using namespace std;

namespace ariel {

    class Cowboy : public Character {
    private:
        int number_b;

    public:
        // Constructors
        Cowboy(const string& name, const Point& location);
        Cowboy(Cowboy& other);

        // Functions
        void shoot(Character* enemy);
        bool hasboolets();
        void reload();
        string print() override;
    };
    }