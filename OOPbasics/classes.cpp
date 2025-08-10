#include <iostream>
#include <string>

class Person
{
    private:
    std::string m_name;
    int m_age = 0;

    public:
    Person(std::string name, int age)
        : m_name {name}, m_age {age}
    {}

    void introduce()
    {
        std::cout << "Hi, I'm " << m_name << ". I'm " << m_age << " years old.";
    }
};

int main()
{
    Person joe {"Joe", 20};
    joe.introduce();
}