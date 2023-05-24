#include "Character.hpp"
#include "Team.hpp"
#include <stdio.h>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

namespace ariel {

    // Constructor and Destructor
    Team::Team(Character* leader) : leader(leader)
    {
        this->add(leader);
    }

    Team::~Team(){
        for(std::vector<Character*>::iterator i=members.begin(); i != members.end(); i++) {
            delete *i;
        }
    } 

    // Public member functions

    const std::vector<Character*>& Team::getMembers() const 
    {
        return members;
    }

    std::vector<Character*>& Team::getMembers() 
    {
    return members;
    }

    void Team::add(Character* member) 
    {
        if (member->get_in_group() )
        {
            throw runtime_error("This member already a member");
        }
        else if (members.size() >= 10)
        {
            throw runtime_error("no more places in the group");
        }
        else
        {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member))
            {
                members.insert(members.begin(), member);
            }
            else
            {
                members.push_back(member);
            }
            member->set_in_group(true);
        }
    }

    void Team::addToMembers(Character* member) 
    {
        members.push_back(member);
        member->set_in_group(true);
    }

    Character* Team::find_leader(const Point& location) const {
        double minDistance = std::numeric_limits<double>::max();
        Character* closest = nullptr;

        for (Character* member : members) {
            if (member->isAlive() && member != leader) {
                double distance = member->getLocation().distance(location);
                if (distance < minDistance) {
                    minDistance = distance;
                    closest = member;
                }
            }
        }

        return closest;
    }

    Character* Team::findClosestEnemy(const Character* enemy) const 
    {
        double minDistance = std::numeric_limits<double>::max();
        Character* victim = nullptr;

        for (Character* member : members) {
            if (member->isAlive() && member != enemy) {
                double distance = member->distance(enemy);
                if (distance < minDistance) {
                    minDistance = distance;
                    victim = member;
                }
            }
        }

        return victim;
    }

    void Team::attack(const Team* enemy)
{
    if (enemy == nullptr)
    {
        throw std::invalid_argument("Enemy is nullptr");
    }
    if (!enemy->stillAlive())
    {
        throw std::runtime_error("Cannot attack a dead team");
    }

    // Check if the leader is alive, if not, find a new leader
    if (!leader->isAlive())
    {
        // Find a new leader as the closest living fighter to the previous leader
        Point lastLeaderLocation = leader->getLocation();
        leader = find_leader(lastLeaderLocation);

        // If no living leader could be found, throw an error
        if (!leader->isAlive())
        {
            throw std::runtime_error("No living leader could be found");
        }
    }

    // Find the closest enemy to the leader
    Character* victim = enemy->findClosestEnemy(leader);

    // Iterate over each member in the team
    for (Character* member : members)
    {
        if (member->isAlive())
        {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
            if (cowboy != nullptr)
            {
                // If the member is a cowboy, check if they have bullets and shoot the victim
                if (cowboy->hasboolets())
                {
                    cowboy->shoot(victim);
                }
                else
                {
                    cowboy->reload();
                }
            }
            else
            {
                Ninja* ninja = dynamic_cast<Ninja*>(member);
                if (ninja != nullptr)
                {
                    // If the member is a ninja, check if the victim is within slashing range
                    // If yes, slash the victim; otherwise, move towards the victim
                    if (ninja->distance(victim) <= 1)
                    {
                        ninja->slash(victim);
                    }
                    else
                    {
                        ninja->move(victim);
                    }
                }
            }
            
            // Check if the victim is still alive after the attack
            // If not, find the next closest enemy to the leader
            if (!victim->isAlive())
            {
                victim = enemy->findClosestEnemy(leader);

                // If no more enemies are left, break out of the loop
                if (victim == nullptr)
                {
                    break;
                }
            }
        }
    }
}


    int Team::stillAlive() const
    {
        int aliveCount = 0;
        for (const auto& member : members)
        {
            if (member->isAlive())
            {
                aliveCount++;
            }
        }
        return aliveCount;
    }

    void Team::print()
    {
        for (Character* member : members)
        {
            cout << member->print() << endl;
        }
    }

} // namespace ariel
