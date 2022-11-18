#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &, const BigInt &);
    friend std::istream &operator>>(std::istream &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);

    std::vector<int> mDigits;
    bool mIsNegative;

public:
    BigInt() : mIsNegative(false)
    {
        mDigits.push_back(0);
    }
    BigInt(const std::string &s)
    {
        if (s.empty())
            throw std::runtime_error("invalid representation of BigInt value");

        mIsNegative = (s[0] == '-');

        for (int i = (mIsNegative ? 1 : 0); i < (int)s.size(); i++)
        {
            auto d = s[i];

            if (!isdigit(d))
                throw std::runtime_error("invalid representation of BigInt value");

            mDigits.push_back(d - '0');
        }
    }
    BigInt(const int val) : BigInt(std::to_string(val)) {}

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
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mIsNegative)
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
    std::string d;
    in >> d;
    x = BigInt(d);
    return in;
}

inline BigInt operator+(const BigInt &a, const BigInt &b)
{
    if (!a.mIsNegative && !b.mIsNegative)
    {
        return BigInt::addAbsValues(a, b);
    }
    else if (a.mIsNegative && b.mIsNegative)
    {
        BigInt c = BigInt::addAbsValues(a, b);
        c.mIsNegative = true;
        return c;
    }

    throw std::runtime_error("not implemented yet");
}

// std::string sum = "";
//     std::vector<int> a = b1.mDigits;
//     std::vector<int> b = b2.mDigits;

//     int size_a = (int)a.size();
//     int size_b = (int)b.size();

//     std::vector<int> z(std::abs(size_a - size_b), 0);

//     if (size_a > size_b)
//         b.insert(b.begin(), z.begin(), z.end());
//     else if (size_b > size_a)
//         a.insert(a.begin(), z.begin(), z.end());

//     for (int i = std::max(size_a, size_b) - 1; i >= 1; i--)
//     {
//         b[i] += a[i];
//         b[i - 1] += b[i] / 10;
//         b[i] %= 10;
//     }

//     b[0] += a[0];
//     if (b[0] / 10 != 0)
//     {
//         int tmp = b[0];
//         b[0] = tmp % 10;
//         b.insert(b.begin(), tmp / 10);
//     }

//     BigInt res;
//     res.mDigits.pop_back();
//     for (auto d : b)
//         res.mDigits.push_back(d);

//     if (b1.mIsNegative && b2.mIsNegative)
//         res.mIsNegative = true;

//     return res;
