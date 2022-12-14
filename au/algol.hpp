#pragma once
#include <utility>

template <typename T>
void auSwap(T &a, T &b)
{
    T t = std::move(a); // T t = static_cast<T&&>(x);
    a = std::move(b);
    b = std::move(t);
}

template <typename BidirectionalIter>
void auReverse(BidirectionalIter beg, BidirectionalIter end)
{
    for (;;)
    {
        if (beg == end)
        {
            break;
        }

        --end;

        if (beg == end)
        {
            break;
        }

        auSwap(*beg, *end);

        ++beg;
    }
}

template <typename ForwardIter, typename Key>
ForwardIter auFind(ForwardIter beg, ForwardIter end, const Key &key)
{
    for (; beg != end; ++beg)
    {
        if (*beg == key)
        {
            return beg;
        }
    }

    return beg;
}

template <typename ForwardIter, typename UnaryPredicate>
ForwardIter auFindIf(ForwardIter beg, ForwardIter end, UnaryPredicate pred)
{
    for (; beg != end; ++beg)
    {
        if (pred(*beg))
        {
            return beg;
        }
    }

    return beg;
}

template <typename ForwardIter>
ForwardIter auMinElement(ForwardIter beg, ForwardIter end)
{
    if (beg == end)
        return end;

    ForwardIter min = beg++;

    for (; beg != end; ++beg)
    {
        if (*beg < *min)
        {
            min = beg;
        }
    }

    return min;
}

template <typename ForwardIter, typename Predicate>
ForwardIter auMinElement(ForwardIter beg, ForwardIter end, Predicate pred)
{
    if (beg == end)
        return end;

    ForwardIter min = beg++;

    for (; beg != end; ++beg)
    {
        if (pred(*beg, *min))
        {
            min = beg;
        }
    }

    return min;
}

template <typename ForwardIter, typename T>
ForwardIter auLowerBound(ForwardIter beg, ForwardIter end, const T &k)
{
    while (beg != end)
    {
        auto mid = beg + (end - beg) / 2;
        if (*mid < k)
        {
            beg = ++mid;
        }
        else
        {
            end = mid;
        }
    }

    return beg;
}

template <typename ForwardIter, typename T>
bool auBinarySearch(ForwardIter beg, ForwardIter end, const T &value)
{
    auto iter = auLowerBound(beg, end, value);
    return iter != end && value >= *iter;
}
