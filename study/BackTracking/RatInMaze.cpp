#include <iostream>
#include <vector>
#include <array>

const int MazeSize = 4;

std::array<std::array<int, MazeSize>, MazeSize> maze;
std::array<std::array<int, MazeSize>, MazeSize> mazeSolution;
std::array<int, 2> dx = {1, 0};
std::array<int, 2> dy = {0, 1};

bool IsSafe(int x, int y)
{
  return (x >= 0 && x < MazeSize && y >= 0 && y < MazeSize && maze[y][x] == 1);
}

void BackTracking(int x, int y)
{
  if (x == MazeSize - 1 && y == MazeSize - 1)
  {
    // Print Created board
    std::cout << "DONE!\n";
    for (int i = 0; i < MazeSize; i++)
    {
      for (int j = 0; j < MazeSize; j++)
      {
        std::cout << mazeSolution[i][j] << ' ';
      }
      std::cout << '\n';
    }
    exit(0);
    return;
  }

  for (int d = 0; d < 2; d++)
  {
    int nextX = x + dx[d];
    int nextY = y + dy[d];

    if (IsSafe(nextX, nextY))
    {
      mazeSolution[nextY][nextX] = 1;
      BackTracking(nextX, nextY);
    }
  }
  return;
}

bool BackTracking2(int x, int y) // Geeks for geeks solution
{
  if (x == MazeSize - 1 && y == MazeSize - 1 && maze[y][x] == 1)
  {
    mazeSolution[y][x] = 1;
    return true;
  }

  if (IsSafe(x, y))
  {
    mazeSolution[y][x] = 1;
    if (BackTracking2(x + 1, y))
      return true;
    if (BackTracking2(x, y + 1))
      return true;

    mazeSolution[y][x] = 0;
    return false;
  }
  return false;
}

int main(void)
{
  maze = {{{1, 0, 0, 0},
           {1, 1, 0, 1},
           {0, 1, 0, 0},
           {1, 1, 1, 1}}};

  mazeSolution[0][0] = 1;

  BackTracking2(0, 0);

  for (int i = 0; i < MazeSize; i++)
  {
    for (int j = 0; j < MazeSize; j++)
    {
      std::cout << mazeSolution[i][j] << ' ';
    }
    std::cout << '\n';
  } // For Geeks for geeks solution
  return 0;
}