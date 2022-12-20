#include <bits/stdc++.h>

// #include "BigInt.hpp"

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class BigInt
{
    friend std::ostream &operator<<(std::ostream &, const BigInt &);
    friend std::istream &operator>>(std::istream &, BigInt &);
    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator!=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);
    friend BigInt operator%(const BigInt &, const BigInt &);
    friend BigInt operator++(const BigInt &, int);
    friend BigInt &operator++(const BigInt &);
    friend BigInt operator--(const BigInt &, int);
    friend BigInt &operator--(const BigInt &);
    friend BigInt &operator+=(BigInt &, const BigInt &);
    friend BigInt &operator-=(BigInt &, const BigInt &);
    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt &operator/=(BigInt &, const BigInt &);
    friend BigInt &operator%=(BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt);
    friend BigInt operator-(const BigInt);

    std::vector<int> mDigits;
    bool mIsNegative;

public:
    static BigInt abs(const BigInt &);

    BigInt() : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(const std::string &s) : mIsNegative(false)
    {
        if (s.empty())
        {
            mDigits.push_back(0);
            throw std::runtime_error("invalid representation of BigInt value");
        }
        else
        {
            std::istringstream in(s);
            char ch;

            while (!(in >> ch))
            {
                continue;
            }

            in.putback(ch);

            std::string n;

            while (in >> ch)
            {
                if ((ch == '+' || ch == '-') && !std::isdigit(in.peek()))
                {
                    mDigits.push_back(0);
                    throw std::runtime_error("invalid representation of BigInt value");
                }

                if (!(std::isdigit(ch) || ch == '+' || ch == '-'))
                {
                    mDigits.push_back(0);
                    in.putback(ch);
                    throw std::runtime_error("invalid representation of BigInt value");
                }

                if (std::isdigit(ch) || ch == '-')
                {
                    n += ch;
                }

                while (in.get(ch) && std::isdigit(ch))
                {
                    n += ch;
                }

                if (!std::isdigit(ch))
                {
                    in.putback(ch);
                    break;
                }
            }

            mIsNegative = (n[0] == '-');

            for (int i = (mIsNegative ? 1 : 0); i < (int)n.size(); i++)
            {
                auto d = n[i];

                if (!std::isdigit(d))
                    throw std::runtime_error("invalid representation of BigInt value");

                mDigits.push_back(d - '0');
            }
        }
    }

    BigInt(const long long val) : BigInt(std::to_string(val)) {}

    static BigInt addAbsValues(const BigInt &a, const BigInt &b)
    {
        auto itA = a.mDigits.rbegin();
        auto itB = b.mDigits.rbegin();

        BigInt z;
        z.mDigits.resize(std::max(a.mDigits.size(), b.mDigits.size()) + 1);
        auto itZ = z.mDigits.rbegin();

        int carry = 0;
        while (itA != a.mDigits.rend() || itB != b.mDigits.rend())
        {
            int s = carry;

            if (itA != a.mDigits.rend())
            {
                s += *itA;
                ++itA;
            }

            if (itB != b.mDigits.rend())
            {
                s += *itB;
                ++itB;
            }
            *itZ = s % 10;
            carry = (s > 9) ? 1 : 0;
            ++itZ;
        }
        if (carry != 0)
        {
            *itZ = carry;
        }
        if (z.mDigits.size() > 1 && z.mDigits.front() == 0)
            z.mDigits.erase(z.mDigits.begin());

        return z;
    }

    static BigInt subAbsValues(const BigInt &a, const BigInt &b)
    {
        auto itA = a.mDigits.rbegin();
        auto itB = b.mDigits.rbegin();

        BigInt z;
        z.mDigits.resize(std::max(a.mDigits.size(), b.mDigits.size()));
        auto itZ = z.mDigits.rbegin();

        int carry = 0;
        while (itA != a.mDigits.rend() || itB != b.mDigits.rend())
        {
            int a_val, b_val, s = 0;

            if (itA != a.mDigits.rend())
            {
                s = *itA;
                a_val = *itA;
                ++itA;
            }

            if (carry)
            {
                if (s > 0)
                {
                    s = s - 1;
                    a_val = s;
                    carry = 0;
                }
                else if (s == 0)
                {
                    s = 9;
                    carry = 1;
                }
            }

            if (itB != b.mDigits.rend())
            {
                s -= *itB;
                b_val = *itB;
                ++itB;
            }

            if (s < 0)
            {
                carry = 1;
                s = 10 + a_val - b_val;
            }

            *itZ = s;
            ++itZ;
        }

        if (z.mDigits.size() > 1 && z.mDigits.front() == 0)
            z.mDigits.erase(z.mDigits.begin());

        return z;
    }

    static BigInt multiplyAbsValues(const BigInt &a, const BigInt &b)
    {
        BigInt z;
        int n = a.mDigits.size(), m = b.mDigits.size();

        vector<int> v(n + m, 0);

        int i = 0;

        for (auto itA = a.mDigits.rbegin(); itA != a.mDigits.rend(); itA++, i++)
        {
            int j = 0;

            for (auto itB = b.mDigits.rbegin(); itB != b.mDigits.rend(); itB++, j++)
                v[i + j] += (*itA) * (*itB);
        }

        n += m;
        z.mDigits.resize(v.size());

        auto itZ = z.mDigits.rbegin();

        for (int s, i = 0, t = 0; i < n && itZ != z.mDigits.rend(); i++, itZ++)
        {
            s = t + v[i];
            v[i] = s % 10;
            t = s / 10;
            *itZ = v[i];
        }

        while (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }

        return z;
    }

    static BigInt divideAbsValues(const BigInt &a, const BigInt &b)
    {
        BigInt t, z, copy_a;

        copy_a = a;

        reverse(begin(copy_a.mDigits), end(copy_a.mDigits));

        int i, lgcat = 0, cc, n = copy_a.mDigits.size(), m = b.mDigits.size();

        vector<int> cat(n, 0);

        for (i = n - 1; t * 10 + copy_a.mDigits[i] < b; i--)
        {
            t *= 10;
            t += copy_a.mDigits[i];
        }

        for (; i >= 0; i--)
        {
            t = t * 10 + copy_a.mDigits[i];
            for (cc = 9; cc * b > t; cc--)
                ;
            t -= cc * b;
            cat[lgcat++] = cc;
        }

        z.mDigits.resize(cat.size());

        for (i = 0; i < lgcat; i++)
            z.mDigits[i] = cat[lgcat - i - 1];

        z.mDigits.resize(lgcat);

        reverse(begin(z.mDigits), end(z.mDigits));

        while (z.mDigits.size() > 1 && z.mDigits.front() == 0)
            z.mDigits.erase(z.mDigits.begin());

        return z;
    }

    static BigInt modDivideAbsValues(const BigInt &a, const BigInt &b)
    {
        BigInt z = a - b * (a / b);
        while (z.mDigits.size() > 1 && z.mDigits.front() == 0)
            z.mDigits.erase(z.mDigits.begin());
        return z;
    }
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mIsNegative) /*&& x > 0)*/
    {
        out << "-";
    }
    for (auto d : x.mDigits)
    {
        out << d;
    }
    return out;
}

inline std::istream &operator>>(std::istream &in, BigInt &x)
{
    char ch;

    if (!(in >> ch))
    {
        return in;
    }

    if ((ch == '+' || ch == '-') && !std::isdigit(in.peek()))
    {
        in.setstate(std::ios_base::failbit);
        return in;
    }

    if (!(std::isdigit(ch) || ch == '+' || ch == '-'))
    {
        in.putback(ch);
        in.setstate(std::ios_base::failbit);
        return in;
    }

    std::string s;

    if (std::isdigit(ch) || ch == '-')
    {
        s += ch;
    }

    while (in.get(ch) && std::isdigit(ch))
    {
        s += ch;
    }

    x = BigInt(s);

    if (!std::isdigit(ch))
    {
        in.putback(ch);
        return in;
    }

    return in;
}

inline bool operator==(const BigInt &a, const BigInt &b)
{
    return a.mIsNegative == b.mIsNegative && a.mDigits == b.mDigits;
}

inline bool operator!=(const BigInt &a, const BigInt &b)
{
    return !(a == b);
}

inline bool operator<(const BigInt &a, const BigInt &b)
{
    if (a.mIsNegative && !b.mIsNegative)
        return true;

    if (!(a.mIsNegative || b.mIsNegative) && a.mDigits.size() < b.mDigits.size())
        return true;

    if (a.mIsNegative && b.mIsNegative && a.mDigits.size() > b.mDigits.size())
        return true;

    if (a.mIsNegative && b.mIsNegative && a.mDigits > b.mDigits && a.mDigits.size() == b.mDigits.size())
        return true;

    if (!(a.mIsNegative || b.mIsNegative) && a.mDigits < b.mDigits && a.mDigits.size() == b.mDigits.size())
        return true;

    return false;
}

inline bool operator>(const BigInt &a, const BigInt &b)
{
    return b < a;
}

inline bool operator>=(const BigInt &a, const BigInt &b)
{
    return !(a < b);
}

inline bool operator<=(const BigInt &a, const BigInt &b)
{
    return !(b < a);
}

inline BigInt BigInt::abs(const BigInt &x)
{
    BigInt r = x;
    if (r.mIsNegative)
        r.mIsNegative = false;
    return r;
}

inline BigInt operator+(const BigInt &a, const BigInt &b)
{
    BigInt r(0);

    if (!a.mIsNegative && !b.mIsNegative)
    {
        return BigInt::addAbsValues(a, b);
    }

    if (a.mIsNegative && b.mIsNegative)
    {
        r = BigInt::addAbsValues(a, b);
        r.mIsNegative = true;
        return r;
    }

    if (a.mIsNegative && !b.mIsNegative)
    {
        if (BigInt::abs(a) > b)
        {
            r = BigInt::subAbsValues(a, b);
            r.mIsNegative = true;
            return r;
        }
        if (BigInt::abs(a) < b)
        {
            return BigInt::subAbsValues(b, a);
        }
    }

    if (!a.mIsNegative && b.mIsNegative)
    {
        if (a > BigInt::abs(b))
        {
            return BigInt::subAbsValues(a, b);
        }

        if (a < BigInt::abs(b))
        {
            r = BigInt::subAbsValues(b, a);
            r.mIsNegative = true;
            return r;
        }
    }

    return r;
}

inline BigInt operator-(const BigInt &a, const BigInt &b)
{
    BigInt r(0);

    if (!(a.mIsNegative || b.mIsNegative))
    {
        if (a < b)
        {
            r = BigInt::subAbsValues(b, a);
            r.mIsNegative = true;
            return r;
        }

        if (a > b)
        {
            return BigInt::subAbsValues(a, b);
        }
    }

    if (a.mIsNegative && b.mIsNegative)
    {
        if (a.mDigits.size() > b.mDigits.size())
        {
            r = BigInt::subAbsValues(a, b);
            r.mIsNegative = true;
            return r;
        }

        if (a.mDigits.size() < b.mDigits.size())
        {
            return BigInt::subAbsValues(b, a);
        }
    }

    if (a.mIsNegative && !b.mIsNegative)
    {
        r = BigInt::addAbsValues(a, b);
        r.mIsNegative = true;
        return r;
    }

    if (!a.mIsNegative && b.mIsNegative)
    {
        return BigInt::addAbsValues(a, b);
    }

    return r;
}

inline BigInt operator*(const BigInt &a, const BigInt &b)
{
    BigInt r(0);

    if (a == 0 || b == 0)
        return r;

    if (a == 1)
        return b;

    if (b == 1)
        return a;

    if ((!a.mIsNegative && !b.mIsNegative) || (a.mIsNegative && b.mIsNegative))
    {
        return BigInt::multiplyAbsValues(a, b);
    }

    if ((!a.mIsNegative && b.mIsNegative) || (a.mIsNegative && !b.mIsNegative))
    {
        r = BigInt::multiplyAbsValues(a, b);
        r.mIsNegative = true;
    }

    return r;
}

inline BigInt operator/(const BigInt &a, const BigInt &b)
{
    BigInt r(0);

    if (b == 0)
    {
        throw std::runtime_error("division by zero occurred!");
    }
    if (a == 0)
    {
        return BigInt(0);
    }
    if (a == b)
    {
        return BigInt(1);
    }
    if (b == 1)
    {
        return a;
    }
    if ((a.mIsNegative && b.mIsNegative) || !(a.mIsNegative || b.mIsNegative))
    {
        if (a.mDigits.size() == b.mDigits.size())
        {
            if (a > b)
            {
                return BigInt(1);
            }
            if (a < b)
            {
                return BigInt(0);
            }
        }
        if (a.mDigits.size() < b.mDigits.size())
        {
            return BigInt(0);
        }
        if (a.mDigits.size() > b.mDigits.size())
        {
            return BigInt::divideAbsValues(BigInt::abs(a), BigInt::abs(b));
        }
    }
    if (a.mIsNegative && !b.mIsNegative)
    {
        if (BigInt::abs(a) < b)
        {
            return BigInt(0);
        }
        if (BigInt::abs(a) > b)
        {
            r = BigInt::divideAbsValues(BigInt::abs(a), BigInt::abs(b));
            r.mIsNegative = true;
            return r;
        }
    }
    if (!a.mIsNegative && b.mIsNegative)
    {
        if (a < BigInt::abs(b))
        {
            return BigInt(0);
        }
        if (a > BigInt::abs(b))
        {
            r = BigInt::divideAbsValues(BigInt::abs(a), BigInt::abs(b));
            r.mIsNegative = true;
            return r;
        }
    }
    return r;
}

inline BigInt operator%(const BigInt &a, const BigInt &b)
{
    BigInt r;

    if (a.mIsNegative && !b.mIsNegative)
    {
        r = BigInt::modDivideAbsValues(BigInt::abs(a), BigInt::abs(b));
        r.mIsNegative = true;
        return r;
    }

    if (b.mIsNegative)
        throw runtime_error("BigInt: modulus not positive");

    if (a < b)
        return a;

    if (a == b)
        return 0;

    return BigInt::modDivideAbsValues(a, b);
}

inline BigInt operator++(BigInt &x, int)
{
    x = x + 1;
    return x;
}

inline BigInt &operator++(BigInt &x)
{
    x++;
    return x;
}

inline BigInt operator--(BigInt &x, int)
{
    x = x - 1;
    return x;
}

inline BigInt &operator--(BigInt &x)
{
    x--;
    return x;
}

inline BigInt &operator+=(BigInt &a, const BigInt &b)
{
    a = a + b;
    return a;
}

inline BigInt &operator-=(BigInt &a, const BigInt &b)
{
    a = a - b;
    return a;
}

inline BigInt &operator*=(BigInt &a, const BigInt &b)
{
    a = a * b;
    return a;
}

inline BigInt &operator/=(BigInt &a, const BigInt &b)
{
    a = a / b;
    return a;
}

inline BigInt operator-(const BigInt x)
{
    BigInt r = x;
    r.mIsNegative = (r.mIsNegative ? false : true);
    return r;
}

inline BigInt operator+(const BigInt x)
{
    BigInt r = x;
    return r;
}

//--------------------------------------usage of BigInt--------------------------------------------------------------
BigInt fib(long n)
{
    BigInt a = 0;
    BigInt b = 1;
    while (n-- > 1)
    {
        BigInt t = a;
        a = b;
        b += t;
    }
    return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long n;

    while (cin >> n)
    {
        cout << "The Fibonacci number for " << n << " is " << fib(n) << "\n";
        // cout << "The Fibonacci number for " << n << " is " << m[n] << "\n";
    }
}