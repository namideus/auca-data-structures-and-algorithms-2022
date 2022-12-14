#include "VecInt.hpp"

VecInt::VecInt(const VecInt &other)
    : data(new int[other.cp]), sz(other.sz), cp(other.cp)
{
    for (size_t i = 0; i < sz; i++)
    {
        data[i] = other.data[i];
    }
}

VecInt &VecInt::operator=(const VecInt &other)
{
    if (&other != this)
    {
        int *newData = new int[other.cp];
        for (size_t i = 0; i < other.sz; i++)
        {
            newData[i] = other.data[i];
        }

        delete[] data;
        sz = other.sz;
        cp = other.cp;
        data = newData;
    }

    return *this;
}

void VecInt::pushBack(int x)
{
    if (sz == cp)
    {
        cp = (cp == 0) ? 1 : 2 * cp;
        int *newData = new int[cp];
        for (size_t i = 0; i < sz; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[sz++] = x;
}

bool operator==(const VecInt &a, const VecInt &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const VecInt &a, const VecInt &b)
{
    return !(a == b);
}
