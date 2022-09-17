#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

std::tuple<int, int> a;

void Input(int& vertices, int& edges)
{
	std::cin >> vertices >> edges;
	return;
}

int Find(std::vector<int>& parents, int nodeNumber)
{
	if (parents[nodeNumber] != nodeNumber)
	{
		parents[nodeNumber] = Find(parents, parents[nodeNumber]);
	}
	return parents[nodeNumber];
}

void Union(
	std::vector<int>& parents,
	std::vector<int>& ranks,
	int lhs, int rhs)
{
	int lhsParent = Find(parents, lhs);
	int rhsParent = Find(parents, rhs);

	if (lhsParent == rhsParent)
	{
		return;
	}

	if (ranks[lhsParent] < ranks[rhsParent])
	{
		parents[lhsParent] = rhsParent;
	}
	else if (ranks[rhsParent] < ranks[lhsParent])
	{
		parents[rhsParent] = lhsParent;
	}
	else
	{
		parents[lhsParent] = rhsParent;
		ranks[rhsParent]++;
	}

	return;
}

std::vector<std::tuple<int, int, int>> InputEdges(int numberOfEdges)
{
	std::vector<std::tuple<int, int, int>> edgeInfo(numberOfEdges, std::tuple<int, int, int>());

	for (int i = 0; i < numberOfEdges; i++)
	{
		int vertex1, vertex2, weight;
		std::cin >> vertex1 >> vertex2 >> weight;
		std::tuple<int, int, int> edge = std::make_tuple(weight, vertex1, vertex2);
		edgeInfo[i] = edge;
	}

	return edgeInfo;
}

int main(void)
{
	int numberOfVertices;
	int numberOfEdges;
	
	Input(numberOfVertices, numberOfEdges);

	std::vector<int> parents(numberOfVertices + 1, -1);
	std::vector<int> ranks(numberOfVertices + 1, 0);

	for (int i = 1; i <= numberOfVertices; i++)
	{
		parents[i] = i;
	}

	std::vector<std::tuple<int, int, int>> edges = InputEdges(numberOfEdges);

	// Sort Edges
	std::sort(edges.begin(), edges.end());
	int totalWeight = 0;
	for (int i = 0; i < numberOfEdges; i++)
	{
		int weight, vertex1, vertex2;
		std::tie(weight, vertex1, vertex2) = edges[i];

		if (Find(parents, vertex1) != Find(parents, vertex2))
		{
			Union(parents, ranks, vertex1, vertex2);
			totalWeight += weight;
		}
	}

	std::cout << totalWeight;

	return 0;
}