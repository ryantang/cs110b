#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "Human.h"
#include "Elf.h"
#include "Cyberdemon.h"
#include "Demon.h"
#include "Balrog.h"

using namespace std;
using namespace cs_creature;

const int NUM_CREATURES = 4;
const int ELF_DEFAULT_STRENGTH = 24;
const int BALROG_DEFAULT_STRENGTH = 10;
const int HUMAN_DEFAULT_STRENGTH = 100;
const int CYBERDEMON_DEFAULT_STRENGTH = 50;
const int DEFAULT_HITPOINTS = 50;

void battle(Creature &Creature1, Creature &Creature2);
void battle1Round(Creature &Creature1, Creature &Creature2, int &creature1Life, int &creature2Life);
void declareWinner(Creature& Creature1, Creature& Creature2, int life1, int life2);


int main() {
    // srand(static_cast<unsigned>(time(nullptr)));

    Elf e(ELF_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
    Balrog b(BALROG_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
    Human h(HUMAN_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
    Cyberdemon c(CYBERDEMON_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
    Creature* creatures[] = {&b, &e, &c, &h};
    
    for (int i = 0; i < NUM_CREATURES; i++) {
        for (int j = i + 1; j < NUM_CREATURES; j++) {
            battle(*creatures[i], *creatures[j]);
        }
    }
}







void battle(Creature& Creature1, Creature& Creature2) {
    cout << "*****  Battle between the " << Creature1.getSpecies() << " and the " 
        << Creature2.getSpecies() << "!!  ******" << endl;
    cout << endl;

    int creature1Life = Creature1.getHitpoints();
    int creature2Life = Creature2.getHitpoints();

    while(creature1Life > 0 && creature2Life > 0) {
        battle1Round(Creature1, Creature2, creature1Life, creature2Life);
    }

    declareWinner(Creature1, Creature2, creature1Life, creature2Life);
}







void battle1Round(Creature &Creature1, Creature &Creature2, int &creature1Life, int &creature2Life) {
    creature2Life -= Creature1.getDamage();
    creature1Life -= Creature2.getDamage();
    cout << "The " << Creature1.getSpecies() << " has " << creature1Life << " hitpoints." << endl;
    cout << "The " << Creature2.getSpecies() << " has " << creature2Life << " hitpoints." << endl;
    cout << endl;
}







void declareWinner(Creature& Creature1, Creature& Creature2, int life1, int life2) {
    if (life1 <= 0 && life2 <= 0) {
        cout << "The battle results in a tie!" << endl;
    } else if (life1 <= 0) {
        cout << "The " << Creature2.getSpecies() << " wins!" << endl;
    } else {
        cout << "The " << Creature1.getSpecies() << " wins!" << endl;
    }
    cout << endl;
    cout << endl;
}
