#include "Creature.h"
#include <iostream>
using namespace std;

namespace cs_creature {

    Creature::Creature() : strength(DEFAULT_STRENGTH), hitpoints(DEFAULT_HITPOINTS) {
    }






    Creature::Creature(int newStrength, int newHitpoints) : strength(newStrength), hitpoints(newHitpoints) {
    }






    string Creature::getSpecies() const {
        return "Creature";
    }






    int Creature::getStrength() const {
        return strength;
    }





    int Creature::getHitpoints() const {
        return hitpoints;
    }






    int Creature::getDamage() const {
        int damage;
        damage = (rand() % strength) + 1;
        return damage;
    }






    void Creature::setStrength(int newStrength) {
        strength = newStrength;
    }






    void Creature::setHitpoints(int newHitpoints) {
        hitpoints = newHitpoints;
    }

}