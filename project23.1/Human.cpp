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
}

