#include "Demon.h"
#include "Creature.h"
#include <iostream>

namespace cs_creature{
    Demon::Demon() : Creature() {
    }






    Demon::Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints) {
    }




    
    string Demon::getSpecies() const {
        return "Demon";
    }






    int Demon::getDamage() const {
        int damage = Creature::getDamage();
        
        //demonic bonus damage
        if (rand() % 100 * 0.01 < DEMONIC_ATTACK_PROBABILITY) {
            damage = damage + DEMONIC_BONUS_DAMAGE;
            cout << "Demonic attack inflicts " << DEMONIC_BONUS_DAMAGE << " additional damage points!" << endl;
        }

        return damage;
    }
}