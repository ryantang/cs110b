#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

const int HAND_SIZE = 5;
const int LOWEST_NUM = 2;
const int HIGHEST_NUM = 9;

bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
void countCards(std::__1::vector<int> &cardsByValues, const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);
void runTests();

int main() {
    runTests();
}

bool containsPair(const int hand[]) {
    vector<int> cardsByValues(HIGHEST_NUM + 1);
    countCards(cardsByValues, hand);
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (cardsByValues[i] == 2) {
            return true;
        }
    }
    return false;
}

bool containsTwoPair(const int hand[]) {
    vector<int> cardsByValues(HIGHEST_NUM + 1);
    int pairs = 0;
    countCards(cardsByValues, hand);
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (cardsByValues[i] == 2) {
            pairs++;
        }
    }
    return pairs == 2;
}

bool containsThreeOfaKind(const int hand[]) {
    vector<int> cardsByValues(HIGHEST_NUM + 1);
    countCards(cardsByValues, hand);
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (cardsByValues[i] == 3) {
            return true;
        }
    }
    return false;
}

void countCards(vector<int> &cardsByValues, const int hand[]) {
    // Create a vector to store the number of cards with each value, 
    // using the value as the index. 
    // For example, if hand is {2, 3, 3, 5, 5},
    // cardsByValues[2] = 1 (there is one two), 
    // cardsByValues[3] = 2 (there are two three's),
    // cardsByValues[5] = 2 (there are two fives).
    for (int i = 0; i < HAND_SIZE; i++) {
        cardsByValues[hand[i]]++;
    }
}

void runTests() {
    int highCard[5] = {6, 2, 3, 4, 9};
    int pair[5] = {8, 5, 3, 2, 8};
    int twoPair[5] = {7, 5, 3, 7, 5};
    int threeOfAKind[5] = {3, 5, 3, 3, 8};
    int straight[5] = {2, 3, 4, 5, 6};
    int fullHouse[5] = {3, 3, 3, 5, 5};
    int fourOfAKind[5] = {3, 3, 3, 3, 5};
    int fiveOfAKind[5] = {3, 3, 3, 3, 3};
    // int outOfOrderStraight[5] = {8, 5, 4, 6, 7};

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
}


