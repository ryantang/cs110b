#ifndef CREATURE_H
#define CREATURE_H
#include <string>
using namespace std;

namespace cs_creature {
    class Creature {
        private:
            int strength;
            int hitpoints;

            static const int DEFAULT_STRENGTH = 10;
            static const int DEFAULT_HITPOINTS = 10;
        public:
            Creature();
            Creature(int newStrength, int newHitpoints);
            int getDamage() const;
            
            int getStrength() const; 
            int getHitpoints() const;
            string getSpecies() const;
            
            void setStrength(int newStrength);
            void setHitpoints(int newStrength);
    };
}
















#endif