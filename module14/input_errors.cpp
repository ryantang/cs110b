#include <iostream>
using namespace std;

int main() {
   cin.exceptions(ios::failbit); // Allow cin to throw exceptions
   int val1;
   int val2;
   int val3;
   int max;
   int valuesRead = 0;

   val1 = 0;
   val2 = 0;
   val3 = 0;
   
    try {
        if (cin >> val1) {
            valuesRead++;
        }
        if (cin >> val2) {
            valuesRead++;
        }
        if (cin >> val3) {
            valuesRead++;
        }


        max = val1;
        if (val2 > max) {
            max = val2;
        }
        if (val3 > max) {
            max = val3;
        }

        cout << max << endl;
    }
    catch(ios_base::failure& e) {
        cout << valuesRead << " input(s) read:" << endl;
        if (valuesRead == 0) {
        cout << "No max" << endl;
        } else if (valuesRead == 1) {
            cout << "Max is " << val1 << endl;
        } else {
            max = val1;
            if (val2 > max) {
                max = val2;
            }
            cout << "Max is " << max << endl;
        }
    }

   return 0;
}