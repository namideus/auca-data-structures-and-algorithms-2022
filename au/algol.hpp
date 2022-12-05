
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
