#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MIN(lhs, rhs) ((lhs < rhs) ? lhs : rhs)

int main(void)
{
    int N = 0, i = 0;
    int* sugars;
    int* dp;

    scanf("%d", &N);

    dp = (int*)malloc(sizeof(int) * N + 1);

    dp[0] = 0;
    dp[1] = 0, dp[2] = 0, dp[3] = 1, dp[4] = 0, dp[5] = 1;

    for(i = 6; i <= N; ++i)
    {
        if (dp[i - 3] == 0 && dp[i - 5] != 0) { dp[i] = dp[i - 5] + 1; }
        else if (dp[i - 3] != 0 && dp[i - 5] == 0) { dp[i] = dp[i - 3] + 1; }
        else if (dp[i - 3] != 0 && dp [i - 5] != 0) { dp[i] = MIN(dp[i - 3], dp[i - 5]) + 1; }
        else if (dp[i - 3] == 0 && dp[i - 5] == 0) { dp[i] = 0; }
    }

    printf("%d", ((dp[N] != 0) ? dp[N] : -1));

    free(dp);

    return 0;
}