#include <iostream>
#include <vector>

int n, k;
std::vector<int> coins;
std::vector<int> dp(10001, 0);

void Input()
{
	std::cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		int coin;
		std::cin >> coin;
		coins.emplace_back(coin);
	}

	return;
}

void DynamicProgramming()
{
	dp[0] = 1;

	for (int i = 0; i < coins.size(); i++)
	{
		int currentCoin = coins[i];

		for (int j = currentCoin; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - currentCoin];
		}

	}

	return;
}


int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	Input();
	DynamicProgramming();

	std::cout << dp[k];

	return 0;
}