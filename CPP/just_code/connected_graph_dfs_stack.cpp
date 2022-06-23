#include <iostream>
#include <stack>
#include <vector>

std::vector<int> adj[10];
bool visited[10];

void dfs()
{
    std::stack<int> s;
    s.push(1);

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (visited[current])
        {
            continue;
        }
        visited[current] = true;

        for (auto next : adj[current])
        {
            if (visited[next])
            {
                continue;
            }
            s.push(next);
        }
    }
}

int main()
{
}