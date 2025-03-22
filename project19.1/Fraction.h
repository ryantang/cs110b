#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>


class Fraction {
    public: 
        Fraction();
        Fraction(int setNumerator);
        Fraction(int setNumerator, int setDenominator);

        friend bool operator==(const Fraction& left, const Fraction& right);
        friend bool operator<(const Fraction& left, const Fraction& right);
        friend bool operator<=(const Fraction& left, const Fraction& right);
        friend bool operator>(const Fraction& left, const Fraction& right);
        friend bool operator>=(const Fraction& left, const Fraction& right);
        friend bool operator!=(const Fraction& left, const Fraction& right);

        friend Fraction operator+(const Fraction& left, const Fraction& right);
        // Fraction operator+(const Fraction& f) const;

        friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
        // Fraction multipliedBy(const Fraction& f) const;
        // Fraction dividedBy(const Fraction& f) const;
        // Fraction addedTo(const Fraction& f) const;
        // Fraction subtract(const Fraction& f) const;
        // bool isEqualTo(const Fraction& f) const;
    private:
        void simplify();
        int numerator;
        int denominator;
};


#endif