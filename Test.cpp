#include <stdexcept>
#include <iostream>
#include <sstream>
#include "doctest.h"
#include <cmath>
#include "sources/Team.hpp"
using namespace std;
using namespace ariel;
using namespace doctest;


TEST_CASE("Point")
{
    Point a(35.1,21),b(3.5,6.5);
    CHECK_EQ(a.distance(b),b.distance(a));
     Point dist1(0, 0);
    Point dist2(0, 0);
    CHECK(dist1.distance(dist2) == 0); 
    Point p1(1, 2), p2(2,2), p3(3,2);

}

TEST_CASE("YoungNinja")
{
    Point p(0, 0);
    YoungNinja* young = new YoungNinja("shira", Point(5,5));
    CHECK_NOTHROW(YoungNinja("shira", p));
    CHECK(young->hits == 100);
    CHECK(young->speed == 14);
    CHECK(young->getLocation().get_x() == p.get_x());
    CHECK_EQ(young->getName(),"shira");
}

TEST_CASE("oldNinja")
{
    Point b(9.9,9.9);
    OldNinja *old = new OldNinja("shira", b);
    CHECK_NOTHROW(OldNinja *old2 = new OldNinja("shira", b));
    CHECK(old->hits == 150);
    CHECK(old->speed == 8);
    CHECK(old->getLocation().get_x() == b.get_x());
    CHECK(old->getLocation().get_y() == b.get_y());
}

TEST_CASE("TrainedNinja")
{
    Point b(4.9,0);
    TrainedNinja *Trained = new TrainedNinja("shira", b);
    CHECK_NOTHROW(TrainedNinja("shira", b));
    CHECK(Trained->hits == 120);
    CHECK(Trained->speed == 12);
}

        
TEST_CASE("cowboy")
{
    Point p(0, 0);
    Cowboy cowboy("shira", p);
    CHECK(cowboy.getName() == "shira");
    CHECK_NOTHROW(Cowboy *coboy2 = new Cowboy("shira", p));
    Cowboy *coboy3 = new Cowboy("shira1", p);
     OldNinja *old = new OldNinja("shira2", p);
     /////////////////////////////////////////
     coboy3->shoot(old);
     CHECK(coboy3->hasboolets()==true);
    for(int i=0; i<=4; i++)
        {
            coboy3->shoot(old);
        }
        CHECK(coboy3->hasboolets()==false);
        coboy3->reload();
        CHECK(coboy3->hasboolets()==true);
//////////////////////////////////////////
        int beforeSlash = old->hits;
        old->move(coboy3);
        old->slash(coboy3);
        int afterSlash = old ->hits;
        CHECK(beforeSlash==afterSlash);
}

TEST_CASE("Ninja")
{
    Point p(0, 0);
    Ninja Ninja("shira", p);
    CHECK(Ninja.getName() == "shira");
    CHECK_EQ(Ninja.speed,0);
    CHECK_EQ(Ninja.hits,0);
}

TEST_CASE("Team")
{
    Point point(0, 0);
    Cowboy c("shira", point);
    OldNinja old("rot", point);
    CHECK(c.isAlive());
    CHECK(old.isAlive());
    Team newTeam(&c);
    CHECK(newTeam.stillAlive() == 1);
    newTeam.add(&c);
    CHECK(newTeam.stillAlive() == 2);
}