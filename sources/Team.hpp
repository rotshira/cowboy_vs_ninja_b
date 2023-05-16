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
namespace ariel
{
class Team
{
private:
Character& leader;
std::vector<Character*> members;

public:
// Team();
Team(Character *lead);

void add( Character* enemy);
void attack(const Team *enemy);
int stillAlive();
void print();
~Team();


};
}