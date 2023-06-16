#include <iostream>
#include "fraction.h"

int main() {
    Fraction f(-2, 4);
    Fraction g(-1, -3);
    std::cout << "frac1: " << f << std::endl;
    std::cout << "frac2: " << g << std::endl;
    std::cout << "+: " << f + g << std::endl;
    std::cout << "-: " << f - g << std::endl;
    std::cout << "*: " << f * g << std::endl;
    std::cout << "/: " << f / g << std::endl;
    std::cout << "==: " << (f == g) << std::endl;
    std::cout << "!=: " << (f != g) << std::endl;
    std::cout << ">=: " << (f >= g) << std::endl;
    std::cout << "<=: " << (f <= g) << std::endl;
    std::cout << ">: " << (f > g) << std::endl;
    std::cout << "<: " << (f < g) << std::endl;
    std::cout << "tostring: " << f.toString() << std::endl;
    std::cout << "double: " << 1.0 * f << std::endl;
    /* 3 methods to convert from decimal */
    std::cout << "fromDecimal: " << Fraction::fromDecimal(1.414) << std::endl;
    Fraction h = 1.2;
    std::cout << "fromDecimal: " << h << std::endl;
    Fraction i(-1.5);
    std::cout << "fromDecimal: " << i << std::endl;
    /* special case */
    std::cout << "special case: " << Fraction(0,-4) << std::endl;
    /* inserter */
    Fraction j;
    std::cout << "Enter a fraction:";
    std::cin >> j;
    std::cout << "inserter: " << j << std::endl;
    return 0;
}