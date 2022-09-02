#include <iostream>
#include <vector>

const int MAX_SIZE = 10;

int Find(std::vector<int>& root, int x)
{
	if (root[x] == x)
	{
		return x;
	}
	else
	{
		return root[x] = Find(root, root[x]);
	}
}

void Union(
	std::vector<int>& root,
	std::vector<int>& levels,
	int x, int y)
{
	x = Find(root, x);
	y = Find(root, y);

	if (x == y)
	{
		return;
	}

	if (levels[x] < levels[y])
	{
		root[x] = y;
	}
	else
	{
		root[y] = x;
		if (levels[x] == levels[y])
		{
			levels[x]++;
		}
	}
}

int Union2(
	std::vector<int>& root,
	std::vector<int>& nodeCount, 
	int x, int y)
{
	x = Find(root, x);
	y = Find(root, y);

	if (x != y)
	{
		root[y] = x;
		nodeCount[x] += nodeCount[y];
		nodeCount[y] = 1;
	}
	return nodeCount[x];
}

void UnionFind()
{
	std::vector<int> root(MAX_SIZE, 0);
	std::vector<int> levels(MAX_SIZE, 0);
	std::vector<int> nodeCount(MAX_SIZE, 1);

	// Initialize root
	for (int i = 0; i < MAX_SIZE; i++)
	{
		root[i] = i;
	}
}

int main(void)
{
	return 0;
}