#include <iostream>

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    int num1 = 10;
    int num2 = 15;
    std::cout << max(num1, num2);
}