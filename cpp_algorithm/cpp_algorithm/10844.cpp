#include <iostream>
#include <vector>

const int MODULAR = 1000000000;

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::vector<std::vector<ll>>dp(101, std::vector<ll>(11, 0));
	std::cin >> n;

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			switch(j)
			{
			case 0:
				dp[i][j] = dp[i - 1][j + 1] % MODULAR;
				break;
			case 9:
				dp[i][j] = dp[i - 1][j - 1] % MODULAR;
				break;
			default:
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MODULAR;
				break;
			}
		}
	}

	ll answer = 0;

	for (int i = 0; i <= 9; i++)
	{
		answer += dp[n][i];
	}

	std::cout << answer % MODULAR;

	return 0;
}