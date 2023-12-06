#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int vertex) {
	if (visited[vertex]) { return; }
	visited[vertex] = true;

	for (const auto v: graph[vertex]) {
		if (!visited[v]) { dfs(graph, visited, v); }
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nodeCount, edgeCount;

	cin >> nodeCount >> edgeCount;

	vector<vector<int>> graph(nodeCount + 1, vector<int>());
	vector<bool> visited(nodeCount + 1, false);

	for (auto i = 0; i < edgeCount; i++) {
		int start;
		int end;
		cin >> start >> end;

		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	auto answer = 0;
	for (auto i = 1; i <= nodeCount; i++) {
		if (!visited[i]) {
			dfs(graph, visited, i);
			answer++;
		}
	}

	cout << answer;

	return 0;
}