#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_N           1001
#define DIVIDER         10007

static int dp[MAX_N];

int main(void)
{
    int n = 0, i = 0;

    scanf("%d", &n);

    dp[1] = 1;
    dp[2] = 3;

    for (i = 3; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % DIVIDER;
    }

    printf("%d", dp[n]);

    return 0;
}