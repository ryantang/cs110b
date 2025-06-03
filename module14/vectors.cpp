#include <iostream>
#include <vector>
#include <stdexcept>      // For std::out_of_range
using namespace std;

int main() {
    vector<string> names = { "Ryley", "Edan", "Reagan", "Henry", "Caius", "Jane", "Guto", "Sonya", "Tyrese", "Johnny" };
    int index;

    cin >> index;
   
    /* Type your code here. */
    try {
    cout << names.at(index) << endl;
    }
    catch(out_of_range& excpt) {
        cout << "Exception! " << excpt.what() << endl;
        if (index < 0) {
            cout << "The closest name is: " << names.at(0) << endl;
        } else if (index > 9)
        {
            cout << "The closest name is: " << names.at(9) << endl;
        }
        
    }

   return 0;
}
