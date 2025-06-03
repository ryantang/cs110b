#include <iostream>
using namespace std;

int main() {
    int userNum, divNum;
    int result;
    cin.exceptions(ios::failbit);

    try {
        cin >> userNum >> divNum;

        if (divNum == 0) {
            throw runtime_error("Divide by zero!");
        }
        result = userNum/divNum;
        cout << result;
    }
    catch(ios_base::failure& excpt) {
        cout << "Input Exception: " << excpt.what() << endl;
    }
    catch(runtime_error& excpt) {
        cout << "Runtime Exception: " << excpt.what() << endl;
    }


    return 0;
}