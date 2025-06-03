/* 
This program is a number guessing game prompts the user to think of a number between 1 and 100.
The program then guesses a number, prompts the user to enter 'l' if the number is lower, 'h' if the number is higher, 
or 'c' if the number is correct. Upon completion, the program asks the user if they would like to play again.
*/

#include <iostream>
using namespace std;

const int LOWER_LIMIT = 1;
const int UPPER_LIMIT = 100;

void playOneGame();
void getUserResponseToGuess(int guess, char& result);
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

/* playOneGame() is the main function that runs the game. 
It takes no parameters and has no return value.
playOneGame() prompts the user to think of a number between 1 and 100.
It then uses a binary search algorithm to guess the number. */
void playOneGame() {
    int low = LOWER_LIMIT;
    int high = UPPER_LIMIT;
    char result = '\0';
    cout << "Think of a number between " << LOWER_LIMIT << " and " << UPPER_LIMIT << "." << endl;

    while (result != 'c') {
        int mid = getMidpoint(low, high);
        
        cout << "low: " << low << " high: " << high << " mid: " << mid << endl;
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

//getUserResponseToGuess takes a guess variable (int) and a reference to a result variable (char). 
//It prompts the user to enter 'l', 'h', or 'c' and stores the response in the char variable.
void getUserResponseToGuess(int guess, char& result)
{
    cout << "My guess is " << guess << ". Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
    cin >> result;
}

//getMidpoint takes two integers, low and high, and returns the midpoint of the two numbers.
//when the midpoint is calculated, it is rounded down to the nearest whole number.
int getMidpoint(int low, int high)
{
    return (low + high) / 2;
}
