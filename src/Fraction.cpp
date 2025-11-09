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

Fraction &Fraction::operator += (const Fraction &other)  {
    this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
    this->denominator = this->denominator * other.denominator;
    normalize();
    return *this;

}

Fraction &Fraction::operator-=(const Fraction &other) {
    this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
    this->denominator = this->denominator * other.denominator;
    normalize();
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &other) {
    this->numerator = this->numerator * other.denominator;
    this->denominator = this->denominator * other.numerator;
    normalize();
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &other) {
    this->numerator = this->numerator * other.numerator;
    this->denominator = this->denominator * other.denominator;
    normalize();
    return *this;
}

void Fraction::ShowFraction() const {
    std::cerr << "Numerator: "<<this->numerator<<"\n"<<this->denominator<<"\n";

}

Fraction::Fraction(long long int s) {
    numerator = s;
    denominator = 1;
}

Fraction Fraction::operator+() const {
    Fraction result = *this;
    return result;
}

Fraction Fraction::operator-() const {
    Fraction result = *this;
    result.numerator = -result.numerator;
    return result;
}

Fraction operator + (Fraction s1,const Fraction& s2){
    s1 += s2;
    return s1;
}
Fraction operator - (Fraction s1,const Fraction& s2){
    s1 -= s2;
    return s1;
}
Fraction operator * (Fraction s1,const Fraction& s2){
    s1 *= s2;
    return s1;
}
Fraction operator / (Fraction s1,const Fraction& s2){
    s1 /= s2;
    return s1;
}

bool operator == (const Fraction& s1,const Fraction&s2){
    return ((s1.GetNumerator() == s2.GetNumerator()) &&
                (s1.GetDenominator() == s2.GetDenominator()));



}
bool operator != (const Fraction& s1,const Fraction& s2){
    return (s1.GetNumerator() != s2.GetNumerator()
    || s1.GetDenominator() != s2.GetDenominator());


}

bool operator >= (const Fraction& s1,const Fraction& s2){
    long long an = s1.GetNumerator();
    long long ad = s1.GetDenominator();
    long long bn = s2.GetNumerator();
    long long bd = s2.GetDenominator();

    long long t1 = bd / std::gcd(std::llabs(an), std::llabs(bd));
    long long t2 = ad / std::gcd(std::llabs(bn), std::llabs(ad));

    __int128 left  = (__int128)an * t1;
    __int128 right = (__int128)bn * t2;

    return left >= right;


}
bool operator <= (const Fraction& s1,const Fraction& s2){
    long long an = s1.GetNumerator();
    long long ad = s1.GetDenominator();
    long long bn = s2.GetNumerator();
    long long bd = s2.GetDenominator();

    long long t1 = bd / std::gcd(std::llabs(an), std::llabs(bd));
    long long t2 = ad / std::gcd(std::llabs(bn), std::llabs(ad));

    __int128 left  = (__int128)an * t1;
    __int128 right = (__int128)bn * t2;

    return left <= right;
}

std::ostream& operator << (std::ostream& output, const Fraction& F1){

    if(F1.GetDenominator() == 1){
        output<<F1.GetNumerator();
    }
    else{
        output<<F1.GetNumerator()<<"/"<<F1.GetDenominator();
    }
    return output;

}
std::istream& operator >> (std::istream& is, Fraction& f){

    Fraction backup = f;

    long long n = 0, d = 1;

    is >> std::ws;
    if (!(is >> n)) {
        is.setstate(std::ios::failbit);
        return is;
    }

    is >> std::ws;
    char ch;
    if (is.get(ch)) {
        if (ch == '/') {
            if (!(is >> d)) {
                is.setstate(std::ios::failbit);
                f = backup;
                return is;
            }
        } else {
            is.unget();
            d = 1;
        }
    } else {

        is.clear(is.rdstate() & ~std::ios::failbit);
        d = 1;
    }

    if (d == 0) {
        is.setstate(std::ios::failbit);
        f = backup;
        return is;
    }

    f = Fraction(n, d);
    return is;


}






