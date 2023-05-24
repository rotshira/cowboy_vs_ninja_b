#include "SmartTeam.hpp"
#include <stdexcept>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace ariel;

//constructor
SmartTeam::SmartTeam(Character* leader) : Team(leader) {}

//function
void SmartTeam::add(Character* other) {
    if (getMembers().size() >= 10) {
        throw runtime_error("There are no more places in the group");
    }
    getMembers().push_back(other);
    other->set_in_group(true); // Assuming the Character class has a setInGroup function
}
////////////////////////////////
Character* SmartTeam::getRandomAliveMember() const {
    vector<Character*> aliveMembers;
    for (Character* member : getMembers()) {
        if (member->isAlive()) {
            aliveMembers.push_back(member);
        }
    }
    if (aliveMembers.empty()) {
        return nullptr;
    }
    int randomIndex = rand() % static_cast<int>(aliveMembers.size());
    return aliveMembers[static_cast<size_t>(randomIndex)];
}
////////////////////////////////
void SmartTeam::attack(Team* enemy) {
    if (enemy == nullptr) {
        throw invalid_argument("Enemy team is nullptr");
    }
    srand(time(nullptr)); // Seed the random number generator

    while (stillAlive() > 0 && enemy->stillAlive() > 0) {
        Character* victim = getRandomAliveMember();

        for (Character* member : getMembers()) {
            if (member->isAlive()) {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
                if (cowboy != nullptr) {
                    if (cowboy->hasboolets()) {
                        cowboy->shoot(victim);
                    } else {
                        cowboy->reload();
                    }
                } else {
                    Ninja* ninja = dynamic_cast<Ninja*>(member);
                    if (ninja != nullptr) {
                        ninja->slash(victim);
                    }
                }

                if (!victim->isAlive()) {
                    victim = getRandomAliveMember();
                }
            }
        }
    }
}
/// /// ////////////////////////
SmartTeam::~SmartTeam() {
    // Destructor implementation if needed
}
