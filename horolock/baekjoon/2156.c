#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX(lhs, rhs)       ((lhs) > (rhs) ? lhs : rhs)

int main(void)
{
    unsigned int wine_size = 0;
    int i = 0;
    int answer = 0;

    int* wines = NULL;
    int* dp = NULL;

    scanf("%d", &wine_size);

    wines = (int*)malloc(sizeof(int) * wine_size + 1);
    dp = (int*)malloc(sizeof(int) * wine_size + 1);

    for (i = 1; i <= wine_size; ++i) {
        scanf("%d", &wines[i]);
    }

    dp[0] = 0, dp[1] = wines[1];
    if (wine_size >= 2) { dp[2] = wines[1] + wines[2]; }
    if (wine_size >= 3) { dp[3] = MAX(wines[2] + wines[3], wines[1] + wines[3]); }

    for (i = 4; i <= wine_size; ++i) {
        dp[i] = MAX(dp[i - 2] + wines[i],
         MAX(dp[i - 3] + wines[i - 1] + wines[i], dp[i - 4] + wines[i - 1] + wines[i]));
    }

    for (i = 1; i <= wine_size; ++i) {
        if (dp[i] > answer) {
            answer = dp[i];
        }
    }

    printf("%d", answer);

    free(wines);
    free(dp);

    return 0;
}