#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> friendsList;

void dfs(vector<bool>& visited, const int current, const int depth) {
	if (depth == 5) {
		cout << "1";
		exit(0);
	}

	for (int i = 0; i < friendsList[current].size(); i++) {
		const auto nextFriend = friendsList[current][i];
		if (!visited[nextFriend]) {
			visited[nextFriend] = true;
			dfs(visited, nextFriend, depth + 1);
			visited[nextFriend] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nodeCount, edgeCount;

	cin >> nodeCount >> edgeCount;

	friendsList.resize(nodeCount);

	for (auto e = 0; e < edgeCount; e++) {
		int start, end;
		cin >> start >> end;

		friendsList[start].push_back(end);
		friendsList[end].push_back(start);
	}

	for (auto f = 0; f < nodeCount; f++) {
		vector<bool> visited(nodeCount, false);
		visited[f] = true;
		dfs(visited, f, 1);
	}

	cout << "0";

	return 0;
}