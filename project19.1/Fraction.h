/* 
This header file declares the Fraction class. The Fraction class has a single contructor that takes
two integers as parameters (numerator and denominator), and initializes the Fraction object to the given values.
This class can handle negative fractions. It will simplify the fraction to its lowest terms and normalize 
negative denominators.

This Fraction class overloads six relational operators (==, <, <=, >, >=, !=), four basic arithmetic 
operators (+, -, *, /), shorthand arithmetic operators (+=, -=, *=, /=), the pre-and-post increment 
and decrement operators (++, --), and the insertion and deletion operators (<<, >>).


void Fraction::Fraction(int setNumerator, int setDenominator)

Precondition: The denominator cannot be 0. Requires up to two integers as parameters.
Postcondition: Initializes the Fraction object to the given values. Simplifies the fraction to its lowest terms. Zero parameters
    will initialize the Fraction object to 0/1. One parameter will treat the parameter as a whole number and set the denominator to 1.
    Two parameters will set the numerator and denominator to the given values.


bool operator==(const Fraction& left, const Fraction& right)

Precondition: Requires two valid Fraction objects.
Postcondition: Returns a boolean value indicating if the two fractions are equal.


bool operator<(const Fraction& left, const Fraction& right)

Precondition: Requires two valid Fraction objects.
Postcondition: Returns a boolean value indicating if the left fraction is less than the right fraction.


bool operator<=(const Fraction& left, const Fraction& right)

Precondition: Requires two valid Fraction objects.
Postcondition: Returns a boolean value indicating if the left fraction is less than or equal to the right fraction.


bool operator>(const Fraction& left, const Fraction& right)

Precondition: Requires two valid Fraction objects.
Postcondition: Returns a boolean value indicating if the left fraction is greater than the right fraction.


bool operator>=(const Fraction& left, const Fraction& right)

Precondition: Requires two valid Fraction objects.
Postcondition: Returns a boolean value indicating if the left fraction is greater than or equal to the right fraction.


bool operator!=(const Fraction& left, const Fraction& right)

Precondition: Requires two valid Fraction objects.
Postcondition: Returns a boolean value indicating if the two fractions are not equal


Fraction operator+(const Fraction& left, const Fraction& right)

Precondition: Requires two valid Fraction objects, or one Fraction object and one integer.
Postcondition: Returns a Fraction object that is the sum of the two given parameters.


Fraction operator-(const Fraction& left, const Fraction& right)

Precondition: Requires two valid Fraction objects, or one Fraction object and one integer.
Postcondition: Returns a Fraction object that is the difference of the two given parameters.


Fraction operator*(const Fraction& left, const Fraction& right)

Precondition: Requires two valid Fraction objects, or one Fraction object and one integer.
Postcondition: Returns a Fraction object that is the product of the two given parameters.


Fraction operator/(const Fraction& left, const Fraction& right)

Precondition: Requires two valid Fraction objects, or one Fraction object and one integer.
Postcondition: Returns a Fraction object that is the quotient of the two given parameters.


Fraction& operator+=(const Fraction& f)

Precondition: Requires a valid Fraction object and parameter that's a valid Fraction object or integer.
Postcondition: Adds the given parameter to the Fraction object and returns the result.


Fraction& operator-=(const Fraction& f)

Precondition: Requires a valid Fraction object and parameter that's a valid Fraction object or integer.
Postcondition: Subtracts the given parameter from the Fraction object and returns the result.


Fraction& operator*=(const Fraction& f)

Precondition: Requires a valid Fraction object and parameter that's a valid Fraction object or integer.
Postcondition: Multiplies the Fraction object by the given parameter and returns the result.


Fraction& operator/=(const Fraction& f)

Precondition: Requires a valid Fraction object and parameter that's a valid Fraction object or integer.
Precondition: Divides the Fraction object by the given parameter and returns the result.


Fraction& operator++()

usage: f++
Precondition: Requires a valid Fraction object.
Postcondition: Increments the Fraction object by 1 and returns the result.


Fraction operator++(int)

usage: ++f
Precondition: Requires a valid Fraction object.
Postcondition: Increments the Fraction object by 1 and returns the original value.


Fraction& operator--()

usage: f--
Precondition: Requires a valid Fraction object.
Postcondition: Decrements the Fraction object by 1 and returns the result.


Fraction operator--(int)

usage: --f 
Precondition: Requires a valid Fraction object.
Postcondition: Decrements the Fraction object by 1 and returns the original value.


std::ostream& operator<<(std::ostream& out, const Fraction& f)

Precondition: Requires a valid Fraction object.
Postcondition: Prints the Fraction as either a whole number (5), a fraction (1/2), or a mixed number (1+1/2).


std::istream &operator>>(std::istream &in, Fraction &f)

Precondition: Requires a stream of fractions in valid format. Valid formats can be whole numbers (5), fractions (1/2), or mixed numbers (1+1/2).
Postcondition: Returns a Fraction object parsed from the input.


void testSimplify(int expectedNumerator, int expectedDenominator)

Precondition: Requires a valid fraction and parameters specifying the expected numerator and denominator after simplification.
Postcondition: Throws an assertion error if the simplified fraction does not match the expected values.

*/



#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace cs_fraction {
    class Fraction {
        public: 

            Fraction(int setNumerator = 0, int setDenominator = 1);

            friend bool operator==(const Fraction& left, const Fraction& right);
            friend bool operator<(const Fraction& left, const Fraction& right);
            friend bool operator<=(const Fraction& left, const Fraction& right);
            friend bool operator>(const Fraction& left, const Fraction& right);
            friend bool operator>=(const Fraction& left, const Fraction& right);
            friend bool operator!=(const Fraction& left, const Fraction& right);

            friend Fraction operator+(const Fraction& left, const Fraction& right);
            friend Fraction operator-(const Fraction& left, const Fraction& right);
            friend Fraction operator*(const Fraction& left, const Fraction& right);
            friend Fraction operator/(const Fraction& left, const Fraction& right);

            Fraction& operator+=(const Fraction& f);
            Fraction& operator-=(const Fraction& f);
            Fraction& operator*=(const Fraction& f);
            Fraction& operator/=(const Fraction& f);
            Fraction& operator++();
            Fraction operator++(int);
            Fraction& operator--();
            Fraction operator--(int);
            
            friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
            friend std::istream &operator>>(std::istream &in, Fraction &f);

            void testSimplify(int expectedNumerator, int expectedDenominator);
        private:
            void simplify();
            void normalize();
            void parseMixedNumber(std::string input);
            int numerator;
            int denominator;

    };
}

#endif