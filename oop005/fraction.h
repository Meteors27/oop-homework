#ifndef _FRACTION_H_
#define _FRACTION_H_
#include <string>
#include <sstream>

class Fraction {
public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n, int d);
    Fraction(const Fraction& other);
    Fraction(double decimal);

    Fraction& operator=(const Fraction& other);
    Fraction& operator=(double decimal);
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }
    bool operator<=(const Fraction& other) const {
        return numerator * other.denominator <= other.numerator * denominator;
    }
    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }
    bool operator!=(const Fraction& other) const {
        return numerator * other.denominator != other.numerator * denominator;
    }
    bool operator>=(const Fraction& other) const {
        return numerator * other.denominator >= other.numerator * denominator;
    }
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    operator double() const {
        return static_cast<double>(numerator) / denominator;
    }

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.toString();
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Fraction& fraction) {
        std::string input;
        is >> input;
        int slashPos = input.find("/");
        if (slashPos != std::string::npos) {
            std::string numeratorStr = input.substr(0, slashPos);
            std::string denominatorStr = input.substr(slashPos + 1);
            Fraction f(std::stoi(numeratorStr), std::stoi(denominatorStr));
            fraction = f;
        }
        return is;
    }

    static Fraction fromDecimal(double decimal) {
        int n = static_cast<int>(decimal * precision);
        int d = precision;
        return Fraction(n, d);
    }
    
private:
    static constexpr int precision = 1000000;
    int numerator;
    int denominator;
    void normalize();
};

#endif