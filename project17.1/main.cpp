/* 
    This program contains functions that manipulate C-style strings. 
    The functions include lastIndexOf, reverse, replace, isPalindrome, toupper, and numLetters.

    main() contains test cases for each function
*/

#include <cassert>
#include <cstring> // for strlen and strcmp
#include <cctype>  // for isalpha
#include <algorithm> // for swap
using namespace std;

int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);

int main() {
    
    //lastIndexOf
    assert (lastIndexOf("hello", 'l') == 3);
    assert (lastIndexOf("A man, a plan, a canal, Panama", 'p') == 9); // case sensitive
    assert (lastIndexOf("team", 'I') == -1);  // there is no 'I' in "team"


    //reverse
    char str1[] = "hello";
    reverse(str1);
    assert(strcmp(str1, "olleh") == 0);

    char str2[] = "Stressed";
    reverse(str2);
    assert(strcmp(str2, "dessertS") == 0); //ensure case sensitivity


    //replace
    char str3[] = "hello";
    assert(replace(str3, 'l', 'y') == 2); //two replacements
    assert(strcmp(str3, "heyyo") == 0);
    
    char str4[] = "untouched";
    assert(replace(str4, 'a', 'e') == 0); //zero replacements
    assert(strcmp(str4, "untouched") == 0);


    //isPalindrome
    assert(isPalindrome("tacocat") == true);
    assert(isPalindrome("hello") == false);
    assert(isPalindrome("Abba") == true); //case insensitive
    assert(isPalindrome("!rac3car!") == true); //works with special characters


    //toupper
    char str5[] = "hello";
    toupper(str5);
    assert(strcmp(str5, "HELLO") == 0);

    char str6[] = "Don't Shout!";
    toupper(str6);
    assert(strcmp(str6, "DON'T SHOUT!") == 0);// works with punctuations and some caps


    //numLetters
    assert(numLetters("hello") == 5);
    assert(numLetters("123 Main St.") == 6); //doesn't count numbers and punctuation
    assert(numLetters("!@%!#%") == 0); //test empty case 

    return 0;
}






//lastIndexOf() returns the index of the last occurrence of the target character in the string.
// It takes the string `inString` and the character `target` as parameters.
// It returns the index of the last occurrence of the target character in the string.
int lastIndexOf(const char* inString, char target) {
    int i = 0;
    int matchIndex = -1;

    while(inString[i] != '\0') {
        if(inString[i] == target) {
            matchIndex = i;
        }
        i++;
    }
    return matchIndex;
}






//reverse() reverses the string in place.
// It takes the string `inString` as a parameter and does not return anything.
void reverse(char* inString) {
    int length = strlen(inString);
    for (int i = 0; i < length/2; i++) {
        swap(inString[i], inString[length - 1 - i]);
    }
}






//replace() replaces all occurrences of the target character with the replacement character.
// It takes the string `inString`, the character `target`, and the character `replacementChar` as parameters.
// It returns the number of replacements made.
int replace(char* inString, char target, char replacementChar){
    int i = 0;
    int numReplaced = 0;

    while(inString[i] != '\0') {
        if (inString[i] == target) {
            inString[i] = replacementChar;
            numReplaced++;
        }
        i++;
    }
    return numReplaced;
}







// isPalindrome() determines if the string is a palindrome.
// It takes the string `inString` as a parameter.
// It returns true if the string is a palindrome, and false otherwise.
bool isPalindrome(const char* inString) {
    int length = strlen(inString);
    for (int i = 0; i < length/2; i++) {
        if (tolower(inString[i]) != tolower(inString[length - 1 - i])) {
            return false;
        }
    }
    return true;
}






// toupper() converts all characters in the string to uppercase.
// It takes the string `inString` as a parameter and does not return anything.
void toupper(char* inString) {
    int i = 0;
    while (inString[i] != '\0') {
        inString[i] = toupper(inString[i]);
        i++;
    }
}







// numLetters() counts the number of letters in the string.
// It takes the string `inString` as a parameter.
// It returns the number of letters in the string.
int numLetters(const char* inString) {
    int i = 0;
    int letterCount = 0;
    while (inString[i] != '\0') {
        if (isalpha(inString[i])) {
            letterCount++;
        }
        i++;
    }
    return letterCount;
}









