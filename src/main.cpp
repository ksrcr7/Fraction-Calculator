#include <iostream>
#include "Fraction.h"
#include <cassert>
#include <sstream>



int main() {

    using std::cout; using std::endl;

    Fraction a(1, 2);
    Fraction b(2, 3);
    Fraction c(-2, -4);
    assert(c == Fraction(1,1) / Fraction(2,1));

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << (a + b) << "  (expect 7/6)\n";
    cout << "a - b = " << (a - b) << "  (expect -1/6)\n";
    cout << "a * b = " << (a * b) << "  (expect 1/3)\n";
    cout << "a / b = " << (a / b) << "  (expect 3/4)\n";


    Fraction x(1, 2);
    x += Fraction(1, 3);
    assert(x == Fraction(5, 6));
    x *= Fraction(2, 5);
    assert(x == Fraction(1, 3));

    cout << "-a   = " << (-a) << "  (expect -1/2)\n";
    cout << "+(-a)= " << ( +(-a) ) << "  (expect -1/2)\n";


    assert(Fraction(2,4) == Fraction(1,2));
    assert(Fraction(-1,2) <= Fraction(1,3));
    assert(Fraction(3,4) >= Fraction(2,5));


    {
        std::istringstream ok1("3/4");
        Fraction t{};
        ok1 >> t;
        assert(ok1 && t == Fraction(3,4));
    }
    {
        std::istringstream ok2("5");
        Fraction t{};
        ok2 >> t;
        std::cout << "ok2.good()=" << std::boolalpha << ok2.good()
                  << "  t=" << t << "\n";

        std::cout << "t num/den = " << t.GetNumerator() << "/" << t.GetDenominator() << "\n";
        std::cout << "eq? " << std::boolalpha << (t == Fraction(5,1)) << "\n";


        assert(!ok2.fail() && !ok2.bad() && t == Fraction(5,1));

    }
    {
        std::istringstream bad1("7/");
        Fraction t(9,10);
        bad1 >> t;
        assert(!bad1 && t == Fraction(9,10));
    }
    {
        std::istringstream bad2("2/0");
        Fraction t(1,3);
        bad2 >> t;
        assert(!bad2 && t == Fraction(1,3));
    }


    try {
        Fraction boom(1,0);
        (void)boom;
        assert(false && "Expected exception for denominator=0");
    } catch (const std::invalid_argument&) {

    }

    cout << "All basic tests passed" << endl;
    return 0;






}
