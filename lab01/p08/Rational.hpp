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

    Rational(const T &num, const T &den)
        : m_num(num), m_den(den)
    {
        if (m_den == 0)
        {
            throw std::runtime_error("Rational: denominator cannot be equal to zero");
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
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Rational<T> &x)
{
    out << x.num() << "/" << x.den();
    return out;
}