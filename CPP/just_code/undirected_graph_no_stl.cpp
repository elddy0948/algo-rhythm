#include <iostream>

const int vertex_count = 10;

int edge[vertex_count][2];
int degree[vertex_count];
int *graph[vertex_count];
int index_to_insert[vertex_count];

int main()
{
    int v, e;

    std::cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        std::cin >> edge[i][0] >> edge[i][1];
        degree[edge[i][0]]++;
        degree[edge[i][1]]++;
    }

    for (int i = 1; i <= v; i++)
    {
        graph[i] = new int[degree[i]];
    }

    for (int i = 0; i < e; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];

        graph[u][index_to_insert[u]] = v;
        index_to_insert[u]++;

        graph[v][index_to_insert[v]] = u;
        index_to_insert[v]++;
    }

    return 0;
}