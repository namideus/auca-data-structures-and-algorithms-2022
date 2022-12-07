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

    ForwardIter min = beg;
    ++beg;

    for (; beg != end; ++beg)
    {
        if (*beg < *min)
        {
            min = beg;
        }
    }

    return min;
}

template <typename ForwardIter, class Compare>
ForwardIter auMinElement(ForwardIter beg, ForwardIter end, Compare comp)
{
    if (beg == end)
        return end;

    ForwardIter min = beg;
    ++beg;

    for (; beg != end; ++beg)
    {
        if (comp(*beg, *min))
        {
            min = beg;
        }
    }

    return min;
}

template <typename ForwardIter, class T>
bool auBinarySearch(ForwardIter beg, ForwardIter end, const T &value)
{
    beg = std::lower_bound(beg, end, value);
    return beg != end && value >= *beg;
}
