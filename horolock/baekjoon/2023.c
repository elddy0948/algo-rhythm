/**
 * BOJ 2023
 * 신기한 소수
 * Search
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define NOT_PRIME       0
#define PRIME           1

static int number_length = 0;

char is_prime(int number)
{
    for (int i = 2; i < number / 2; ++i) {
        if (number % i == 0) {
            return NOT_PRIME;
        }
    }
    return PRIME;
}

void dfs(int number, int length)
{
    if (length == number_length) {
        if (is_prime(number))
            printf("%d\n", number);
        return;
    }

    for (int i = 1; i < 10; i += 2) {
        if (is_prime(number * 10 + i))
            dfs(number * 10 + i, length + 1);
    }
}

int main(void)
{
    scanf("%d", &number_length);

    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);

    return 0;
}

