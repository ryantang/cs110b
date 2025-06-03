/*
This is a magic date calculator. A date is considered magic if the month 
multiplied by the day equals the two-digit year. Input from the user is a date
in the form of MM/DD/YY, though the "/" can be replaced with any non-numeric character.

The output shows whether the date is magic or not.
*/

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