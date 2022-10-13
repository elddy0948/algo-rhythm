#include <iostream>
#include <algorithm>
#include <vector>

const int MAX_CABLE = 101;
int cableCount;
std::vector<std::pair<int, int>> cableVector;
std::vector<int> dp(MAX_CABLE, 0);

void Input();
int DynamicProgramming();

int main(void)
{
	Input();
	auto answer = DynamicProgramming();

	std::cout << answer;

	return 0;
}

void Input()
{
	std::cin >> cableCount;

	cableVector.push_back({ 0, 0 });

	for (int i = 0; i < cableCount; i++)
	{
		int lhs, rhs;
		std::cin >> lhs >> rhs;
		cableVector.push_back({ lhs, rhs });
	}

	std::sort(cableVector.begin(), cableVector.end());
	return;
}

int DynamicProgramming()
{
	dp[1] = 1;
	int answer = 100;

	for (int i = 2; i <= cableCount; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (cableVector[i].second > cableVector[j].second && dp[i] <= dp[j])
			{
				dp[i] = dp[j] + 1;
			}
		}
	}
	
	for (auto cable : dp)
		answer = std::min(answer, cableCount - cable);

	return answer;
}