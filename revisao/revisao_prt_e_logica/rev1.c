#include <stdio.h>

int main () {
    int a = 1, b = 2, c = 3, d = 4;
    printf("\n\na = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);

    int *pa = &a, *pb = &b, *pc = &c, *pd = &d;
    *pa = 10, *pb = 20, *pc = 30, *pd = 40;

    printf("\n\na = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
    return 0;
}