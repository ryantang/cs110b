/*
The Fraction class has two private data members, numerator and denominator, that store the values of the fraction. The class stores
the fraction in its simplest form, meaning the numerator and denominator have no common factors other than 1. However, it still stores
the fraction as an "improper fraction", meaning the numerator can be greater than the denominator. The insertion operator (<<) will 
convert the fraction to a mixed number if necessary. This class handles negative fractions.
*/

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





    // This extraction operator calculates whether the input has a non-zero whole number or non-zero remainder.
    // If it has both, it prints out a mixed number (1+3/4). If it has only a whole number, it prints out the whole number (5).
    // If it has only a remainder, it prints out a proper fraction (1/2).
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






    // This insertion operator reads in a stream, converts them to individual strings, and parses them into
    // Fraction objects. If it detects a "+" sign, it will parse the string as a mixed number. Otherwise, it 
    // detects a "/" sign, it will parse the string as a fraction. If it doesn't detect either, it will parse 
    // the string as a whole number.
    std::istream& operator>>(istream& in, Fraction& f) {
        string input;
        int numerator, denominator;
        while(in >> input) {
            if (input.find("+") != string::npos) {
                f.parseMixedNumber(input);
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






    // The parsedMixedNumber function takes a mixed number string (1+1/2) and parses it into a Fraction object.
    // It first finds the "+" and "/" signs, then parses the whole number, numerator, and denominator. It then
    // calculates the numerator adjusting for negatives.
    void Fraction::parseMixedNumber(string input) {
        int plusIndex = input.find("+");
        int slashIndex = input.find("/");
        int whole = stoi(input.substr(0, plusIndex));
        int parsedNumerator = stoi(input.substr(plusIndex + 1, slashIndex));

        denominator = stoi(input.substr(slashIndex + 1));
        if (whole < 0) {
            numerator = whole * denominator - parsedNumerator;
        } else {
            numerator = whole * denominator + parsedNumerator;
        }
        simplify();   
    }
    





    // The simplify function simplifies the fraction to its lowest terms. It does not return anything.
    //
    // Implementation: Since we allow negative and improper fractions, we start with the 
    // absolute value of the numerator and denominator, and find the smaller of the two. 
    // We then loop from that number down to 2, looking for the greatest common factor (GCF). 
    // When we find it, we divide both the numerator and denominator by the GCF.
    //
    // The normalize function ensures that the denominator is positive.
    //
    // This function also handles the case where the numerator is 0. In that case, the denominator
    // is set to 1.
    void Fraction::simplify() {
        int smaller;
        bool foundGCF = false;
        normalize();

        if (numerator == 0) {
            denominator = 1;
        }

        if (abs(numerator) < denominator) {
            smaller = abs(numerator);
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






    // The normalize function ensures that the denominator is positive.
    void Fraction::normalize() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
}