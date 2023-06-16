#include "fraction.h"
#include <numeric>

Fraction::Fraction(int n, int d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero!");
    }
    else if (n == 0) {
        numerator = 0;
        denominator = 1;
    }
    else {
        numerator = n;
        denominator = d;
        normalize();
    }
}

Fraction::Fraction(const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;
}

Fraction::Fraction(double decimal) {
    Fraction f = fromDecimal(decimal);
    numerator = f.numerator;
    denominator = f.denominator;
}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}
Fraction& Fraction::operator=(double decimal) {
    Fraction f = fromDecimal(decimal);
    numerator = f.numerator;
    denominator = f.denominator;
    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
    int n = numerator * other.denominator + other.numerator * denominator;
    int d = denominator * other.denominator;
    return Fraction(n, d);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int n = numerator * other.denominator - other.numerator * denominator;
    int d = denominator * other.denominator;
    return Fraction(n, d);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int n = numerator * other.numerator;
    int d = denominator * other.denominator;
    return Fraction(n, d);
}

Fraction Fraction::operator/(const Fraction& other) const {
    int n = numerator * other.denominator;
    int d = denominator * other.numerator;
    return Fraction(n, d);
}

std::string Fraction::toString() const {
    return numerator != 0 ? std::to_string(numerator) + "/" + std::to_string(denominator) : "0";
}

void Fraction::normalize() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}