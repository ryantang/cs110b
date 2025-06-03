#include "Elf.h"
#include "Creature.h"
#include <iostream>

namespace cs_creature {

    Elf::Elf() : Creature() {
    }






    Elf::Elf(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {
    }






    string Elf::getSpecies() const {
        return "elf";
    }






    int Elf::getDamage() const {
        int damage;
        damage = Creature::getDamage();
        std::cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        if (rand() % 100 * 0.01 < MAGICAL_ATTACK_PROBABILITY) {
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
            damage *= MAGICAL_ATTACK_MULTIPLIER;
        }
        return damage;
    }

}