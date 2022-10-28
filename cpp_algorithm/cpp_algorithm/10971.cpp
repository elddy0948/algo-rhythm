#include <iostream>
#include <array>
#include <algorithm>
#include <bitset>

using namespace std;

const int MaxCity = 11;

int numberOfCity;
int answer = 987654321;

array<array<int, MaxCity>, MaxCity> weights;
bitset<MaxCity> visited;


void Input()
{
	cin >> numberOfCity;

	for (int i = 0; i < numberOfCity; i++)
	{
		for (int j = 0; j < numberOfCity; j++)
		{
			cin >> weights[i][j];
		}
	}
}

void BackTracking(int startCity, int currentCity, int visitedCity, int cost)
{
	if (visitedCity == numberOfCity && startCity == currentCity)
	{
		answer = min(answer, cost);
		return;
	}

	for (int c = 0; c < numberOfCity; c++)
	{
		if (!visited[c] && weights[currentCity][c] != 0)
		{
			visited[c] = true;
			BackTracking(startCity, c, visitedCity + 1, cost + weights[currentCity][c]);
			visited[c] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();
	
	for (int city = 0; city < numberOfCity; city++)
	{
		BackTracking(city, city, 0, 0);
	}

	cout << answer;

	return 0;
}