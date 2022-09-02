#include <iostream>
#include <vector>
#include <queue>

const int INF = 0x3f3f3f3f;

void InputCityAndBusCount(int& cityCount, int& busCount)
{
	std::cin >> cityCount;
	std::cin >> busCount;

	return;
}

void InputBusInfo(
	std::vector<std::vector<std::pair<int, int>>>& graph,
	int busCount)
{
	for (int i = 0; i < busCount; i++)
	{
		int start, end, weight;
		std::cin >> start >> end >> weight;
		graph[start].emplace_back(std::make_pair(weight, end));
	}
}

void Dijkstra(
	std::vector<std::vector<std::pair<int, int>>>& graph,
	std::vector<int>& distance,
	int startCity, 
	int cityCount)
{
	std::priority_queue<std::pair<int, int>> pq;
	std::vector<bool> visited(cityCount + 1, false);

	pq.push(std::make_pair(0, startCity));
	distance[startCity] = 0;

	while (!pq.empty())
	{
		int currentCost = -pq.top().first;
		int currentCity = pq.top().second;

		pq.pop();

		if (visited[currentCity])
		{
			continue;
		}

		visited[currentCity] = true;

		if (distance[currentCity] < currentCost)
		{
			continue;
		}

		for (auto nextCity : graph[currentCity])
		{
			int nextDistance = currentCost + nextCity.first;

			if (nextDistance < distance[nextCity.second])
			{
				distance[nextCity.second] = nextDistance;
				pq.push(std::make_pair(-nextDistance, nextCity.second));
			}
		}
	}
}
int main(void)
{
	int cityCount, busCount;

	InputCityAndBusCount(cityCount, busCount);

	std::vector<std::vector<std::pair<int, int>>> graph(cityCount + 1, std::vector<std::pair<int, int>>());
	std::vector<int> distance(cityCount + 1, INF);

	InputBusInfo(graph, busCount);

	int startCity, targetCity;
	std::cin >> startCity >> targetCity;

	Dijkstra(graph, distance, startCity, cityCount);
	
	std::cout << distance[targetCity];

	return 0;
}