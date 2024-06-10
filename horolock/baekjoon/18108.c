/**
 * BOJ 18108
 * 1998년생인 내가 태국에서는 2541년생?!
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define CONVERTER       543

int main(void)
{
    unsigned int year = 0;
    scanf("%d", &year);
    printf("%d", year - CONVERTER);
    return 0;
}