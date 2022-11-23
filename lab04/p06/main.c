#include "VecInt.h"
#include <stdio.h>

void printArray(int *beg, int *end);
void reverse(int *beg, int *end);
void p01();
void p02();

int main(void)
{
    p01();
    p02();
}

void p01()
{
    printf("the size of array: ");

    int n;
    scanf("%d", &n);

    struct VecInt v;
    VecInt_createOfSize(&v, n, 0);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v.data[i]);
    }

    reverse(v.data, v.data + n);

    printArray(v.data, v.data + n);

    VecInt_destroy(&v);
}

void p02()
{
    // vector<int> v;
    struct VecInt v;
    VecInt_createEmpty(&v);

    puts("enter arbitray number of integer values:");
    int x;
    while (scanf("%d", &x) == 1)
    {
        // v.push_back(x)
        VecInt_pushBack(&v, x);
    }

    printArray(v.data, v.data + v.sz);
    reverse(v.data, v.data + v.sz);
    printArray(v.data, v.data + v.sz);

    VecInt_destroy(&v);
}

void printArray(int *beg, int *end)
{
    while (beg != end)
    {
        printf(" %d", *beg++);
    }
    printf("\n");
}

void reverse(int *beg, int *end)
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

        int t = *beg;
        *beg = *end;
        *end = t;

        ++beg;
    }
}
