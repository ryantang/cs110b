#include <iostream>
using namespace std;

int main() {
    int month;
    int day;
    int year;

    cout << "Enter a date in the format month/day/2-digit-year: ";
    cin >> month; // reads in the first integer of cin; stops at the first non-integer character
    cin.ignore(); // skips over the next character in cin
    cin >> day;
    cin.ignore();
    cin >> year;

    if (year == month * day) {
        cout << "That is a magic date!" << endl;
    } else {
        cout << "That is not a magic date!" << endl;
    }
    return 0;
}