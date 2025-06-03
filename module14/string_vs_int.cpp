#include <string>
#include <iostream>

using namespace std;

int main() {
    // Set exception mask for cin stream
    string inputName;
    int age;
    cin.exceptions(ios::failbit);

    cin >> inputName;
    while(inputName != "-1") {
      // FIXME: The following line will throw an ios_base::failure.
      //        Insert a try/catch statement to catch the exception.
      //        Clear cin's failbit to put cin in a useable state.

        try {
        cin >> age;
        cout << inputName << " " << (age + 1) << endl;

        cin >> inputName;
        }
        catch (ios_base::failure& excpt) {
            cin.clear();
            cout << inputName << " " << 0 << endl;
            string garbage;
            getline(cin, garbage);
            cin >> inputName;
        }
   }
   
   return 0;
}