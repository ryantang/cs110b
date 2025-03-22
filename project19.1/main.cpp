#include <iostream>
#include <cassert>
#include "Fraction.h"
using namespace std;

void runFractionTests();

int main()
{
    runFractionTests();
    Fraction f;
    cout << "The result starts off at " << f << endl;

    // uncomment to test denominator of 0
    // Fraction f1(1, 0);
}



void runFractionTests() {

    //TODO: Handle negatives
    Fraction f1;
    Fraction f2(9,8);
    Fraction f3(2); //represents the whole number 2
    Fraction result;
    
    assert(f1 == 0);
    assert(f2 == Fraction(9,8));
    assert(f3 == Fraction(2,1));
    assert(f3 == 2);

    assert(f1 < 1);
    assert(!(f1 < 0)); //boundary condition
    assert(f1 < f2);

    assert(f1 <= 1);
    assert((f1 <= 0)); //boundary condition
    assert(f1 <= f2);

    assert(1 > f1);
    assert(!(0 > f1)); //boundary condition
    assert(f2 > f1);
    assert(f2 > 1);

    assert(1 >= f1);
    assert((0 >= f1)); //boundary condition
    assert(f2 >= f1);
    assert(f2 >= 1);

    assert(f1 != 1);
    assert(f2 != f1);
    assert(!(f1 != 0));

    Fraction f4(1,2);
    Fraction f5(5,2);
    assert(f4 + f3 == f5);
    assert(f4 + 2 == f5);
    assert(2 + f4 == f5);

    assert(f5 - f4 == f3);// TODO
    assert(f5 - 2 == f4);
    assert(3 - f4 == f5);


    // cout << "Multiplying " << f1 << " by " << f2 << " gives ";
    // result = f1.multipliedBy(f2);
    // cout << result;
    // cout << endl;

    // cout << "Dividing " << f1 << " by " << f2 << " gives ";
    // result = f1.dividedBy(f2);
    // cout << result;
    // cout << endl;

    // cout << "Adding " << f1 << " to " << f2 << " gives ";
    // result = f1.addedTo(f2);
    // cout << result;
    // cout << endl;

    // cout << "Subtracting " << f2 << " from " << f1 << " gives ";
    // result = f1.subtract(f2);
    // cout << result;
    // cout << endl;

    // cout << "Comparing " << f1 << " and " << f2;
    // if (f1.isEqualTo(f2)) {
    //     cout << " are equal";
    // } else {
    //     cout << " are not equal";
    // }
    // cout << endl;


}