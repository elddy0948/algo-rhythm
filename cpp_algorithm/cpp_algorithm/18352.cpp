#include <iostream>
#include <queue>
#include <vector>

const int INF = 987654321;

void InputInfo(int& numberOfCities, int& numberOfRoads, int& answerDistance, int& startCity)
{
	std::cin >> numberOfCities >> numberOfRoads >> answerDistance >> startCity;
	return;
}

void InputGraph(std::vector<std::vector<int>>& graph, int numberOfRoads)
{
	for (int i = 0; i < numberOfRoads; i++)
	{
		int start, end;
		std::cin >> start >> end;

		graph[start].emplace_back(end);
	}
}

std::vector<int> Dijkstra(
	std::vector<std::vector<int>> graph,
	int numberOfCities,
	int startPoint)
{
	std::vector<int> distanceList(numberOfCities + 1, INF);
	std::queue<int> q;

	distanceList[startPoint] = 0;
	q.push(startPoint);

	while (!q.empty())
	{
		int currentNode = q.front();
		q.pop();

		for (auto nextNode : graph[currentNode])
		{
			if (distanceList[currentNode] + 1 < distanceList[nextNode])
			{
				distanceList[nextNode] = distanceList[currentNode] + 1;
				q.push(nextNode);
			}
		}
	}
	return distanceList;
}

int Solution18352(void)
{
	int numberOfCities;
	int numberOfRoads;
	int answerDistance;
	int startCity;

	InputInfo(numberOfCities, numberOfRoads, answerDistance, startCity);

	std::vector<std::vector<int>> graph(numberOfCities + 1, std::vector<int>());
	
	InputGraph(graph, numberOfRoads);

	std::vector<int> result = Dijkstra(graph, numberOfCities, startCity);

	bool noAnswerFlag = true;

	for (int i = 1; i <= numberOfCities; i++)
	{
		if (result[i] == answerDistance)
		{
			noAnswerFlag = false;
			std::cout << i << std::endl;
		}
	}

	if (noAnswerFlag)
	{
		std::cout << "-1";
	}

	return 0;
}