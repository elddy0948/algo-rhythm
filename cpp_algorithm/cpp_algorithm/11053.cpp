#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(0);

	std::vector<int> arr(1001);
	std::vector<int> dp(1001);
	int length;

	std::cin >> length;


	for (int i = 0; i < length; i++)
	{
		std::cin >> arr[i];
		dp[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && (dp[j] + 1) > dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	std::cout << *std::max_element(dp.begin(), dp.end());

	return 0;
}