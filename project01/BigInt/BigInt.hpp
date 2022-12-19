#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

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
            std::string s_copy = s;

            while (s_copy.size() > 1 && s_copy.front() == '0')
            {
                s_copy.erase(s_copy.begin());
            }

            std::istringstream in(s_copy);
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

        while (z.mDigits.size() > 1 && z.mDigits.front() == 0)
            z.mDigits.erase(z.mDigits.begin());

        return z;
    }

    static BigInt multiplyAbsValues(const BigInt &a, const BigInt &b)
    {
        BigInt z;
        int n = a.mDigits.size(), m = b.mDigits.size();

        std::vector<int> v(n + m, 0);

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
        // auto itA = a.mDigits.rbegin();
        // auto itB = b.mDigits.rbegin();

        // BigInt z, r(0);

        // int carry = 0, a_val, b_val, s, cnt = 0;

        // while (itB != b.mDigits.rend() || itA != a.mDigits.rend())
        // {
        //     if (itB != b.mDigits.rend())
        //     {
        //         b_val = *itB;
        //         ++itB;
        //     }

        //     z.mDigits.clear();
        //     z.mDigits.resize(std::max(a.mDigits.size(), b.mDigits.size()) + 1);

        //     auto itZ = z.mDigits.rbegin();
        //     itA = a.mDigits.rbegin();

        //     s = 0;
        //     carry = 0;

        //     while (itA != a.mDigits.rend())
        //     {
        //         if (itA != a.mDigits.rend())
        //         {
        //             a_val = *itA;
        //             ++itA;
        //         }

        //         s = a_val * b_val + carry;

        //         if (s >= 10)
        //             carry = s / 10;
        //         else
        //             carry = 0;

        //         *itZ = s % 10;
        //         ++itZ;
        //     }

        //     if (carry != 0)
        //     {
        //         *itZ = carry;
        //     }
        //     while (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        //     {
        //         z.mDigits.erase(z.mDigits.begin());
        //     }
        //     for (int i = 0; i < cnt; i++)
        //     {
        //         z.mDigits.insert(z.mDigits.end(), 0);
        //     }
        //     r += z;

        //     cnt++;
        // }

        // return r;
    }

    static BigInt divideAbsValues(const BigInt &a, const BigInt &b)
    {
        BigInt t, z, copy_a;

        copy_a = a;

        reverse(begin(copy_a.mDigits), end(copy_a.mDigits));

        int i, lgcat = 0, cc, n = copy_a.mDigits.size(), m = b.mDigits.size();

        std::vector<int> cat(n, 0);

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

        return z;

        // r.mDigits.clear();
        // z.mDigits.clear();

        /* auto itA = a.mDigits.begin();

         while (itA != a.mDigits.end())
         {
           while (z < b && itA != a.mDigits.end())
           {
             z.mDigits.push_back(*itA);
             itA++;
           }

           if (z.mDigits.front() == 0)
           {
             z.mDigits.erase(z.mDigits.begin());
           }

           long cnt = 0;

           while (b * (cnt + 1) <= z)
             cnt++;

           p = b * cnt;

           //if (cnt > 0)
           r.mDigits.push_back(cnt);

           if (p == z)
           {
             if (itA != a.mDigits.end() && *itA != 0)
             {
               r.mDigits.push_back(0);
             }
             else
             {
               while (itA != a.mDigits.end() && *itA == 0)
               {
                 r.mDigits.push_back(0);
                 itA++;
               }
               if (itA != a.mDigits.end())
               {
                 r.mDigits.push_back(0);
               }
             }
           }

           z -= p;
         }
         while (r.mDigits.size() > 1 && r.mDigits.front() == 0)
         {
           r.mDigits.erase(r.mDigits.begin());
         }
         return r;*/
    }

    static BigInt modDivideAbsValues(const BigInt &a, const BigInt &b)
    {
        return a - b * (a / b);
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

    if (!a.mIsNegative && !b.mIsNegative)
    {
        if (a < b)
        {
            r = BigInt::subAbsValues(b, a);
            r.mIsNegative = true;
            return r;
        }

        return BigInt::subAbsValues(a, b);
    }

    if (a.mIsNegative && b.mIsNegative)
    {
        if (BigInt::abs(a) > BigInt::abs(b))
        {
            r = BigInt::subAbsValues(BigInt::abs(a), BigInt::abs(b));
            r.mIsNegative = true;
            return r;
        }

        if (BigInt::abs(b) > BigInt::abs(a))
        {
            return BigInt::subAbsValues(BigInt::abs(b), BigInt::abs(a));
        }
    }

    if (a.mIsNegative && !b.mIsNegative)
    {
        r = BigInt::addAbsValues(BigInt::abs(a), b);
        r.mIsNegative = true;
        return r;
    }

    if (!a.mIsNegative && b.mIsNegative)
    {
        return BigInt::addAbsValues(a, BigInt::abs(b));
    }

    if (a == b)
        return BigInt(0);

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

// To be fixed later
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
    {
        throw std::runtime_error("BigInt: modulus not positive");
    }

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

inline BigInt &operator%=(BigInt &a, const BigInt &b)
{
    a = a % b;
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