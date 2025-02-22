/* Ryan Tang | 2/20/2025 | CS 110B with instructor David Harden | project14.1/main.cpp
    This program creates a class that represents a fraction. The class has methods to set the numerator and denominator, 
    multiply two fractions, divide two fractions, add two fractions, subtract two fractions, and check if two fractions are equal. 
    The main() function demonstrates the class by creating two fractions, performing the operations, and printing the results.
*/

#include <iostream>
#include <cassert>
#include <string> //TODO: Delete after testing
#include "Fraction.h"
using namespace std;

void runTests();




// main() demonstrates the Fraction class by creating two Fraction objects, performing operations, and printing the results.
int main()
{
    runTests();
    Fraction f1(9,8);
    Fraction f2(2,3);
    Fraction result;

    cout << "The result starts off at ";
    result.print();
    cout << endl;

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
    
    const Fraction f3(12, 8);
    const Fraction f4(202, 303);
    result = f3.multipliedBy(f4);
    cout << "The product of ";
    f3.print();
    cout << " and ";
    f4.print();
    cout << " is ";
    result.print();
    cout << endl;
}






// runTests() is a helper function that runs a series of tests to verify the Fraction class.
void runTests() {
    Fraction f1(9, 8);
    Fraction f2(2, 3);
    Fraction f3(4, 6);
    Fraction f4(3, 4);
    Fraction f5(1, 4);
    Fraction result;
    Fraction defaultFraction;
    Fraction zero(0, 1);

    assert(f1.toString() == "9/8");
    
    assert(f1.isEqualTo(f1));
    assert(!f1.isEqualTo(f2));
    assert(f2.isEqualTo(f3));
    assert(defaultFraction.isEqualTo(zero));

    result = f1.multipliedBy(f2);
    Fraction expected1(18,24);
    assert(result.isEqualTo(expected1));

    result = f1.dividedBy(f2);
    Fraction expected2(27,16);
    assert(result.isEqualTo(expected2));

    result = f1.addedTo(f2);
    Fraction expected3(43,24);
    assert(result.isEqualTo(expected3));

    result = f1.subtract(f2);
    Fraction expected4(11,24);
    assert(result.isEqualTo(expected4));

    //Test simplification
    assert(f3.toString() == "2/3");

    result = f4.multipliedBy(f2);
    assert(result.toString() == "1/2");

    result = f4.dividedBy(f4);
    assert(result.toString() == "1/1");

    result = f1.addedTo(f1);
    assert(result.toString() == "9/4");

    result = f4.subtract(f5);
    assert(result.toString() == "1/2");

    result = f1.subtract(f1);
    assert(result.toString() == "0/1"); //test zero simplification case

    cout << "Tests completed." << endl;
}