/* Ryan Tang | 2/22/2025 | CS 110B with instructor David Harden | project15.1/Fraction.h
    
    This header file declares the Fraction class. The Fraction class has two constructors.
    The default contructor takes no parameters and initializes the Fraction object to 0/1.
    The other constructor takes two integers as parameters (numerator and denominator),
    and initializes the Fraction object to the given values. This class only handles
    non-negative fractions. It will also simplify the fraction to its lowest terms.
    
    The Fraction class has functions to print the fraction, multiply two fractions, divide two 
    fractions, add two fractions, subtract two fractions, and check if two fractions are equal.

    void Fraction::Fraction() 
    
    Precondition: None
    Postcondition: Initializes the Fraction object to 0/1.

    void Fraction::Fraction(int n, int d)

    Precondition: The denominator cannot be 0. Neither of the parameters can be negative.
    Postcondition: Initializes the Fraction object to the given values. Simplifies the fraction to its lowest terms.

    void Fraction::print() const

    Precondition: None
    Postcondition: Prints the Fraction object in the format "numerator/denominator". For fractions larger than 1, 
        the result will be printed as an improper fraction rather than a mixed number.


    Fraction Fraction::multipliedBy(const Fraction& f) const;

    Precondition: Requires two valid Fraction objects.
    Postcondition: Returns a Fraction object that is the product of the two fractions.


    Fraction Fraction::dividedBy(const Fraction& f) const;

    Precondition: Requires two valid Fraction objects.
    Postcondition: Returns a Fraction object that is the quotient of the two fractions.


    Fraction Fraction::addedTo(const Fraction& f) const;

    Precondition: Requires two valid Fraction objects.
    Postcondition: Returns a Fraction object that is the sum of the two fractions.


    Fraction Fraction::subtract(const Fraction& f) const;

    Precondition: Requires two valid Fraction objects.
    Postcondition: Returns a Fraction object that is the difference of the two fractions.


    bool Fraction::isEqualTo(const Fraction& f) const;

    Precondition: Requires two valid Fraction objects.
    Postcondition: Returns a boolean value indicating if the two fractions are equal.
*/

#ifndef FRACTION_H
#define FRACTION_H

using namespace std;

class Fraction {
    public:
        Fraction();
        Fraction(int n, int d);
        void print() const;
        Fraction multipliedBy(const Fraction& f) const;
        Fraction dividedBy(const Fraction& f) const;
        Fraction addedTo(const Fraction& f) const;
        Fraction subtract(const Fraction& f) const;
        bool isEqualTo(const Fraction& f) const;
    private:
        void simplify();
        int numerator;
        int denominator;
    };

#endif