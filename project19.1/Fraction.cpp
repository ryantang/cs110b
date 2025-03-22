#include <iostream>
#include <cassert>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int setNumerator) {
    numerator = setNumerator;
    denominator = 1;
}

Fraction::Fraction(int setNumerator, int setDenominator) {
    assert(setDenominator != 0);
    numerator = setNumerator;
    denominator = setDenominator;
    // simplify();
}

bool operator==(const Fraction& left, const Fraction& right) {
    return left.numerator * right.denominator == right.numerator * left.denominator;
}

bool operator<(const Fraction& left, const Fraction& right) {
    return left.numerator * right.denominator < right.numerator * left.denominator;
}

bool operator<=(const Fraction& left, const Fraction& right) {
    return left.numerator * right.denominator <= right.numerator * left.denominator;
}

bool operator>(const Fraction& left, const Fraction& right) {
    return left.numerator * right.denominator > right.numerator * left.denominator;
}

bool operator>=(const Fraction& left, const Fraction& right) {
    return left.numerator * right.denominator >= right.numerator * left.denominator;
}

bool operator!=(const Fraction& left, const Fraction& right) {
    return left.numerator * right.denominator != right.numerator * left.denominator;
}

Fraction operator+(const Fraction& left, const Fraction& right) {
    return Fraction(left.numerator * right.denominator + right.numerator * left.denominator, 
        left.denominator * right.denominator);
}

// Fraction Fraction::operator+(const Fraction& f) const {
//     return Fraction(numerator * f.denominator + f.numerator * denominator, denominator * f.denominator);
// }

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}
