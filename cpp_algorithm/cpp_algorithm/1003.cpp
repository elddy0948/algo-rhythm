#include <iostream>
#include <vector>

int main(void)
{
	std::vector<std::pair<int, int>> dp(41, std::make_pair(0, 0));

	dp[0] = std::make_pair(1, 0);
	dp[1] = std::make_pair(0, 1);

	for (int i = 2; i <= 40; i++)
	{
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}

	int test_case;

	std::cin >> test_case;
	
	for (int i = 0; i < test_case; i++)
	{
		int n;
		std::cin >> n;

		std::cout << dp[n].first << ' ' << dp[n].second << std::endl;
	}

	return 0;
}