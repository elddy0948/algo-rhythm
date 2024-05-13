#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MIN(lhs, rhs) ((lhs < rhs) ? lhs : rhs)
#define MAX_ARRAY_SIZE      1000001

int dp[MAX_ARRAY_SIZE] = {0,};

int main(void)
{
    int N = 0, i = 0;
    int temp = 0;

    scanf("%d", &N);

    dp[0] = 0, dp[1] = 0, dp[2] = 1, dp[3] = 1;

    for (i = 4; i <= N; ++i)
    {
        temp = dp[i - 1];
        if (i % 2 == 0) { temp = MIN(dp[i / 2], temp); }
        if (i % 3 == 0) { temp = MIN(dp[i / 3], temp); }
        dp[i] = temp + 1;
    }

    printf("%d", dp[N]);

    return 0;
}