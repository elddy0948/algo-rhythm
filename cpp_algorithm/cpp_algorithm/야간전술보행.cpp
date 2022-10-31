#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool IsWorking(int currentTime, vector<int> time)
{
	int calculatedTime = currentTime % (time.front() + time.back());

	if (calculatedTime != 0 && calculatedTime <= time.front()) return true;
	else return false;
}

int solution(int distance, vector<vector<int>> scope, vector<vector<int>> times) {
	int answer = 0;

	vector<int> dist(distance + 1, 0);

	for (int s = 0; s < scope.size(); s++)
	{
		if (scope[s].front() < scope[s].back())
		{
			for (int i = scope[s].front(); i <= scope[s].back(); i++)
			{
				dist[i] = s + 1;
			}
		}
		else
		{
			for (int i = scope[s].back(); i <= scope[s].front(); i++)
			{
				dist[i] = s + 1;
			}
		}
	}

	for (int d = 1; d <= distance; d++)
	{
		if (dist[d] != 0)
		{
			auto worker = dist[d] - 1;
			if (IsWorking(d, times[worker]))
			{
				answer = d;
				break;
			}
		}
	}

	if (answer == 0) return distance;

	return answer;
}

int main(void)
{
	cout << solution(12, { {7,6}, {4,6}, {11, 10} }, { {2, 2}, {2, 4}, {3, 3} });

	return 0;
}