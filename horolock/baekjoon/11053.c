#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_ARRAY_SIZE      1001

int main(void)
{
    int length = 0, i = 0, j = 0, longest = 0;
    int numbers[MAX_ARRAY_SIZE] = {0,};
    int dp[MAX_ARRAY_SIZE] = {0,};

    scanf("%d", &length);

    for (i = 1; i <= length; ++i)
    {
        scanf("%d", &numbers[i]);
    }

    for (i = 1; i <= length; ++i)
    {
        for(j = 0; j < i; ++j)
        {
            if (numbers[i] > numbers[j] && dp[i] <= dp[j])
            {
                dp[i] = dp[j] + 1;
                if (dp[i] > longest) { longest = dp[i]; }
            }
        }
    }

    printf("%d", longest);

    return 0;
}