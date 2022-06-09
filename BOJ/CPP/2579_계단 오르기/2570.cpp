#include <iostream>

int n;
int stair[301];
int dp[301];

int main()
{
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> stair[i];
    }

    dp[0] = stair[0];
    dp[1] = std::max(stair[0] + stair[1], stair[1]);
    dp[2] = std::max(stair[0] + stair[2], stair[1] + stair[2]);

    for (int i = 3; i < n; i++)
    {
        dp[i] = std::max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);
    }

    std::cout << dp[n - 1] << '\n';

    return 0;
}