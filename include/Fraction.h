

#ifndef FRACTION_CALCULATOR_FRACTION_H
#define FRACTION_CALCULATOR_FRACTION_H

#include <iostream>


class Fraction{
private:
    long long numerator,denominator;
    void normalize();


public:
    Fraction(long long,long long);
    [[nodiscard]] long long GetNumerator()const;
    [[nodiscard]] long long GetDenominator()const;
    Fraction operator += (const Fraction&);
    Fraction operator -= (const Fraction&);
    Fraction operator /= (const Fraction&);
    Fraction operator *= (const Fraction&);



};




















#endif //FRACTION_CALCULATOR_FRACTION_H
