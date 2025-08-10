#include <iostream>
#include <memory>

class Resource
{
    private:
    int* data;

    public:
    Resource()
    {
        data = new int[100];
        std::cout << "Resource acquired\n";
    }
    ~Resource()
    {
        delete[] data;
        std::cout << "Resource released\n";
    }

    void use()
    {
        std::cout << "Using resource\n";
    }

};

void test()
{
    auto r = std::make_unique<Resource>();
    r->use();
}

int main()
{
    test();
}