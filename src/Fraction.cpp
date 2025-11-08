#include "Fraction.h"
#include <numeric>
#include <cstdlib>
#include <stdexcept>


Fraction::Fraction(long long int a, long long int b) {
    numerator = a;
    denominator = b;
    normalize();


}

void Fraction::normalize() {
    if(denominator == 0){
        throw std::invalid_argument("Denominator must not be zero.");
    }
    if(numerator == 0){
        denominator = 1;
        return;
    }
    if(denominator < 0){
        numerator = -numerator;
        denominator = -denominator;
    }

    long long g = std::gcd(std::llabs(numerator),std::llabs(denominator));
    numerator /= g;
    denominator /= g;




}

long long Fraction::GetNumerator() const {
    return numerator;
}

long long Fraction::GetDenominator() const {
    return denominator;
}

Fraction Fraction::operator += (const Fraction &other)  {
    this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
    this->denominator = this->denominator * other.denominator;
    normalize();
    return *this;

}

Fraction Fraction::operator-=(const Fraction &other) {
    this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
    this->denominator = this->denominator * other.denominator;
    normalize();
    return *this;
}

Fraction Fraction::operator/=(const Fraction &other) {
    this->numerator = this->numerator * other.denominator;
    this->denominator = this->denominator * other.numerator;
    normalize();
    return *this;
}

Fraction Fraction::operator*=(const Fraction &other) {
    this->numerator = this->numerator * other.numerator;
    this->denominator = this->denominator * other.denominator;
    normalize();
    return *this;
}


