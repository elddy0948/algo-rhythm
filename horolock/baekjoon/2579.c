#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(lhs, rhs)       ((lhs) > (rhs) ? lhs : rhs)
#define MAX_STAIRS      301

int main(void)
{
    unsigned int number_of_stairs = 0;
    int i = 0;
    unsigned int stairs[MAX_STAIRS] = {0,};
    unsigned int dp[MAX_STAIRS] = {0,};

    scanf("%d", &number_of_stairs);

    stairs[0] = 0;

    for (i = 1; i <= number_of_stairs; ++i) {
        scanf("%d", &stairs[i]);
    }

    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];

    for(i = 3; i <= number_of_stairs; ++i)
    {
        dp[i] = MAX((dp[i - 3] + stairs[i - 1] + stairs[i]), (dp[i - 2] + stairs[i]));
    }

    printf("%d", dp[number_of_stairs]);

    return 0;
}