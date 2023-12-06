#include <stdio.h>

int main()
{
    int a, b, c, i;

    scanf_s("%d %d %d", &a, &b, &c);

    if (c % 2 == 1) { a ^= b; }
    
    printf("%d", a);

    return 0;
}