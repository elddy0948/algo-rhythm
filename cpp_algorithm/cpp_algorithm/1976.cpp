#include <iostream>
#include <vector>

std::vector<int> parents(201, 0);
std::vector<int> rank(201, 0);

int Find(const int node)
{
	if (parents[node] != node)
	{
		parents[node] = Find(parents[node]);
	}
	return parents[node];
}

void Union(const int lhs, const int rhs)
{
	int lhsParent = Find(lhs);
	int rhsParent = Find(rhs);

	if (lhsParent == rhsParent) return;

	if (rank[lhsParent] < rank[rhsParent])
	{
		parents[lhsParent] = rhsParent;
	}
	else if (rank[rhsParent] < rank[lhsParent])
	{
		parents[rhsParent] = lhsParent;
	}
	else
	{
		parents[lhsParent] = rhsParent;
		rank[rhsParent]++;
	}

	return;
}

void InputCityMap(int numberOfCities)
{
	for (int startCity = 1; startCity <= numberOfCities; startCity++)
	{
		for (int targetCity = 1; targetCity <= numberOfCities; targetCity++)
		{
			int canGo;

			std::cin >> canGo;

			if (canGo)
			{
				Union(startCity, targetCity);
			}
		}
	}
}

bool CanTravel(int travelScheduleSize)
{
	int currentParent = 0;

	for (int i = 0; i < travelScheduleSize; i++)
	{
		int city;

		std::cin >> city;

		int parent = Find(city);

		if (i == 0)
		{
			currentParent = parent;
			continue;
		}

		if (currentParent != parent) return false;
	}

	return true;
}

int main(void)
{
	int numberOfCities;
	int travelScheduleSize;

	std::cin >> numberOfCities;
	std::cin >> travelScheduleSize;

	for (int i = 1; i <= numberOfCities; i++)
	{
		parents[i] = i;
	}

	InputCityMap(numberOfCities);

	bool answer = CanTravel(travelScheduleSize);

	answer ? (std::cout << "YES") : (std::cout << "NO");

	return 0;
}