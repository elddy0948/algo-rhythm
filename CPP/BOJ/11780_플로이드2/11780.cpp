#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 0x3f3f3f3f;

void InputCitiesAndBuses(int &cities, int &buses)
{
  std::cin >> cities;
  std::cin >> buses;
}

int CheckShortestDistance(int oldPath, int newPathFrom, int newPathTo)
{
  if (newPathFrom == INF || newPathTo == INF)
  {
    return oldPath;
  }

  return std::min(oldPath, newPathFrom + newPathTo);
}

void InputAndInItBusGraph(
    std::vector<std::vector<int>> &citiesGraph,
    std::vector<std::vector<int>> &pathGraph,
    int numberOfBuses, int numberOfCities)
{
  for (int i = 0; i < numberOfBuses; i++)
  {
    int from, to, value;
    std::cin >> from >> to >> value;
    int distance = CheckShortestDistance(citiesGraph[from][to], value, 0);
    if (distance != citiesGraph[from][to])
    {
      citiesGraph[from][to] = distance;
      pathGraph[from][to] = to;
    }
  }
}

void FloydAndPath(
    std::vector<std::vector<int>> &citiesGraph,
    std::vector<std::vector<int>> &pathGraph,
    int numberOfCities)
{
  for (int middle = 1; middle <= numberOfCities; middle++)
  {
    for (int start = 1; start <= numberOfCities; start++)
    {
      for (int target = 1; target <= numberOfCities; target++)
      {
        if (start == target)
        {
          continue;
        }
        int distance = CheckShortestDistance(
            citiesGraph[start][target],
            citiesGraph[start][middle],
            citiesGraph[middle][target]);

        if (distance != citiesGraph[start][target])
        {
          citiesGraph[start][target] = distance;
          pathGraph[start][target] = pathGraph[start][middle];
        }
      }
    }
  }
}

int main(void)
{
  int numberOfCities;
  int numberOfBuses;

  InputCitiesAndBuses(numberOfCities, numberOfBuses);

  std::vector<std::vector<int>> citiesGraph(
      numberOfCities + 1, std::vector<int>(numberOfCities + 1, INF));
  std::vector<std::vector<int>> pathGraph(
      numberOfCities + 1, std::vector<int>(numberOfCities + 1, INF));

  InputAndInItBusGraph(citiesGraph, pathGraph, numberOfBuses, numberOfCities);

  FloydAndPath(citiesGraph, pathGraph, numberOfCities);

  for (int i = 1; i <= numberOfCities; i++)
  {
    for (int j = 1; j <= numberOfCities; j++)
    {
      if (citiesGraph[i][j] == INF)
      {
        citiesGraph[i][j] = 0;
      }
      std::cout << citiesGraph[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  for (int i = 1; i <= numberOfCities; i++)
  {
    for (int j = 1; j <= numberOfCities; j++)
    {
      if (citiesGraph[i][j] == INF || citiesGraph[i][j] == 0)
      {
        std::cout << "0\n";
        continue;
      }

      std::vector<int> path;
      int startPoint = i;
      while (startPoint != j)
      {
        path.emplace_back(startPoint);
        startPoint = pathGraph[startPoint][j];
      }
      path.emplace_back(j);

      std::cout << path.size() << ' ';
      for (auto city : path)
      {
        std::cout << city << ' ';
      }
      std::cout << std::endl;
    }
  }
}