#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> nodeList;
vector<int> dist;
static int nodeCount;

void bfs(int node) {
	queue<int> q;
	vector<bool> visited(nodeCount + 1, false);

	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		auto f = q.front();
		q.pop();

		for (int i = 0; i < nodeList[f].size(); i++) {
			auto nextNode = nodeList[f][i].first;

			if (!visited[nextNode]) {
				q.push(nextNode);
				visited[nextNode] = true;
				dist[nextNode] = dist[f] + nodeList[f][i].second;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nodeCount;

	nodeList.resize(nodeCount + 1);
	dist = vector<int>(nodeCount + 1, 0);

	for (int i = 0; i < nodeCount; i++) {
		int nodeNumber;
		cin >> nodeNumber;

		while (true) {
			int target;
			cin >> target;
			if (target == -1) { break; }
			int weight;
			cin >> weight;

			nodeList[nodeNumber].push_back({ target, weight });
		}
	}

	bfs(1);

	int m = 1;
	for (int i = 2; i <= nodeCount; i++) {
		if (dist[m] < dist[i]) { m = i; }
	}

	fill(dist.begin(), dist.end(), 0);
	bfs(m);

	sort(dist.begin(), dist.end());

	cout << dist[nodeCount] << '\n';

	return 0;
}