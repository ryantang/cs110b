/*
This is a variant of a blackjack game. The player receives two cards. 
They are prompted with the decision to draw another card until they are
ready to stop or they bust. The player wins if the sum of their cards reach 21 exactly.

The prompts to the player are to draw another card (y/n), or to play again (y/n).
Outputs include the cards drawn, the sum, and whether the player has won or busted.
*/


#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int firstCard;
    int secondCard;
    int sum;
    char keepPlaying = 'y';

    // srand(time(0));

    while (keepPlaying == 'y') {
        firstCard = rand() % 10 + 1;
        secondCard = rand() % 10 + 1;
        sum = firstCard + secondCard;

        cout << "First cards: " << firstCard << ", " << secondCard << endl;
        cout << "Total: " << sum << endl;
        cout << "Do you want another card (y/n)? ";

        char anotherCard;
        cin >> anotherCard;

        while (anotherCard == 'y' && sum < 21) {
            int newCard = rand() % 10 + 1;
            sum += newCard;
            cout << "Card: " << newCard << endl;
            cout << "Total: " << sum << endl;
            if (sum == 21) {
                cout << "Congratulations!" << endl;
            } else if (sum > 21) {
                cout << "Bust." << endl;
            } else {
                cout << "Do you want another card (y/n)? ";
                cin >> anotherCard;
            }
        }
        cout << "Would you like to play again (y/n)? ";
        cin >> keepPlaying;
    }
return 0;
}