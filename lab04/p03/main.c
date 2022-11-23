#include <stdio.h>

#define N 5
#define M 3

void readArray(int *p, int n);
void printArray(int *beg, int *end);

int a[N];

int main(void)
{
    int b[M];

    readArray(a, N);
    readArray(b, M);

    printArray(a, a + N);
    printArray(b, b + M);
}

void readArray(int *p, int n)
{
    // for (int i = 0; i < n; ++i)
    // {
    //     scanf("%d", &p[i]);
    // }

    while (n--)
    {
        scanf("%d", p++);
    }
}

void printArray(int *beg, int *end)
{
    // for (int i = 0; i < n; ++i)
    // {
    //     printf(" %d", p[i]);
    // }

    // int *end = p + n;
    // for (; p != end; ++p)
    // {
    //     printf(" %d", *p)
    // }

    while (beg != end)
    {
        printf(" %d", *beg++);
    }
    printf("\n");
}