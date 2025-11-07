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


