#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include "Ninja.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel {

    // Constructors

    Ninja::Ninja(const std::string& name, const Point& location, int life, int speed)
        : Character(location, life, name), speed(speed) {
    }

    Ninja::Ninja(Ninja& other)
        : Character(other), speed(other.speed) {
    }

    // Functions

    void Ninja::move(Character* enemy) {
        checkEnemyAlive(enemy);
        setLocation(getLocation().moveTowards(getLocation(), enemy->getLocation(), speed));
    }

    void Ninja::slash(Character* enemy) {
        checkEnemyAlive(enemy);

        if (this == enemy) {
            throw runtime_error("No self harm");
        }

        if (!isAlive()) {
            throw runtime_error("Attacking method of a dead character");
        }

        if (isAlive() && getLocation().distance(enemy->getLocation()) <= 1.0) {
            enemy->hit(40);
        }
    }

    void Ninja::checkEnemyAlive(Character* enemy) {
        if (!enemy->isAlive()) {
            throw runtime_error("The enemy is dead");
        }
    }

    string Ninja::print() {
        string locationString = getLocationString();
        return "(N) Name: " + getName() + ", Location: " + locationString + ", Hit: " + to_string(life);
    }

}  // namespace ariel
