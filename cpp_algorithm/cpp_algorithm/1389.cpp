#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_USER = 101;
const int INF = 987654321;

std::vector<std::vector<int>> graph(MAX_USER, std::vector<int>(MAX_USER, INF));
int userCount;
int relationCount;
int min_bacon = INF;
int answer = 0;

void Input()
{
	std::cin >> userCount >> relationCount;
	for (int i = 0; i < relationCount; i++)
	{
		int user1, user2;
		std::cin >> user1 >> user2;

		graph[user1][user2] = 1;
		graph[user2][user1] = 1;
	}

	for (int i = 0; i <= userCount; i++)
	{
		graph[i][i] = 0;
	}
}

void Floyd()
{
	for (int i = 1; i <= userCount; i++)
	{
		for (int j = 1; j <= userCount; j++)
		{
			for (int k = 1; k <= userCount; k++)
			{
				if (graph[j][i] + graph[i][k] < graph[j][k])
				{
					graph[j][k] = graph[j][i] + graph[i][k];
				}
			}
		}
	}
}

void FindAnswer()
{
	for (int i = 1; i <= userCount; i++)
	{
		int cavin_bacon = 0;
		for (int j = 1; j <= userCount; j++)
		{
			cavin_bacon += graph[i][j];
		}

		if (min_bacon > cavin_bacon)
		{
			min_bacon = cavin_bacon;
			answer = i;
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	Input();
	Floyd();
	FindAnswer();
	
	std::cout << answer << std::endl;

	return 0;
}