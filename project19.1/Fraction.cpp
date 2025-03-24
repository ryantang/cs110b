#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Fraction.h"
using namespace std;

namespace cs_fraction {

    Fraction::Fraction(int setNumerator, int setDenominator) {
        assert(setDenominator != 0);
        numerator = setNumerator;
        denominator = setDenominator;
        simplify();
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

    Fraction operator-(const Fraction& left, const Fraction& right) {
        return Fraction(left.numerator * right.denominator - right.numerator * left.denominator, 
            left.denominator * right.denominator);
    }

    Fraction operator*(const Fraction& left, const Fraction& right) {
        return Fraction(left.numerator * right.numerator, left.denominator * right.denominator);
    }

    Fraction operator/(const Fraction& left, const Fraction& right) {
        return Fraction(left.numerator * right.denominator, left.denominator * right.numerator);
    }

    Fraction& Fraction::operator+=(const Fraction& f) {
        numerator = numerator * f.denominator + f.numerator * denominator;
        denominator = denominator * f.denominator;
        simplify();
        return *this;
    }

    Fraction& Fraction::operator-=(const Fraction& f) {
        numerator = numerator * f.denominator - f.numerator * denominator;
        denominator = denominator * f.denominator;
        simplify();
        return *this;
    }

    Fraction& Fraction::operator*=(const Fraction& f) {
        numerator = numerator * f.numerator;
        denominator = denominator * f.denominator;
        simplify();
        return *this;
    }

    Fraction& Fraction::operator/=(const Fraction& f) {
        numerator = numerator * f.denominator;
        denominator = denominator * f.numerator;
        simplify();
        return *this;
    }

    Fraction& Fraction::operator++() {
        numerator += denominator;
        simplify();
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp = *this;
        numerator += denominator;
        simplify();
        return temp;
    }

    Fraction& Fraction::operator--() {
        numerator -= denominator;
        simplify();
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp = *this;
        numerator -= denominator;
        simplify();
        return temp;
    }

    void Fraction::testSimplify(int expectedNumerator, int expectedDenominator) {
        simplify();
        assert(numerator == expectedNumerator);
        assert(denominator == expectedDenominator);
    }

    std::ostream& operator<<(ostream& out, const Fraction& f) {
        int whole = f.numerator / f.denominator;
        int remainder = f.numerator % f.denominator;
        if (remainder == 0) {
            out << whole;
        } else if (whole == 0) {
            out << remainder << "/" << f.denominator;
        } else { 
                out << whole << "+" << abs(remainder) << "/" << f.denominator;
        }
        return out;
    }

    std::istream& operator>>(istream& in, Fraction& f) {
        string input;
        int whole, numerator, denominator;
        while(in >> input) {
            if (input.find("+") != string::npos) {
                int plusIndex = input.find("+");
                int slashIndex = input.find("/");
                whole = stoi(input.substr(0, plusIndex));
                numerator = stoi(input.substr(plusIndex + 1, slashIndex));
                denominator = stoi(input.substr(slashIndex + 1));
                if (whole < 0) {
                    f = Fraction(whole * denominator - numerator, denominator);
                } else {
                    f = Fraction(whole * denominator + numerator, denominator);
                }   
                return in;
            } else if (input.find("/") != string::npos) {
                int slashIndex = input.find("/");
                numerator = stoi(input.substr(0, slashIndex));
                denominator = stoi(input.substr(slashIndex + 1));
                f = Fraction(numerator, denominator);
                return in;
            } else {
                f = Fraction(stoi(input));
                return in;
            }
        }
        return in;
    }


    void Fraction::simplify() {
        int smaller;
        bool foundGCF = false;
        normalize();

        if (numerator == 0) {
            denominator = 1;
        }

        if (abs(numerator) < abs(denominator)) {
            smaller = abs(numerator);
        } else {
            smaller = abs(denominator);
        }

        for (int i = smaller; i > 1; i--) {
            if (numerator % i == 0 && denominator % i == 0 && !foundGCF) {
                foundGCF = true;
                numerator = numerator/i;
                denominator = denominator/i;
            }
        }
    }

    void Fraction::normalize() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
}