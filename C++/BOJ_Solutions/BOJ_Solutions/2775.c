#include <stdio.h>

int dp[15][15];

int main()
{
    int test_case;
    int tc;

    scanf("%d", &test_case);
    
    for (int i = 1; i < 15; i++)
    {
        dp[0][i] = i;
    }

    for(int i = 1; i < 15; i++)
    {
        for (int j = 1; j < 15; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    for(tc = 0; tc < test_case; ++tc)
    {
        int k, n;
        scanf("%d", &k);
        scanf("%d", &n);

        printf("%d\n", dp[k][n]);
    }

    return 0;
}