#include <iostream>

template <typename T>
class Box
{
    T value;
    public:
    Box(T v) : value(v) {}
    T getValue() const {return value;}
    void print() const {std::cout << value << "\n";}
};

template<>
void Box<int>::print() const
{
    std::cout << "The value is number " << value << "\n";
}

template<>
void Box<std::string>::print() const
{
    std::cout << "The value is a string " << value << "\n";
}

int main()
{
    Box<int> intBox(5);
    Box<std::string> strBox("Str");

    intBox.print();
    strBox.print();
}