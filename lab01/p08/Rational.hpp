#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Rational
{
    T m_num;
    T m_den;

public:
    Rational()
        : m_num(0), m_den(1)
    {
    }

    Rational(const T &num, const T &den = 1)
        : m_num(num), m_den(den)
    {
        if (m_den == 0)
        {
            throw std::runtime_error("Rational: denominator cannot be equal to zero");
        }

        T a = m_num < 0 ? -m_num : m_num;
        T b = m_den < 0 ? -m_den : m_den;

        while (b != 0)
        {
            T r = a % b;
            a = b;
            b = r;
        }

        m_num /= a;
        m_den /= a;

        if (m_den < 0)
        {
            m_den = -m_den;
            m_num = -m_num;
        }
    }

    const T &num() const
    {
        return m_num;
    }

    const T &den() const
    {
        return m_den;
    }

    Rational operator+(const Rational &other)
    {
        T num = m_num * other.m_den + m_den * other.m_num;
        T den = m_den * other.m_den;

        return Rational(num, den);
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Rational<T> &x)
{
    out << x.num() << "/" << x.den();
    return out;
}

template <typename T>
std::istream &operator>>(std::istream &in, Rational<T> &r)
{
    T num;
    if (!(in >> num))
    {
        return in;
    }

    char ch;
    if (!in.get(ch))
    {
        return in;
    }

    if (ch != '/')
    {
        in.putback(ch);
        in.setstate(std::ios_base::failbit);
        return in;
    }

    if (!in.get(ch))
    {
        return in;
    }

    if (ch == '+' || ch == '-' || isdigit(ch))
    {
        in.putback(ch);
    }
    else
    {
        in.putback(ch);
        in.setstate(std::ios_base::failbit);
        return in;
    }

    T den;
    if (!(in >> den))
    {
        return in;
    }

    r = Rational<T>(num, den);

    return in;
}

template <typename T>
Rational<T> operator+(const Rational<T> &a, const Rational<T> &b)
{
    T num = a.num() * b.den() + a.den() * b.num();
    T den = a.den() * b.den();

    return Rational<T>(num, den);
}

template <typename T>
Rational<T> operator-(const Rational<T> &a, const Rational<T> &b)
{
    T num = a.num() * b.den() - a.den() * b.num();
    T den = a.den() * b.den();

    return Rational<T>(num, den);
}

template <typename T>
Rational<T> operator*(const Rational<T> &a, const Rational<T> &b)
{
    T num = a.num() * b.num();
    T den = a.den() * b.den();

    return Rational<T>(num, den);
}

template <typename T>
Rational<T> operator/(const Rational<T> &a, const Rational<T> &b)
{
    if (b == Rational<T>())
    {
        throw std::runtime_error("Rational: division by zero");
    }
    T num = a.num() * b.den();
    T den = a.den() * b.num();

    return Rational<T>(num, den);
}

template <typename T>
bool operator==(const Rational<T> &a, const Rational<T> &b)
{
    return a.num() == b.num() && a.den() == b.den();
}

template <typename T>
bool operator!=(const Rational<T> &a, const Rational<T> &b)
{
    return !(a == b);
}

template <typename T>
bool operator<(const Rational<T> &a, const Rational<T> &b)
{
    return a.num() * b.den() < a.den() * b.num();
}

template <typename T>
bool operator>(const Rational<T> &a, const Rational<T> &b)
{
    return b < a;
}

template <typename T>
bool operator>=(const Rational<T> &a, const Rational<T> &b)
{
    return !(a < b);
}

template <typename T>
bool operator<=(const Rational<T> &a, const Rational<T> &b)
{
    return !(b < a);
}
