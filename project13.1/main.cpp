/* 
This program is a poker hand evaluator (minus face cards and suits). The user is prompted to enter 6 numeric cards,
and the program will determine the best hand that can be made from those cards. Possible hands are four of a kind, full house,
straight, three of a kind, two pair, pair, and high card.

The HAND_SIZE and card values are defined as constants, but will work if changed in the code.
*/

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

const int HAND_SIZE = 8;
const int LOWEST_NUM = 1;
const int HIGHEST_NUM = 13;

bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);
vector<int> countCards(const int hand[]);
int setsOf(int setSize, const int hand[]);
bool fiveCardsInaRowStartingat(int start, const int hand[]);
void runTests();

int main() {
    int hand[HAND_SIZE];

    cout << "Enter " << HAND_SIZE << " numeric cards, no face cards. Use " 
        << LOWEST_NUM << " - " << HIGHEST_NUM << "." << endl;
    for(int i = 0; i < HAND_SIZE; i++) {
        cout << "Card " << i + 1 << ": ";
        cin >> hand[i];
    }
    if (containsFourOfaKind(hand)) {
        cout << "Four of a kind!" << endl;
    } else if (containsFullHouse(hand)) {
        cout << "Full house!" << endl;
    } else if (containsStraight(hand)) {
        cout << "Straight!" << endl;
    } else if (containsThreeOfaKind(hand)) {
        cout << "Three of a Kind!" << endl;
    } else if (containsTwoPair(hand)) {
        cout << "Two Pair!" << endl;
    } else if (containsPair(hand)) {
        cout << "Pair!" << endl;
    } else {
        cout << "High card!" << endl;
    }
}






//containsPair() takes the integer array `hand[]` as a parameter. It returns true if there 
// is one or more pairs in the hand. Note that three of a kind, four of a kind, and so forth do not
// count as pairs.
bool containsPair(const int hand[]) {
    return setsOf(2, hand) > 0;
}






//containsTwoPair() takes the integer array `hand[]` as a parameter. It returns true if there are exactly 
//two pairs in the hand.
bool containsTwoPair(const int hand[]) {
    return setsOf(2, hand) == 2;
}






//containsThreeOfaKind() takes the integer array `hand[]` as a parameter. It returns true if there are at least
//one set of three cards with the same value in the hand. Four of a kind and five of a kind does not 
//count as three of a kind.
bool containsThreeOfaKind(const int hand[]) {
    return setsOf(3, hand) > 0;
}






//containsStraight() takes the integer array `hand[]` as a parameter. It returns true if there are five cards in a row.
//In the case the HAND_SIZE is higher than 5, the function will return true if any five cards are in a row.
//However, the function only returns true if all 5 cards fall within the maximum (HIGHEST_NUM) and 
//minimum (LOWEST_NUM) values.
bool containsStraight(const int hand[]) {
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM - 4; i++) {
        if (fiveCardsInaRowStartingat(i, hand)) {
            return true;
        }
    }
    return false;
}






//containsFullHouse() takes the integer array `hand[]` as a parameter. It returns true if there is a pair and a three of a 
//kind in the hand.
bool containsFullHouse(const int hand[]) {
    return containsPair(hand) && containsThreeOfaKind(hand);
}






//containsFourOfaKind() takes the integer array `hand[]` as a parameter. It returns true if there are four or more cards 
//with the same value.
bool containsFourOfaKind(const int hand[]) {
    vector<int> cardsByValues = countCards(hand);
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (cardsByValues[i] >= 4) {
            return true;
        }
    }
    return false;
}






//countCards() is a helper method that takes the integer array `hand[]` as a parameter. It returns a vector to store the number 
// of cards with each value using the value as the index. For example, if hand is {2, 3, 3, 5, 5},
// cardsByValues[2] = 1 (there is one two), 
// cardsByValues[3] = 2 (there are two three's),
// cardsByValues[5] = 2 (there are two fives).
vector<int> countCards(const int hand[]) {
    vector<int> cardsByValues(HIGHEST_NUM + 1);
    for (int i = 0; i < HAND_SIZE; i++) {
        cardsByValues[hand[i]]++;
    }
    return cardsByValues;
}






//setsOf() is a helper function that takes the integer `setSize` and the integer array `hand[]` as parameters.
//This function returns the number of sets of cards that match the `setSize` parameter.
//For example, if setSize is 2, the function will return the number of pairs in the hand.
//Likewise, if setSize is 3, the function will return the number of triplets in the hand.
int setsOf(int setSize, const int hand[]) {
    int count = 0;
    vector<int> cardsByValues = countCards(hand);
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (cardsByValues.at(i) == setSize){
            count++;
        }
    }
    return count;
}






//fiveCardsInaRowStartingat() is a helper function that takes the integer `start` and the integer array `hand[]` as parameters.
//`start` is the value of the first card in the sequence. The function returns true if there are five cards in a row.
bool fiveCardsInaRowStartingat(int start, const int hand[]) {
    vector<int> cardsByValues = countCards(hand);
    for (int i = 0; i < 5; i++) {
        if (cardsByValues.at(start + i) == 0) {
            return false;
        }
    }
    return true;
}






//runTests() is a helper function that runs tests on the functions in this program.
//It was useful to run regularly while coding, but I have removed runTests() from main() for the final version.
void runTests() {
    int highCard[5] = {6, 2, 3, 4, 9};
    int pair[5] = {8, 5, 3, 2, 8};
    int twoPair[5] = {7, 5, 3, 7, 5};
    int threeOfAKind[5] = {3, 5, 3, 3, 8};
    int straight[5] = {2, 3, 4, 5, 6};
    int fullHouse[5] = {3, 3, 3, 5, 5};
    int fourOfAKind[5] = {3, 3, 3, 3, 5};
    int fiveOfAKind[5] = {3, 3, 3, 3, 3};
    int outOfOrderStraight[5] = {8, 5, 4, 6, 7};
    // int sixCardsStraight[6] = {2, 4, 5, 6, 7, 8};

    assert(!containsPair(highCard));
    assert(containsPair(pair));
    assert(containsPair(twoPair));
    assert(!containsPair(threeOfAKind));
    assert(!containsPair(straight));

    assert(!containsTwoPair(highCard));
    assert(!containsTwoPair(pair));
    assert(containsTwoPair(twoPair));
    assert(!containsTwoPair(threeOfAKind));

    assert(!containsThreeOfaKind(highCard));
    assert(!containsThreeOfaKind(pair));
    assert(!containsThreeOfaKind(twoPair));
    assert(containsThreeOfaKind(threeOfAKind));
    assert(containsThreeOfaKind(fullHouse));
    assert(!containsThreeOfaKind(fourOfAKind));
    assert(!containsThreeOfaKind(fiveOfAKind));

    assert(!containsStraight(highCard));
    assert(!containsStraight(pair));
    assert(containsStraight(straight));
    assert(!containsStraight(fullHouse));
    assert(containsStraight(outOfOrderStraight));
    // assert(containsStraight(sixCardsStraight)); 
    
    assert(!containsFullHouse(pair));
    assert(!containsFullHouse(twoPair));
    assert(containsFullHouse(fullHouse));
    assert(!containsFullHouse(threeOfAKind));

    assert(!containsFourOfaKind(fullHouse));
    assert(containsFourOfaKind(fourOfAKind));
    assert(containsFourOfaKind(fiveOfAKind));
}


