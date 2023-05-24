#pragma once

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include "Point.hpp"

namespace ariel
{
    class Character
    {
    private:
        string name;
        int life;
        Point location;
        bool in_group;
        
    public:
        // Constructors
        Character();
        Character(Character& other) noexcept;
        Character(Point location_, int live_, string name_);
        
        // Destructor
        virtual ~Character() = default;
        
        // Member functions
        bool get_in_group() const { return in_group;}
        bool isAlive() const;
        double distance(const Character* other) const;
        void hit(int n);
        string getName();
        Point getLocation();
        void setLocation(Point other);
        int getLife() const;
        string getLocationString();
        bool operator==(const Character& other) const;
        Character& operator==(Character&& other) noexcept;
        void set_in_group(bool in_group);
        virtual string print();
    };
}
