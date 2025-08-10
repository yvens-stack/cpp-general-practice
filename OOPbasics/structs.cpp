#include <iostream>

struct Fraction
{
    int numerator = 0;
    int denominator = 1;
};

Fraction getFraction()
{
    Fraction temp;
    std::cout << "Numerator: \n";
    std::cin >> temp.numerator;
    std::cout << "Denominator: \n";
    std::cin >> temp.denominator;

    return temp;
}

Fraction multiply(const Fraction& f1, const Fraction& f2)
{
    return {f1.numerator * f2.numerator, f1.denominator * f2.denominator};
}

void printFraction(const Fraction& temp)
{
    std::cout << temp.numerator << "/" << temp.denominator;
}

int main()
{
    Fraction f1 = getFraction();
    Fraction f2 = getFraction();

    std::cout << "Product: ";
    printFraction(multiply(f1, f2));

    return 0;
}