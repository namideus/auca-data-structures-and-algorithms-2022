#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "../../au/algol.hpp"

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
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};

        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};

        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }
}

void p0102()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};

        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};

        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }
}

int main()
{
    p0101();
    p0102();
}