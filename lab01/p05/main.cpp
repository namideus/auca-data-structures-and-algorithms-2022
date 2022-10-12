#include <iostream>
#include <algorithm>

using namespace std;

//
template <typename T>
void auSwap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

// pass by value
void badSwap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

// pass by reference
void goodSwap01(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

// pass a pointer by value
void goodSwap02(int *pA, int *pB)
{
    int t = *pA;
    *pA = *pB;
    *pB = t;
}

int main()
{
    cout << "1st int: ";
    int a;
    cin >> a;

    cout << "2nd int: ";
    int b;
    cin >> b;

    cout << "Standard swap:" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "Bad swap:" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    badSwap(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "Good swap 1:" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap01(a, b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    cout << "Good swap 2:" << endl;
    cout << "Before swap a = " << a << ", b = " << b << endl;
    goodSwap02(&a, &b);
    cout << "After swap a = " << a << ", b = " << b << endl;

    double d1 = 1.6;
    double d2 = 3.14;
    cout << "Geneal swap for doubles:" << endl;
    cout << "Before swap d1 = " << d1 << ", d2 = " << d2 << endl;
    auSwap(d1, d2);
    cout << "After swap d1 = " << d1 << ", d2 = " << d2 << endl;

    string s1 = "hello";
    string s2 = "world";
    cout << "Geneal swap for strings:" << endl;
    cout << "Before swap s1 = " << s1 << ", s2 = " << s2 << endl;
    auSwap(s1, s2);
    cout << "After swap s1 = " << s1 << ", s2 = " << s2 << endl;
}