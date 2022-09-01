#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> graph[1001];
bool visited[1001];

void bfs(int start)
{
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int vertex = q.front();
        std::cout << vertex << ' ';
        q.pop();

        for (auto next_vertex : graph[vertex])
        {
            if (visited[next_vertex])
            {
                continue;
            }

            q.push(next_vertex);
            visited[next_vertex] = true;
        }
    }
}

void dfs(int current)
{
    visited[current] = true;
    std::cout << current << ' ';
    for (auto next_vertex : graph[current])
    {
        if (visited[next_vertex])
        {
            continue;
        }
        dfs(next_vertex);
    }
}

int main()
{
    int vertex_count;
    int edge_count;
    int start;

    std::cin >> vertex_count >> edge_count >> start;

    for (int i = 0; i < edge_count; i++)
    {
        int from, to;

        std::cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (int i = 1; i <= vertex_count; i++)
    {
        std::sort(graph[i].begin(), graph[i].end());
    }

    visited[start] = true;
    dfs(start);

    std::fill_n(visited, vertex_count + 1, false);

    std::cout << '\n';
    bfs(start);

    return 0;
}