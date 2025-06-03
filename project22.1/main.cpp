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

int main() {
    
    // Comment this line out before submitting to zyBooks!
    // srand(static_cast<unsigned>(time(nullptr)));  
    
    
    Human h1;

    assert(h1.getStrength() == 10);
    assert(h1.getHitpoints() == 10);
    assert(h1.getSpecies() == "human");

    Human h(20, 30);
    assert(h.getStrength() == 20);
    assert(h.getHitpoints() == 30);
    assert(h.getSpecies() == "human");

    h.setHitpoints(23);
    h.setStrength(17);

    assert(h.getStrength() == 17);
    assert(h.getHitpoints() == 23);

    // Elf e1;
    // assert(e1.getStrength() == 10);
    // assert(e1.getHitpoints() == 10);
    // assert(e1.getSpecies() == "elf");

    // Elf e(40, 50);
    // assert(e.getStrength() == 40);
    // assert(e.getHitpoints() == 50);
    // assert(e.getSpecies() == "elf");

    // Cyberdemon c1;
    // assert(c1.getStrength() == 10);
    // assert(c1.getHitpoints() == 10);
    // assert(c1.getSpecies() == "cyberdemon");

    // Cyberdemon c(60, 70);
    // assert(c.getStrength() == 60);
    // assert(c.getHitpoints() == 70);
    // assert(c.getSpecies() == "cyberdemon");

    // Balrog b1;
    // assert(b1.getStrength() == 10);
    // assert(b1.getHitpoints() == 10);
    // assert(b1.getSpecies() == "balrog");

    // Balrog b(80, 90);
    // assert(b.getStrength() == 80);
    // assert(b.getHitpoints() == 90);
    // assert(b.getSpecies() == "balrog");


    // Human h1;
    // Elf e1;
    // Cyberdemon c1;
    // Balrog b1;
    
    // Human h(20, 30);
    // Elf e(40, 50);
    // Cyberdemon c(60, 70);
    // Balrog b(80, 90);

    
    // cout << "default human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
    // cout << "default elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
    // cout << "default cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
    // cout << "default balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
    // cout << "non-default human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
    // cout << "non-default elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
    // cout << "non-default cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
    // cout << "non-default balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
    // cout << endl << endl;

    // cout << "Examples of " << h.getSpecies() << " damage: " << endl;
    // for (int i = 0; i < 10; i++){
    //     int damage = h.getDamage();
    //     cout << " Total damage = " << damage << endl;
    //     cout << endl;
    // }
    // cout << endl;
    
    
    // cout << "Examples of " << e.getSpecies() << " damage: " << endl;
    // for (int i = 0; i < 10; i++){
    //     int damage = e.getDamage();
    //     cout << " Total damage = " << damage << endl;
    //     cout << endl;
    // }
    // cout << endl;
    
    
    
    // cout << "Examples of " << c.getSpecies() << " damage: " << endl;
    // for (int i = 0; i < 10; i++){
    //     int damage = c.getDamage();
    //     cout << " Total damage = " << damage << endl;
    //     cout << endl;
    // }
    // cout << endl;
    
    
    
    // cout << "Examples of " << b.getSpecies() << " damage: " << endl;
    // for (int i = 0; i < 10; i++){
    //     int damage = b.getDamage();
    //     cout << " Total damage = " << damage << endl;
    //     cout << endl;
    // }
    // cout << endl;
}