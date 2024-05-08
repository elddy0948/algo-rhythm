#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


// always minus when first '-' comes

int main(void)
{
    int i = 0, number = 0, temp = 0;
    char operator;

    scanf("%d", &number);

    for (;scanf("%c", &operator), operator != 10;)
    {
        if (operator == '-')
        {
            i = 1;
        }

        scanf("%d", &temp);

        if (i)
        {
            number -= temp;
        }
        else
        {
            number += temp;
        }
    }

    printf("%d", number);
}