/*Ryan Tang | 1/29/2025 | CS 110B with instructor David Harden | project4.5/main.cpp
*/

#include <iostream>
using namespace std;

const int LOWER_LIMIT = 1;
const int UPPER_LIMIT = 100;

void playOneGame();
void getUserResponseToGuess(int mid, char &response);
int getMidpoint(int low, int high);

int main() {
    char response;
    
    cout << "Ready to play (y/n)? ";
    cin >> response;
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
}

void playOneGame() {
    int low = LOWER_LIMIT;
    int high = UPPER_LIMIT;
    char result = '\0';
    cout << "Think of a number between " << LOWER_LIMIT << " and " << UPPER_LIMIT << "." << endl;

    while (result != 'c') {
        int mid = getMidpoint(low, high);

        getUserResponseToGuess(mid, result);
        if (result == 'l') {
            high = mid - 1;
        } else if (result == 'h') {
            low = mid + 1;
        } else if (result != 'c') {
            cout << "'" << result << "'" << " is not a valid response. Please enter 'l', 'h', or 'c'." << endl;
        }
    }
}

void getUserResponseToGuess(int mid, char& result)
{
    cout << "My guess is " << mid << ". Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
    cin >> result;
}

int getMidpoint(int low, int high)
{
    return (low + high) / 2;
}
