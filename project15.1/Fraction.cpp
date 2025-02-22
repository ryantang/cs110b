/* 
The Fraction class has two private member variables, numerator and denominator, that store the values of the fraction.
The numerator must be zero or a positive integer, and the denominator must be a positive integer. 

This class will store the fraction in its simplest form. For example, if the fraction is 4/6, the class will simplify it to 2/3.
The Fraction class also has a simplify() method that simplifies the fraction to its lowest terms.
*/

#include <iostream>
#include <cassert>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}






Fraction::Fraction(int n, int d) {
    assert(d != 0);
    numerator = n;
    denominator = d;
    simplify();
}





// The Fraction::simplify() private function simplifies the fraction to its lowest terms.
// It does not return anything.  
//
// Implmentation: Since we allow fractions that are greater than 1, we start
// by finding the smaller of the numerator and denominator.  We then loop from that number
// down to 2, looking for the greatest common factor (GCF).  When we find it, we divide both
// the numerator and denominator by the GCF.
//
// This function also handles the case where the numerator is 0.  In that case, the denominator
// is set to 1.
//
// Developer note: This function would benefit from refactoring, however the requirements state
// that we cannot define any additional functions. Furthermore, there could be small performance
// improvements by returning early when the numerator is 0 or breaking the loop when the GCF is found.
void Fraction::simplify() {
    int smaller;
    bool foundGCF = false;

    if (numerator == 0) {
        denominator = 1;
    }

    if (numerator < denominator) {
        smaller = numerator;
    } else {
        smaller = denominator;
    }

    for (int i = smaller; i > 1; i--) {
        if (numerator % i == 0 && denominator % i == 0 && !foundGCF) {
            foundGCF = true;
            numerator = numerator/i;
            denominator = denominator/i;
        }
    }
}






Fraction Fraction::multipliedBy(const Fraction& f) const {
    Fraction result;
    result.numerator = numerator * f.numerator;
    result.denominator = denominator * f.denominator;
    result.simplify();
    return result;
}







Fraction Fraction::dividedBy(const Fraction& f) const{
    Fraction result;
    result.numerator = numerator * f.denominator;
    result.denominator = denominator * f.numerator;
    result.simplify();
    return result;
}







Fraction Fraction::addedTo(const Fraction& f) const {
    Fraction result;
    result.numerator = numerator * f.denominator + f.numerator * denominator;
    result.denominator = denominator * f.denominator;
    result.simplify();
    return result;
}







Fraction Fraction::subtract(const Fraction& f) const {
    Fraction result;
    result.numerator = numerator * f.denominator - f.numerator * denominator;
    result.denominator = denominator * f.denominator;
    result.simplify();
    return result;
}







bool Fraction::isEqualTo(const Fraction& f) const {
    return (numerator * f.denominator == denominator * f.numerator);
}






void Fraction::print() const {
    cout << numerator << "/" << denominator;
}


