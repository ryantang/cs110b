#include "Cyberdemon.h"
#include "Demon.h"
#include "Creature.h"
#include <iostream>

namespace cs_creature {
    Cyberdemon::Cyberdemon() : Demon() {
    }






    Cyberdemon::Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints) {
    }






    string Cyberdemon::getSpecies() const {
        return "cyberdemon";
    }
}