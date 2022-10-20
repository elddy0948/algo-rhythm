#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const int MaxBoardSize = 16;

vector<int> rows(MaxBoardSize, 0);
vector<vector<int>> ans;
int queenCount;

bool Place(int row, int col)
{
  for (int prev = 0; prev < col; prev++)
  {
    if (rows[prev] == row || (abs(rows[prev] - row) == abs(prev - col)))
      return false;
  }
  return true;
}

void BackTracking(int col)
{
  if (col == queenCount)
  {
    vector<int> temp;
    for (int i = 0; i < queenCount; i++)
    {
      temp.push_back(rows[i] + 1);
    }
    ans.push_back(temp);
  }

  for (int row = 0; row < queenCount; row++)
  {
    if (Place(row, col))
    {
      rows[col] = row;
      BackTracking(col + 1);
    }
  }
}

vector<vector<int>> nQueen(int n)
{
  queenCount = n;

  BackTracking(0);

  return ans;
}

int main(void)
{
  vector<vector<int>> result = nQueen(8);

  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < queenCount; j++)
    {
      std::cout << result[i][j] << ' ';
    }
    std::cout << '\n';
  }

  std::cout << result.size();

  return 0;
}
