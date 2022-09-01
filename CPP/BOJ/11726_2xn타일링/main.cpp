#include <iostream>

int dp[1001];
const int MOD = 10007;

void init_dp()
{
    dp[1] = 1;
    dp[2] = 2;
}

int solve_with_dp(int n)
{
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    return dp[n];
}

int main(void)
{
    int n;
    std::cin >> n;

    init_dp();
    int answer = solve_with_dp(n);

    std::cout << answer;

    return 0;
}