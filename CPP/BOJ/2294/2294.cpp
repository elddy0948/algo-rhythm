#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_VALUE = 10001;
const int MAX_INT = 987654321;

std::vector<int> coins;
std::vector<int> dp(MAX_VALUE, MAX_INT);

int coinCount;
int valueToMake;

void Input();
void DynamicProgramming();

int main(void)
{
  Input();

  dp[0] = 0;

  DynamicProgramming();

  if (dp[valueToMake] != MAX_INT)
  {
    std::cout << dp[valueToMake];
  }
  else
  {
    std::cout << -1;
  }

  return 0;
}

void Input()
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  std::cin >> coinCount >> valueToMake;

  for (int i = 0; i < coinCount; i++)
  {
    int coin;
    std::cin >> coin;

    if (coin > 10000)
      continue;

    coins.push_back(coin);

    dp[coin] = 1;
  }
}

void DynamicProgramming()
{
  for (auto coin : coins)
  {
    for (int i = coin; i <= valueToMake; i++)
    {
      dp[i] = std::min(dp[i], dp[i - coin] + 1);
    }
  }
}