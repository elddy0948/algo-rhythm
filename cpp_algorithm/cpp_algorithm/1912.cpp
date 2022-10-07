#include <iostream>
#include <array>
#include <algorithm>

int main(void)
{
	int n;
	int largestSum = 0;
	std::cin >> n;

	std::array<int, 100001> dp;
	std::array<int, 100001> arr;

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	dp[0] = arr[0];
	largestSum = dp[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = std::max(dp[i - 1] + arr[i], arr[i]);
		largestSum = std::max(largestSum, dp[i]);
	}

	std::cout << largestSum;

	return 0;
}