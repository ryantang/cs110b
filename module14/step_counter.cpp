#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

/* Define your function here */ 
double StepsToMiles(int steps) {
    if (steps < 0) {
        throw runtime_error("Exception: Negative step count entered.");
    }
    return static_cast<double>(steps)/2000;
}

int main() {
    int steps;
    double miles;

    cin >> steps;
    try {
        miles = StepsToMiles(steps);
        cout << fixed << setprecision(2);
        cout << miles << endl;
    }
    catch(runtime_error& excpt) {
        cout << excpt.what() << endl;
    }


   return 0;
}