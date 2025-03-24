#include <iostream>
#include <cassert>
#include <sstream>
#include "Fraction.h"
using namespace std;
using namespace cs_fraction;

void runFractionTests();

int main()
{
    runFractionTests();
    Fraction f;
    cout << "The result starts off at " << f << endl;

    f = Fraction(5,3);
    cout << "The result is now " << f << endl;
    cout << "It should show 1+2/3" << endl;

    f = Fraction(1,3);
    f--;
    cout << "The result is now " << f << endl;
    cout << "It should show -2/3" << endl;

    f = Fraction(1,-3);
    cout << "The result is now " << f << endl;
    cout << "It should show -1/3" << endl;
    f--;
    cout << "The result is now " << f << endl;
    cout << "It should show -1+1/3" << endl;

    // uncomment to test denominator of 0
    // Fraction f1(1, 0);
}



void runFractionTests() {

    //TODO: Handle negatives
    Fraction f, f1;
    Fraction f2(9,8);
    Fraction f3(2); //represents the whole number 2
    Fraction result;
    istringstream in;
    
    assert(f1 == 0);
    assert(f2 == Fraction(9,8));
    assert(f3 == Fraction(2,1));
    assert(f3 == 2);

    assert(f1 < 1);
    assert(!(f1 < 0)); //boundary condition
    assert(f1 < f2);

    assert(f1 <= 1);
    assert((f1 <= 0)); //boundary condition
    assert(f1 <= f2);

    assert(1 > f1);
    assert(!(0 > f1)); //boundary condition
    assert(f2 > f1);
    assert(f2 > 1);

    assert(1 >= f1);
    assert((0 >= f1)); //boundary condition
    assert(f2 >= f1);
    assert(f2 >= 1);

    assert(f1 != 1);
    assert(f2 != f1);
    assert(!(f1 != 0));

    Fraction f4(1,2);
    Fraction f5(5,2);
    assert(f4 + f3 == f5);
    assert(f4 + 2 == f5);
    assert(2 + f4 == f5);

    assert(f5 - f4 == f3);// TODO
    assert(f5 - 2 == f4);
    assert(3 - f4 == f5);

    assert(f4 * f4 == Fraction(1,4));
    assert(f4 * 2 == 1);
    assert(2 * f4 == 1);

    assert(Fraction(1,4) / f4 == f4);
    assert(Fraction(1,3) / 2 == Fraction(1,6));
    assert(1 / f4 == 2);

    f = Fraction(3,4);
    f += f4;
    assert(f == Fraction(5,4));
    f += 1;
    assert(f == Fraction(9,4));

    f = Fraction(10,3);
    f -= Fraction(2,3);
    assert(f == Fraction(8,3));
    f -= 1;
    assert(f == Fraction(5,3));

    f = Fraction(3,4);
    f *= Fraction(2,3);
    assert(f == Fraction(1,2));
    f *= 2;
    assert(f == 1);

    f = Fraction(3,4);
    f /= Fraction(2,3);
    assert(f == Fraction(9,8));
    f /= 2;
    assert(f == Fraction(9,16));

    f = Fraction(-5,2);
    f /= Fraction(5);
    assert(f == Fraction(-1,2));

    f = Fraction(1,2);
    assert(++f == Fraction(3, 2));
    assert(f == Fraction(3, 2));

    f = Fraction(1, 2);
    assert(f++ == Fraction(1, 2));
    assert(f == Fraction(3, 2)); 

    f = Fraction(3, 2);
    assert(--f == Fraction(1, 2));
    assert(f == Fraction(1, 2));

    f = Fraction(3, 2);
    assert(f-- == Fraction(3, 2));
    assert(f == Fraction(1, 2));

    f = Fraction(6, 8);
    f.testSimplify(3, 4);

    in.str("3/4");
    in.clear();
    in >> f;
    assert(f == Fraction(3, 4));
    
    in.str("5");
    in.clear();
    in >> f;
    assert(f == Fraction(5));

    in.str("3+1/2");
    in.clear();
    in >> f;
    assert(f == Fraction(7, 2));

    in.str("-4/2");
    in.clear();
    in >> f;
    assert(f == -2);

    in.str("-10+5/6");
    in.clear();
    in >> f;
    assert(f == Fraction(-65, 6));

    in.str("5 3+1/2 -4/2");
    in.clear();
    in >> f >> f1 >> f2;
    cout << "f is " << f << endl;
    cout << "f1 is " << f1 << endl;
    cout << "f2 is " << f2 << endl;
    assert(f == Fraction(5));
    assert(f1 == Fraction(7, 2));
    assert(f2 == -2);



}