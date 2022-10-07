#include <iostream>
#include <vector>

typedef long long ll;
const int MAX_SIZE = 92;

std::vector<std::vector<ll>> dp(MAX_SIZE, std::vector<ll>(2, 0));
int n;

int main(void)
{
  std::cin >> n;

  dp[1][0] = 0;
  dp[1][1] = 1;

  dp[2][0] = 1;
  dp[2][1] = 0;

  if (n > 2)
  {
    for (int i = 3; i <= n; i++)
    {
      dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
      dp[i][1] = dp[i - 1][0];
    }
  }

  std::cout << dp[n][0] + dp[n][1];

  return 0;
}