#include <iostream>
#include <vector>
#include <queue>

const int MAX = 987654321;

int vertex_count, edge_count;
int start_vertex;
int distance[20010];
std::vector<std::pair<int, int>> graph[300001];
std::queue<int> near_vertex;

void Input()
{
    std::cin >> vertex_count >> edge_count;
    std::cin >> start_vertex;

    for (int i = 0; i < edge_count; i++)
    {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        graph[from].push_back({weight, to});
    }

    for (int i = 1; i <= vertex_count; i++)
    {
        distance[i] = MAX;
    }
}

void Solve_with_dijkstra()
{
    distance[start_vertex] = 0;
    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, start_vertex});

    while (!pq.empty())
    {
        int current = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if (distance[current] != dist)
        {
            continue;
        }

        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].second;
            int nextDistance = dist + graph[current][i].first;

            if (nextDistance < distance[next])
            {
                distance[next] = nextDistance;
                pq.push({-nextDistance, next});
            }
        }
    }
}

void Print_answer()
{
    for (int i = 1; i <= vertex_count; i++)
    {
        if (distance[i] == MAX)
        {
            std::cout << "INF" << '\n';
        }
        else
        {
            std::cout << distance[i] << '\n';
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Input();
    Solve_with_dijkstra();
    Print_answer();

    return 0;
}