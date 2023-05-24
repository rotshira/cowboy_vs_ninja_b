#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include "Character.hpp"
#include "Cowboy.hpp"

using namespace std;

namespace ariel {

    // Constructors

    Cowboy::Cowboy(const string& name, const Point& location)
        : Character(location, 110, name), number_b(6) {
    }

    Cowboy::Cowboy(Cowboy& other) : Character(other), number_b(other.number_b) {
    }

    // Functions

    void Cowboy::shoot(Character* enemy) {
        if (!isAlive()) {
            throw std::runtime_error("Dead-cannot shoot");
        }

        if (enemy == nullptr) {
            throw std::invalid_argument("Enemy character pointer -nullptr");
        }

        if (enemy == this) {
            throw std::runtime_error("Cannot shoot ineself");
        }

        if (!enemy->isAlive()) {
            throw std::runtime_error(" already dead");
        }

        if (!hasboolets()) {
            return;
        }

        enemy->hit(10);
        number_b -= 1;
    }

    bool Cowboy::hasboolets() {
        return number_b > 0;
    }

    void Cowboy::reload() {
        if (!isAlive()) {
            throw runtime_error("The cowboy is dead");
        }
        else {
            number_b += 6;
            if (number_b > 6) 
            {
                number_b = 6;
            }
        }
    }

    string Cowboy::print() {
        string locationString = getLocationString();
        return "(C) Name: " + getName() + ", Location: " + locationString + ", Hit: " + to_string(getLife());
    }

}  // namespace ariel
