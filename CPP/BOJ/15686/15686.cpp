#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int n, m;
int result;
const int INF = 987654321;
std::vector<std::pair<int, int>> house, chicken;
std::vector<std::vector<int>> graph(51, std::vector<int>(51, 0));
std::vector<bool> visited(13, false);

void Input()
{
  std::cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cin >> graph[i][j];
      if (graph[i][j] == 1)
      {
        // house
        house.push_back(std::make_pair(i, j));
      }
      else if (graph[i][j] == 2)
      {
        // chicken
        chicken.push_back(std::make_pair(i, j));
      }
    }
  }
}

int CalculateDistance(std::pair<int, int> lhs, std::pair<int, int> rhs)
{
  return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
}

void DFS(int index, int selected)
{
  if (selected == m)
  {
    int temp = 0;
    for (int i = 0; i < house.size(); i++)
    {
      int distance = INF;
      for (int j = 0; j < chicken.size(); j++)
      {
        if (visited[j])
        {
          distance = std::min(distance, CalculateDistance(house[i], chicken[j]));
        }
      }
      temp += distance;
    }
    result = std::min(result, temp);
    return;
  }

  if (index == chicken.size())
  {
    return;
  }

  visited[index] = true;
  DFS(index + 1, selected + 1);
  visited[index] = false;
  DFS(index + 1, selected);
}

int main(void)
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  result = INF;

  Input();
  DFS(0, 0);

  std::cout << result;

  return 0;
}