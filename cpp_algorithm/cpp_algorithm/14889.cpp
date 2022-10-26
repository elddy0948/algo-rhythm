// 능력치 차이를 최소로

#include <iostream>
#include <array>
#include <bitset>
#include <cstdlib>

using namespace std;

const int MaxPlayerSize = 21;

array<array<int, MaxPlayerSize>, MaxPlayerSize> players;
bitset<MaxPlayerSize> visited;

int n;
int answer = 987654321;

void Input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> players[i][j];
}

void Solution(int count, int player)
{
	if (count == n / 2)
	{
		int startTeam = 0;
		int linkTeam = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (visited[i] && visited[j]) startTeam += players[i][j];
				else if (!visited[i] && !visited[j]) linkTeam += players[i][j];
			}
		}

		int teamBalance = abs(startTeam - linkTeam);
		if (answer > teamBalance) answer = teamBalance;

		return;
	}

	for (int p = player; p < n; p++)
	{
		if (!visited[p])
		{
			visited[p] = true;
			Solution(count + 1, p);
			visited[p] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solution(0, 1);

	cout << answer;

	return 0;
}