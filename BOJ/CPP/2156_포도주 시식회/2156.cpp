#include <iostream>

int wineArray[10001];
int dp[10001];

int main()
{
  int n = 0;
  std::cin >> n;

  for (int i = 1; i <= n; i++)
  {
    std::cin >> wineArray[i];
  }

  dp[1] = wineArray[1];
  dp[2] = dp[1] + wineArray[2];

  for (int i = 3; i <= n; i++)
  {
    dp[i] = std::max(dp[i - 3] + wineArray[i - 1] + wineArray[i], dp[i - 2] + wineArray[i]);
    dp[i] = std::max(dp[i - 1], dp[i]);
  }

  std::cout << dp[n];

  return 0;
}