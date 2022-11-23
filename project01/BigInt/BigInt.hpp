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
    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator!=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt operator++(const BigInt &, int);
    friend BigInt &operator++(const BigInt &);
    friend BigInt operator--(const BigInt &, int);
    //    friend BigInt &operator--(const BigInt &);

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

inline bool operator==(const BigInt &a, const BigInt &b)
{
    if (a.mDigits.size() != b.mDigits.size())
        return false;

    if (a.mIsNegative != b.mIsNegative)
        return false;

    auto itA = a.mDigits.begin();
    auto itB = b.mDigits.begin();
    while (itA != a.mDigits.end() && itB != b.mDigits.end())
    {
        if (*itA != *itB)
            return false;

        itA++;
        itB++;
    }

    return true;
}

inline bool operator!=(const BigInt &a, const BigInt &b)
{
    return !(a == b);
}

inline bool operator<(const BigInt &a, const BigInt &b)
{
    if (a.mIsNegative && !b.mIsNegative)
        return true;

    if (!a.mIsNegative && b.mIsNegative)
        return false;

    if (a == b)
        return false;

    if (a.mDigits.size() < b.mDigits.size() && (!a.mIsNegative && !b.mIsNegative))
        return true;

    if (a.mDigits.size() < b.mDigits.size() && a.mIsNegative && b.mIsNegative)
        return false;

    if (a.mDigits.size() > b.mDigits.size() && (!a.mIsNegative && !b.mIsNegative))
        return false;

    if (a.mDigits.size() > b.mDigits.size() && a.mIsNegative && b.mIsNegative)
        return true;

    std::string a_str = "";
    std::string b_str = "";
    auto itA = a.mDigits.begin();
    auto itB = b.mDigits.begin();
    while (itA != a.mDigits.end() && itB != b.mDigits.end())
    {
        a_str += std::to_string(*itA);
        b_str += std::to_string(*itB);
        itA++;
        itB++;
    }

    if (!a.mIsNegative && !b.mIsNegative && a_str < b_str)
        return true;

    if (a.mIsNegative && b.mIsNegative && a_str > b_str)
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

inline BigInt operator++(BigInt &x, int)
{
    x = x + BigInt("1");
    return x;
}

inline BigInt &operator++(BigInt &x)
{
    x++;
    return x;
}

// Testing subtraction
inline BigInt operator-(const BigInt &a, const BigInt &b)
{
    auto itA = a.mDigits.rbegin();
    auto itB = b.mDigits.rbegin();

    BigInt z;
    z.mDigits.resize(std::max(a.mDigits.size(), b.mDigits.size()) + 1);
    auto itZ = z.mDigits.rbegin();

    int carry = 0;
    while (itA != a.mDigits.rend() || itB != b.mDigits.rend())
    {
        int s = 0;

        if (itA != a.mDigits.rend())
        {
            s += *itA;
            ++itA;
        }

        s = (s > 0 && carry) ? s - 1 : s;
        s = (s == 0 && carry) ? 9 : s;

        if (itB != b.mDigits.rend())
        {
            s -= *itB;
            ++itB;
        }

        carry = (s < 0) ? 1 : 0;

        s = (s < 0) ? 10 + *itA - *itB : s;

        *itZ = s;
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