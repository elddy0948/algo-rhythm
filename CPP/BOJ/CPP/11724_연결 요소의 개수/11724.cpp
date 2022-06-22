#include <iostream>
#include <vector>

bool visited[1002];
std::vector<int> graph[1002];

void dfs(int vertex_number)
{
    visited[vertex_number] = true;

    for (int i = 0; i < graph[vertex_number].size(); i++)
    {
        int next_vertex = graph[vertex_number][i];
        if (!visited[next_vertex])
        {
            dfs(next_vertex);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;

        // No direction
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int connection_components = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            connection_components++;
        }
    }

    std::cout << connection_components;
}