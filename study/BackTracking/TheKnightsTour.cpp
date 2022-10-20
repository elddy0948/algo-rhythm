#include <iostream>
#include <array>

// Geeks for geeks
// The Knight's tour (Back Tracking) O(n^2)

const int BoardSize = 8;

std::array<std::array<int, BoardSize>, BoardSize> board;
std::array<int, BoardSize> xMoves = {2, 1, -1, -2, -2, -1, 1, 2};
std::array<int, BoardSize> yMoves = {1, 2, 2, 1, -1, -2, -2, -1};

int SolveKnightUtil(int x, int y, int moveCount);

int IsSafe(int x, int y)
{
  return (x >= 0 && x < BoardSize && y >= 0 && y < BoardSize && board[x][y] == -1);
}

void PrintSolution()
{
  for (int x = 0; x < BoardSize; x++)
  {
    for (int y = 0; y < BoardSize; y++)
    {
      std::cout << board[x][y] << ' ';
    }
    std::cout << '\n';
  }
}

int SolveKnight()
{
  for (int x = 0; x < BoardSize; x++)
  {
    for (int y = 0; y < BoardSize; y++)
    {
      board[x][y] = -1;
    }
  }

  board[0][0] = 0;

  if (SolveKnightUtil(0, 0, 1) == 0)
  {
    std::cout << "Solution does not exist";
    return 0;
  }
  else
  {
    PrintSolution();
  }

  return 1;
}

int SolveKnightUtil(int x, int y, int moveCount)
{
  int k, nextX, nextY;

  if (moveCount == BoardSize * BoardSize)
  {
    return 1;
  }

  for (k = 0; k < 8; k++)
  {
    nextX = x + xMoves[k];
    nextY = y + yMoves[k];

    if (IsSafe(nextX, nextY))
    {
      board[nextX][nextY] = moveCount;
      if (SolveKnightUtil(nextX, nextY, moveCount + 1) == 1)
      {
        return 1;
      }
      else
      {
        board[nextX][nextY] = -1;
      }
    }
  }
  return 0;
}

int main(void)
{
  SolveKnight();
  return 0;
}