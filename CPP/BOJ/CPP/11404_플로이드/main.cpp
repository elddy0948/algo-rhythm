#include <iostream>
#include <algorithm>
#include <vector>

const int INF = 0x3f3f3f3f;

void InputCityCountAndBusCount(int &cityCount, int &busCount)
{
  std::cin >> cityCount;
  std::cin >> busCount;
}

void InitGraph(std::vector<std::vector<int>> &graph, int cityCount, int busCount)
{
  for (int i = 1; i <= busCount; i++)
  {
    int start, target, cost;
    std::cin >> start >> target >> cost;

    graph[start][target] = std::min(graph[start][target], cost);
  }

  for (int i = 1; i <= cityCount; i++)
  {
    graph[i][i] = 0;
  }
}

void Floyd(std::vector<std::vector<int>> &graph, int cityCount)
{
  for (int middle = 1; middle <= cityCount; middle++)
  {
    for (int startPoint = 1; startPoint <= cityCount; startPoint++)
    {
      for (int targetPoint = 1; targetPoint <= cityCount; targetPoint++)
      {
        graph[startPoint][targetPoint] = std::min(
            graph[startPoint][targetPoint], graph[startPoint][middle] + graph[middle][targetPoint]);
      }
    }
  }
}

int main(void)
{
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int cityCount;
  int busCount;

  InputCityCountAndBusCount(cityCount, busCount);

  std::vector<std::vector<int>> graph(cityCount + 1, std::vector<int>(cityCount + 1, INF));

  InitGraph(graph, cityCount, busCount);
  Floyd(graph, cityCount);

  for (int i = 1; i <= cityCount; i++)
  {
    for (int j = 1; j <= cityCount; j++)
    {
      if (graph[i][j] == INF)
      {
        std::cout << "0 ";
      }
      else
      {
        std::cout << graph[i][j] << ' ';
      }
    }
    std::cout << std::endl;
  }

  return 0;
}