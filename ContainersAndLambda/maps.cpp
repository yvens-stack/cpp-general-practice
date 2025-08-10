#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::map<std::string, int> grades
{
    {"Bob", 5},
    {"Tom", 4},
    {"Mark", 3},
    {"Fred", 2}
};

int main()
{
    std::vector<std::pair<std::string, int>> gradeVec;

    for (const auto& pair : grades)
    {
        gradeVec.push_back(pair);
    }

    std::sort(gradeVec.begin(), gradeVec.end(),
              [](const auto& a, const auto& b) {return a.second > b.second;});

    for (const auto& i : gradeVec)
    {
        std::cout << i.first << " " << i.second << "\n";
    }

    int evens = std::count_if(gradeVec.begin(), gradeVec.end(),
                              [](const auto& n) {return n.second % 2 == 0;});

    std::cout << evens;

}