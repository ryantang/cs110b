#include <iostream>
using namespace std;

/* TODO: Write recursive DigitCount() function here. */
int DigitCount(int num) {
    if (num <= 9) {
        return 1;
    } else {
        return DigitCount(num/10) + 1;
    }
}


int main() {
   int num;
   int digits;

   cin >> num;
   digits = DigitCount(num);
   cout << digits << endl;
   return 0;
}
