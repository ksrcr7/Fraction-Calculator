

#ifndef FRACTION_CALCULATOR_FRACTION_H
#define FRACTION_CALCULATOR_FRACTION_H

#include <iostream>


class Fraction{
private:
    long long numerator,denominator;
    void normalize();


public:
    explicit Fraction(long long,long long);
    [[nodiscard]] long long GetNumerator()const;
    [[nodiscard]] long long GetDenominator()const;
    void ShowFraction()const;
    Fraction operator += (const Fraction&);
    Fraction operator -= (const Fraction&);
    Fraction operator /= (const Fraction&);
    Fraction operator *= (const Fraction&);




};
Fraction operator + (Fraction,const Fraction&);
Fraction operator - (Fraction,const Fraction&);
Fraction operator * (Fraction,const Fraction&);
Fraction operator / (Fraction,const Fraction&);




















#endif //FRACTION_CALCULATOR_FRACTION_H
