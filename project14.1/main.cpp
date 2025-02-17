/* Ryan Tang | 2/12/2025 | CS 110B with instructor David Harden | project14.1/main.cpp
    This program creates a class that represents a fraction. The class has methods to set the numerator and denominator, 
    multiply two fractions, divide two fractions, add two fractions, subtract two fractions, and check if two fractions are equal. 
    The main() function demonstrates the class by creating two fractions, performing the operations, and printing the results.
*/

#include <iostream>
#include <cassert>
using namespace std;

class Fraction {
public:
    void set(int setNumerator, int setDenominator);
    void print();
    Fraction multipliedBy(Fraction f);
    Fraction dividedBy(Fraction f);
    Fraction addedTo(Fraction f);
    Fraction subtract(Fraction f);
    bool isEqualTo(Fraction f);
private:
    int numerator;
    int denominator;
};






// The Fraction::set() sets the value of the Fraction object.
// It takes an integer for the numerator and an integer for the denominator.
// It does not return anything.
void Fraction::set(int setNumerator, int setDenominator) {
    numerator = setNumerator;
    denominator = setDenominator;
}






// The Fraction::multipliedBy() takes a Fraction object as a parameter
// and returns a Fraction object that is the product of the two fractions.
Fraction Fraction::multipliedBy(Fraction f) {
    Fraction result;
    result.numerator = numerator * f.numerator;
    result.denominator = denominator * f.denominator;
    return result;
}






// The Fraction::dividedBy() takes a Fraction object as a parameter,
// divides the Fraction object by the parameter, and returns the resulting Fraction object.
Fraction Fraction::dividedBy(Fraction f) {
    Fraction result;
    result.numerator = numerator * f.denominator;
    result.denominator = denominator * f.numerator;
    return result;
}






// The Fraction::addedTo() takes a Fraction object as a parameter,
// adds the Fraction object to the parameter, and returns the resulting Fraction object.
Fraction Fraction::addedTo(Fraction f) {
    Fraction result;
    result.numerator = numerator * f.denominator + f.numerator * denominator;
    result.denominator = denominator * f.denominator;
    return result;
}






// The Fraction::subtract() takes a Fraction object as a parameter,
// subtracts the parameter from the Fraction object, and returns the resulting Fraction object.
Fraction Fraction::subtract(Fraction f) {
    Fraction result;
    result.numerator = numerator * f.denominator - f.numerator * denominator;
    result.denominator = denominator * f.denominator;
    return result;
}






// The Fraction::isEqualTo() takes a Fraction object as a parameter,
// checks if the Fraction object is equal to the parameter, and returns a boolean.
bool Fraction::isEqualTo(Fraction f) {
    return (numerator * f.denominator == denominator * f.numerator);
}






// The Fraction::print() prints the Fraction object in the format "numerator/denominator".
void Fraction::print() {
    cout << numerator << "/" << denominator;
}






// main() demonstrates the Fraction class by creating two Fraction objects, performing operations, and printing the results.
int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

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
}






// runTests() is a helpr function that runs a series of tests to verify the Fraction class.
void runTests() {
    Fraction f1;
    Fraction f2;
    Fraction f3;
    Fraction result;
    Fraction expected;

    f1.set(9, 8);
    f2.set(2, 3);
    f3.set(4, 6);

    assert(f1.isEqualTo(f1));
    assert(!f1.isEqualTo(f2));
    assert(f2.isEqualTo(f3));

    result = f1.multipliedBy(f2);
    expected.set(18,24);
    assert(result.isEqualTo(expected));

    result = f1.dividedBy(f2);
    expected.set(27,16);
    assert(result.isEqualTo(expected));

    result = f1.addedTo(f2);
    expected.set(43,24);
    assert(result.isEqualTo(expected));

    result = f1.subtract(f2);
    expected.set(11,24);
    assert(result.isEqualTo(expected));
}