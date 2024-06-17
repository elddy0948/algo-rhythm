/**
 * BOJ 14501
 * 퇴사
 * DP
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX(lhs, rhs)       ((lhs > rhs) ? lhs : rhs)

int t[16];
int p[16];
int dp[16];

int main(void)
{
    int n = 0, i = 0;
    
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        scanf("%d %d", &t[i], &p[i]);
    }

    for (i = n; i > 0; i--) {
        if (t[i] > n - i + 1) 
            dp[i] = dp[i + 1];
        else
            dp[i] = MAX(p[i] + dp[i + t[i]], dp[i + 1]);
    }

    printf("%d", dp[1]);

    return 0;
}