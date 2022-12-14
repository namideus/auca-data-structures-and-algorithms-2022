#include "../../au/algol.hpp"

#include "VecInt.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void printVecInt(const VecInt &v);

int main()
{
    VecInt v;
    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    // Value semantics: copy constructor, assignment operator
    VecInt w = v;

    reverse(begin(w), end(w));

    cout << (w == v ? "Palindrome" : "Not a palindrome") << endl;
}

void printVecInt(const VecInt &v)
{
    for (int e : v)
    {
        cout << e << " ";
    }
    cout << "\n";
}
