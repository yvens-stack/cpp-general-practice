#include <iostream>
#include <math.h>

class Shape
{
    public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape
{
    private:
    int m_a = 0;
    int m_b = 0;

    public:
    Rectangle(int a, int b) : m_a{a}, m_b{b} {}

    double getArea() override
    {
        return m_a * m_b;
    }
};

class Circle : public Shape
{
    private:
    int m_radius = 0;

    public:
    Circle(int radius) : m_radius{radius} {}
    
    double getArea() override
    {
        return(pow(m_radius, 2) * M_PI);
    }
};

int main()
{
    Rectangle rec = {2, 3};
    Circle cir = {5};

    std::cout << "The area of the rectangle is " << rec.getArea() << "\n";
    std::cout << "The area of the circle is " << cir.getArea() << "\n";
}