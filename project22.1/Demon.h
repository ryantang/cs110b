#ifndef DEMON_H
#define DEMON_H
#include "Creature.h"

namespace cs_creature{
    class Demon : public Creature {
        public:
            Demon();
            Demon(int newStrength, int newHitpoints);
            string getSpecies() const;
            int getDamage() const;

        private:
            static constexpr double DEMONIC_ATTACK_PROBABILITY = 0.25;
            static const int DEMONIC_BONUS_DAMAGE = 50;
    };
}
#endif