#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;

int parents[MAX];
bool visited[MAX];
vector<int> graph[MAX];
int nodeCount = 0;

void BFS()
{
	queue<int> q;

	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		int parent = q.front();
		q.pop();

		for (int i = 0; i < graph[parent].size(); ++i)
		{
			int curr = graph[parent][i];
			if (!visited[curr])
			{
				parents[curr] = parent;
				visited[curr] = true;
				if (graph[curr].size() != 0)
				{
					q.push(curr);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> nodeCount;
	
	for (int i = 0; i < nodeCount - 1; ++i)
	{
		int lhs, rhs;
		cin >> lhs >> rhs;

		graph[lhs].push_back(rhs);
		graph[rhs].push_back(lhs);
	}

	BFS();

	for (int i = 2; i <= nodeCount; ++i)
	{
		cout << parents[i] << '\n';
	}

	return 0;
}