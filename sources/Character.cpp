#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <vector>
#include <typeinfo>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"

using namespace ariel;
using namespace std;

namespace ariel {

    // Constructor
    Character::Character() {
        this->location = Point();
        this->life = 0;
        this->name = "";
        this->in_group = false;
    }

    // Constructor
    Character::Character(Character &other) noexcept
        : name(other.name), location(other.location), life(other.life)
    {
    }

    // Constructor
    Character::Character(const Point location_, int life, const string name_)
        : location(location_), life(life), name(name_), in_group(false) {
    }

    bool Character::isAlive() const {
        return life > 0;
    }

    double Character::distance(const Character* player) const {
        return location.distance(player->location);
    }

    void Character::hit(int damage) {
        if (damage < 0) {
            throw std::invalid_argument("Damage cannot be negative");
        }
        else {
            life -= damage;
        }
    }

    string Character::getName() {
        return this->name;
    }

    Point Character::getLocation() {
        return this->location;
    }

    void Character::setLocation(Point other) {
        location = other;
    }

    int Character::getLife() const {
        return life;
    }

    string Character::getLocationString() {
        // Convert the x and y coordinates to strings
        string xCoord = to_string(location.get_x());
        string yCoord = to_string(location.get_y());

        // Construct the location string
        return "(" + xCoord + ", " + yCoord + ")";
    }

    bool Character::operator==(const Character& other) const {
        // Compare characters based on their unique identifiers or other attributes
        return (name == other.name && location == other.location && life == other.life);
    }

    Character& Character::operator==(Character&& other) noexcept {
        this->name = other.name;
        this->location = other.location;
        this->life = other.life;
        return *this;
    }

    
    void Character::set_in_group(bool ingroup) {
        this->in_group = ingroup;
    }

    string Character::print() {
        if (!isAlive()) {
            return "(name: " + name + ")";
        }
        else {
            string locationString = getLocationString();
            return "name: " + name + "\nhits: " + to_string(life) + "\nlocation: " + locationString + "\n";
        }
    }
}  // namespace ariel
