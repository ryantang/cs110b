/* 
    This program reads in a list of names and scores from the user, sorts the list by score 
    in descending order, and displays the sorted list. The program uses the selection sort 
    algorithm to sort the list.
*/

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);
int indexOfLargest(const int list[], int startingIndex, int numItems);
void testSort();

int main() {
    testSort();
    int size;
    string* names;
    int* scores;

    cout << "How many scores will you enter?: ";
    cin >> size;

    names = new string[size];
    scores = new int[size];
    readData(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);
}






//readData() reads in the names and scores from the user and stores them in the arrays.
// It takes the string array `names[]`, the integer array `scores[]`, and the integer `size` as parameters.
// It does not return anything.
void readData(string names[], int scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter the score for score #" << i + 1 << ": ";
        cin >> scores[i];
    }
}






//displayData() displays the names and scores in the arrays.
// It takes the string array `names[]`, the integer array `scores[]`, and the integer `size` as parameters.
// It assumes that names[] and scores[] are sorted in descending order by score, because it states "Top Scorers:".
// It does not return anything.
void displayData(const string names[], const int scores[], int size) {
    cout << endl << "Top Scorers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    }
}







//sortData() sorts two arrays, names[] and scores[], in descending order by score.
// It takes the string array `names[]`, the integer array `scores[]`, and the integer `size` as parameters.
// It uses the selection sort algorithm to sort the arrays, uses the indexOfLargest() helper function,
// and does not return anything.
void sortData(string names[], int scores[], int numItems)
{
    for (int count = 0; count < numItems - 1; count++){
        int largestIndex = indexOfLargest(scores, count, numItems);
        swap(scores[largestIndex], scores[count]);
        swap(names[largestIndex], names[count]);
    }

}






//indexOfLargest() is a helper function that returns the index of the largest value in the list.
// It takes the integer array `list[]`, the integer `startingIndex`, and the integer `numItems` as parameters.
// It returns the index of the largest value in the list.
int indexOfLargest(const int list[], int startingIndex, int numItems) {
    int targetIndex = startingIndex;

    for (int count = startingIndex + 1; count < numItems; count++){
        if (list[count] > list[targetIndex]){
            targetIndex = count;
        }
    }

    return targetIndex;
}






//testSort() is a function that tests the sortData() function.
// It does not take any parameters and does not return anything.
void testSort() {
    string names[] = {"A", "B", "C"};
    int scores[] = {1, 7, 5};
    sortData(names, scores, 3);

    assert(names[0] == "B");
    assert(scores[0] == 7);
    assert(names[1] == "C");
    assert(scores[1] == 5);
    assert(names[2] == "A");
    assert(scores[2] == 1);
}
