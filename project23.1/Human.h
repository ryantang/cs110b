#ifndef HUMAN_H
#define HUMAN_H
#include "Creature.h"

namespace cs_creature{
    class Human : public Creature {
        public:
            Human();
            Human(int newStrength, int newHitpoints);
            string getSpecies() const override;
    };
}
#endif