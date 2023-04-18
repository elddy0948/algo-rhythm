#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> numbers;
static vector<bool> visited;

void bfs(int n) {
	queue<int> q;
	q.push(n);
	
	visited[n] = true;

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		cout << f << ' ';

		for (const auto node : numbers[f]) {
			if (!visited[node]) {
				visited[node] = true;
				q.push(node);
			}
		}
	}
}

void dfs(int n) {
	cout << n << ' ';
	visited[n] = true;
	for (const auto node : numbers[n]) {
		if (!visited[node]) { dfs(node); }
	}
}

int main() {
	int vertexCount;
	int edgeCount;
	int startVertex;

	cin >> vertexCount >> edgeCount >> startVertex;

	numbers.resize(vertexCount + 1);

	for (int i = 0; i < edgeCount; i++) {
		int start, end;

		cin >> start >> end;

		numbers[start].push_back(end);
		numbers[end].push_back(start);
	}

	for (int i = 1; i <= vertexCount; i++) {
		sort(numbers[i].begin(), numbers[i].end());
	}

	visited = vector<bool>(vertexCount + 1, false);
	dfs(startVertex);
	cout << '\n';

	fill(visited.begin(), visited.end(), false);
	bfs(startVertex);
	cout << '\n';

	return 0;
}
