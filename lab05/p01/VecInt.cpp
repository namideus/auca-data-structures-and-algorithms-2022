#include "VecInt.hpp"

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