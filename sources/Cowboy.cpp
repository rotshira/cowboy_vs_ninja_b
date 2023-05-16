#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include "Character.hpp"

#include "Cowboy.hpp"

using namespace std;
namespace ariel
{
//constructor
  Cowboy::Cowboy(std::string name_, Point l) : Character(name_, l)
{
    number_b = 6;
} 


void Cowboy::shoot(Character*  enemy)
{
    if (enemy == this) {
            throw std::runtime_error("Can't shoot self.");
        }
        if (!enemy->isAlive()) {
            throw std::runtime_error("Enemy is already dead.");
        }
        if (isAlive() && number_b > 0) {
            enemy->hit(10);
            number_b--;
        }
}

bool  Cowboy::hasboolets()
{
    if (!isAlive()) 
    {
        throw("The cowboy is dead");
    }
    return number_b > 0;
}

void Cowboy::reload()
{
 if (!isAlive())
    {
        throw("The cowboy is dead");
    }
    number_b += 6;
}

string Cowboy::print()
{
    string locationString = getLocationString(); // Call getLocationString() and store the result in a string variable
    return "(C) Name: " + getName() + ", Position: " + locationString + ", Hit: " + to_string(hits);
}

}

