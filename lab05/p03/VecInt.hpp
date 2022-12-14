#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>

#ifdef AUCA_DEBUG
#include <string>
#endif

class VecInt
{
    int *data;
    size_t sz;
    size_t cp;

public:
    static size_t numOfCopies;

    using Iter = int *;
    using CIter = const int *;

    // Default constructor
    VecInt()
        : data(nullptr), sz(0), cp(0)
    {
    }

    explicit VecInt(size_t aSz, int initValue = 0)
        : data(new int[aSz]), sz(aSz), cp(aSz)
    {
        for (size_t i = 0; i < sz; i++)
        {
            data[i] = initValue;
        }
    }

    VecInt(std::initializer_list<int> initList)
        : VecInt()
    {
        for (auto e : initList)
        {
            pushBack(e);
        }
    }

    // copy constructor
    VecInt(const VecInt &other);

    // assignment operator
    VecInt &operator=(const VecInt &other);

    // move constructor
    // VecInt(VecInt &&other);

    // move assignment operator
    // VecInt &operator=(VecInt &&other) noexcept;

    ~VecInt()
    {
        std::cout << "~VecInt: number of released int values: " << sz << std::endl;
        delete[] data;
    }

    std::size_t size() const
    {
        return sz;
    }

    Iter begin()
    {
        return data;
    }

    CIter begin() const
    {
        return data;
    }

    Iter end()
    {
        return data + sz;
    }

    CIter end() const
    {
        return data + sz;
    }

    const int &operator[](std::size_t index) const
    {
#ifdef AUCA_DEBUG
        if (sz <= index)
        {
            throw std::runtime_error("VecInt: incorrect index: " + std::to_string(index));
        }
#endif
        return data[index];
    }

    int &operator[](std::size_t index)
    {
#ifdef AUCA_DEBUG
        if (sz <= index)
        {
            throw std::runtime_error("VecInt: incorrect index: " + std::to_string(index));
        }
#endif
        return data[index];
    }

    void pushBack(int x);
};

bool operator==(const VecInt &a, const VecInt &b);
bool operator!=(const VecInt &a, const VecInt &b);
