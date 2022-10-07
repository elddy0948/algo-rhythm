#include <iostream>
#include <array>

int main(void)
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(0);
	std::array<int, 1001> dp;

	// Input
	const int MOD = 10007;
	int n;
	std::cin >> n;

	// array init
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	// dynamic programming
	if (n < 3)
	{
		std::cout << dp[n];
		return 0;
	}

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + (2 * dp[i - 2])) % MOD;
	}

	std::cout << dp[n];

	return 0;
}