#include <string>
#include <vector>

using namespace std;

int dx[3] = {0, 1, -1};
int dy[3] = {1, 0, -1};

vector<int> solution(int n)
{
  vector<int> answer;
  vector<vector<int>> snail(n, vector<int>(n, -1));

  int currentX = 0;
  int currentY = 0;
  int number = 1;
  int currentDirection = 0;
  int targetNumber = (n * (n + 1)) / 2;

  snail[currentX][currentY] = number;
  number++;

  while (true)
  {
    if (number > targetNumber)
    {
      break;
    }

    int nextX = currentX + dx[currentDirection];
    int nextY = currentY + dy[currentDirection];

    if (nextY < n && nextX < n && snail[nextX][nextY] == -1)
    {
      snail[nextX][nextY] = number;
      number++;

      currentX = nextX;
      currentY = nextY;

      continue;
    }
    currentDirection = (currentDirection + 1) % 3;
  }

  for (int i = 0; i < snail.size(); i++)
  {
    for (int j = 0; j <= i; j++)
    {
      answer.push_back(snail[j][i]);
    }
  }

  return answer;
}