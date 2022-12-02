#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(const string &name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};

void p0101()
{
    vector<int> n = {3, 1, 20, 4, 7, 0, 5};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
        }
    }
}

int main()
{
}