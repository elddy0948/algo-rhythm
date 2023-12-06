#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[101][101] = { 0 };
bool visited[101][101] = { false };
int n;
int m;
int depth = 0;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty()) {
		auto currentQueueSize = q.size();
		depth++;
		for (auto i = 0; i < currentQueueSize; i++) {
			auto f = q.front();
			q.pop();

			for (auto d = 0; d < 4; d++) {
				auto nextX = f.first + dx[d];
				auto nextY = f.second + dy[d];

				if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) { continue; }

				if (nextX == n - 1 && nextY == m - 1) {
					return;
				}

				if (!visited[nextX][nextY] && map[nextX][nextY] == 1) {
					visited[nextX][nextY] = true;
					q.push({ nextX, nextY });
				}
			}
		} 

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j < m; j++) {
			char c;
			cin >> c;
			map[i][j] = c - '0';
		}
	}

	bfs();

	cout << depth + 1;

	return 0;
}