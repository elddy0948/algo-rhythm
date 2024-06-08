/**
 * BOJ 1260
 * DFS와 BFS
 * Search
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_VERTEX      1001

using namespace std;

vector<vector<int>> edge_map(MAX_VERTEX, vector<int>());
vector<bool> visited(MAX_VERTEX, false);

void dfs(int v) {
    cout << v << ' ';
    visited[v] = true;

    for (int i = 0; i < edge_map[v].size(); ++i) {
        int available_vertex = edge_map[v][i];
        if (!visited[available_vertex]) {
            dfs(available_vertex);
        }
    }
    return;
}

void bfs(int start_vertex) {
    queue<int> q;

    q.push(start_vertex);
    visited[start_vertex] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << ' ';

        for (int i = 0; i < edge_map[v].size(); ++i) {
            int available_vertex = edge_map[v][i];
            if (!visited[available_vertex]) {
                visited[available_vertex] = true;
                q.push(available_vertex);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int vertex_size = 0, edge_size = 0, start_vertex = 0;
    int vertex1 = 0, vertex2 = 0, e = 0;

    cin >> vertex_size >> edge_size >> start_vertex;

    for (e = 0; e < edge_size; ++e) {
        cin >> vertex1 >> vertex2;

        edge_map[vertex1].push_back(vertex2);
        edge_map[vertex2].push_back(vertex1);
    }

    for (int v = 1; v <= vertex_size; ++v) {
        sort(edge_map[v].begin(), edge_map[v].end());
    }

    dfs(start_vertex);

    cout << '\n';
    fill(visited.begin(), visited.end(), false);

    bfs(start_vertex);

    return 0;
}