

#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Ninja.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel {
    Ninja::Ninja(string name_, Point P) : Character(name_, P) {
        // initialize speed and hits
        speed = 0;
        hits = 0;
    }

    Ninja::Ninja() : Character() {
        speed = 0;
        hits = 0;
    }

    void Ninja::move(Character * enemy) 
    {
     double distanceToEnemy = distance(enemy);
        double maxDistance = std::min(static_cast<double>(speed), distanceToEnemy);
        double dx = enemy->getLocation().get_x() - getLocation().get_x();
        double dy = enemy->getLocation().get_y() - getLocation().get_y();
        double norm = sqrt(dx * dx + dy * dy);
        dx /= norm;
    }

    void Ninja::slash(Character* enemy) {
        // implementation of slash function
        // ...
    }

   string Ninja::print()
{
    string locationString = getLocationString(); // Call getLocationString() and store the result in a string variable
    return "(N) Name: " + getName() + ", Position: " + locationString + ", Hit: " + to_string(hits);
}

}