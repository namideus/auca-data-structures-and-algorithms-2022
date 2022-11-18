#include <stdio.h>

int main(void)
{
    int x;
    int y;
    int *p;

    x = 1;
    p = &x; // address of operator

    printf("x = %d\n", x);
    printf("address of x = %p\n", (void *)p);
    printf("x = %d\n", *p); // dereference operator

    *p = 2;

    printf("x = %d\n", x);
    printf("x = %d\n", *p);

    y = *p * *p;

    printf("y = %d\n", y);
}