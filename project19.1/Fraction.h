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
            friend std::istream& operator>>(std::istream& in, Fraction& f);


            void testSimplify(int expectedNumerator, int expectedDenominator);
        private:
            void simplify();
            void normalize();
            int numerator;
            int denominator;

    };
}

#endif