#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

#include "../p08/Rational.hpp"

using namespace std;

using Fraction = Rational<int64_t>;

bool parseExpr(const string &line, Fraction &r1, char &op, Fraction &r2);
void computeAndShow(const Fraction &r1, char op, const Fraction &r2);

int main()
{
    cout << boolalpha;

    for (string line; getline(cin, line);)
    {
        try
        {
            Fraction r1;
            char op;
            Fraction r2;

            if (!parseExpr(line, r1, op, r2))
            {
                cout << "Incorrect expression: " << line << endl;
            }
            else
            {
                computeAndShow(r1, op, r2);
            }
        }
        catch (runtime_error &e)
        {
            cout << e.what() << endl;
        }
    }
}

bool parseExpr(const string &line, Fraction &r1, char &op, Fraction &r2)
{
    const string operations = "+-*:<>=#";

    istringstream sinp(line);

    if (!(sinp >> r1))
    {
        return false;
    }

    if (!(sinp >> op) || operations.find(op) == string::npos)
    {
        return false;
    }

    char c;
    if (!(sinp >> r2) || sinp >> c)
    {
        return false;
    }

    return true;
}

void computeAndShow(const Fraction &r1, char op, const Fraction &r2)
{
    switch (op)
    {
    case '+':
        cout << r1 + r2 << endl;
        break;
    case '-':
        cout << r1 - r2 << endl;
        break;
    case '*':
        cout << r1 * r2 << endl;
        break;
    case ':':
        cout << r1 / r2 << endl;
        break;
    case '=':
        cout << (r1 == r2) << endl;
        break;
    case '#':
        cout << (r1 != r2) << endl;
        break;
    case '<':
        cout << (r1 < r2) << endl;
        break;
    case '>':
        cout << (r1 > r2) << endl;
        break;
    }
}