#include <stdio.h>
#include <stdlib.h>

void printArray(int *beg, int *end);
void reverse(int *beg, int *end);

int main(void)
{
    printf("the size of array: ");

    int n;
    scanf("%d", &n);

    int *dynArray = (int *)malloc(n * sizeof(int));
    if (dynArray == NULL)
    {
        printf("Not enough memory");
        exit(1);
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &dynArray[i]);
    }

    reverse(dynArray, dynArray + n);

    printArray(dynArray, dynArray + n);

    free(dynArray);
}

void printArray(int *beg, int *end)
{
    while (beg != end)
    {
        printf(" %d", *beg++);
    }
    printf("\n");
}

// pointer operations
// *p
// p->member
// p == q
// p != q
// the following operations only for arrays
// p++, ++p --q, q--
// p + n, p - n, p += n, p -= n
// p < q, q > p, p <= q, p >= q

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
