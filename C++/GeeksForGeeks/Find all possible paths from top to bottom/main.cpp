#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int directionX[2] = {0, 1};
  int directionY[2] = {1, 0};
  vector<vector<int>> result;

public:
  vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
  {
    vector<int> path;
    backtracking(0, 0, n - 1, m - 1, path, grid);
    return result;
  }

private:
  void backtracking(int currentX, int currentY, int endX, int endY, vector<int> path, vector<vector<int>> &grid)
  {
    if (currentX == endX && currentY == endY)
    {
      path.push_back(grid[currentX][currentY]);
      result.emplace_back(path);
      return;
    }

    if (currentX > endX || currentY > endY)
    {
      return;
    }

    path.push_back(grid[currentX][currentY]);

    // Go right
    backtracking(currentX + 1, currentY, endX, endY, path, grid);
    // Go down
    backtracking(currentX, currentY + 1, endX, endY, path, grid);

    return;
  }
};

int main()
{
  Solution sol = Solution();

  vector<vector<int>> grid = {
      {1, 2, 3},
      {4, 5, 6}};
  vector<vector<int>> res = sol.findAllPossiblePaths(2, 3, grid);

  for (const auto &p : res)
  {
    for (const auto &e : p)
    {
      cout << e << ' ';
    }
    cout << endl;
  }
  return 0;
}