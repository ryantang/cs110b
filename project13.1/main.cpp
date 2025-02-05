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
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);
void runTests();
vector<int> countCards(const int hand[]);

int main() {
    int hand[HAND_SIZE];
    runTests();

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

bool containsPair(const int hand[]) {
    vector<int> cardsByValues = countCards(hand);
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (cardsByValues[i] == 2) {
            return true;
        }
    }
    return false;
}



bool containsTwoPair(const int hand[]) {
    vector<int> cardsByValues = countCards(hand);
    int pairs = 0;
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (cardsByValues[i] == 2) {
            pairs++;
        }
    }
    return pairs == 2;
}

bool containsThreeOfaKind(const int hand[]) {
    vector<int> cardsByValues = countCards(hand);
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (cardsByValues[i] == 3) {
            return true;
        }
    }
    return false;
}

bool containsStraight(const int hand[]) {
    vector<int> cardsByValues = countCards(hand);
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM - 4; i++) {
        if (cardsByValues[i] == 1 && cardsByValues[i + 1] == 1 && 
            cardsByValues[i + 2] == 1 && cardsByValues[i + 3] == 1 && 
            cardsByValues[i + 4] == 1) {
            return true;
        }
    }
    return false;
}

bool containsFullHouse(const int hand[]) {
    return containsPair(hand) && containsThreeOfaKind(hand);
}

bool containsFourOfaKind(const int hand[]) {
    vector<int> cardsByValues = countCards(hand);
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (cardsByValues[i] >= 4) {
            return true;
        }
    }
    return false;
}

vector<int> countCards(const int hand[]) {
    // Create a vector to store the number of cards with each value, 
    // using the value as the index. 
    // For example, if hand is {2, 3, 3, 5, 5},
    // cardsByValues[2] = 1 (there is one two), 
    // cardsByValues[3] = 2 (there are two three's),
    // cardsByValues[5] = 2 (there are two fives).
    vector<int> cardsByValues(HIGHEST_NUM + 1);
    for (int i = 0; i < HAND_SIZE; i++) {
        cardsByValues[hand[i]]++;
    }
    return cardsByValues;
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
    // assert(containsStraight(sixCardsStraight)); // Don't know how to override HAND_SIZE to 6

    assert(!containsFullHouse(pair));
    assert(!containsFullHouse(twoPair));
    assert(containsFullHouse(fullHouse));
    assert(!containsFullHouse(threeOfAKind));

    assert(!containsFourOfaKind(fullHouse));
    assert(containsFourOfaKind(fourOfAKind));
    assert(containsFourOfaKind(fiveOfAKind));
}


