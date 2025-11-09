

#ifndef FRACTION_CALCULATOR_FRACTION_H
#define FRACTION_CALCULATOR_FRACTION_H

#include <iostream>


class Fraction{
private:
    long long numerator,denominator;
    void normalize();


public:
    explicit Fraction() = default;
    explicit Fraction(long long,long long);
    explicit Fraction(long long);
    [[nodiscard]] long long GetNumerator()const;
    [[nodiscard]] long long GetDenominator()const;
    void ShowFraction()const;
    Fraction& operator += (const Fraction&);
    Fraction& operator -= (const Fraction&);
    Fraction& operator /= (const Fraction&);
    Fraction& operator *= (const Fraction&);
    Fraction operator + ()const;
    Fraction operator - ()const;






};
Fraction operator + (Fraction,const Fraction&);
Fraction operator - (Fraction,const Fraction&);
Fraction operator * (Fraction,const Fraction&);
Fraction operator / (Fraction,const Fraction&);

bool operator == (const Fraction&,const Fraction&);
bool operator != (const Fraction&,const Fraction&);
bool operator >= (const Fraction&,const Fraction&);
bool operator <= (const Fraction&,const Fraction&);




















#endif //FRACTION_CALCULATOR_FRACTION_H
