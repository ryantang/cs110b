#include "Human.h"
#include <iostream>
using namespace cs_creature;

namespace cs_creature {

    Human::Human() : Creature() {
    }







    Human::Human(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {
    }







    string Human::getSpecies() const {
        return "human";
    }







    int Human::getDamage() const {
        int damage = Creature::getDamage();
        std::cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }

}

