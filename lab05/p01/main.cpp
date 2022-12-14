#include "../../au/algol.hpp"

#include "VecInt.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

void p01();
void p02();
void printVecInt(const VecInt &v);

int main()
{
    try
    {
        p01();
        // p02();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
}

void p01()
{
    cout << "size of array: ";

    int n;
    cin >> n;

    VecInt v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    auReverse(begin(v), end(v));

    printVecInt(v);
}

void p02()
{
    std::cout << "enter integer numbers: " << std::endl;

    VecInt v;
    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    printVecInt(v);
    auReverse(begin(v), end(v));
    printVecInt(v);
}

void printVecInt(const VecInt &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}