#include <string>
#include <vector>

using namespace std;

int calculateSum(int x)
{
  int sum = 0;

  while (x != 0)
  {
    sum += (x % 10);
    x /= 10;
  }

  return sum;
}

bool solution(int x)
{
  bool answer = true;

  int sum = calculateSum(x);

  if (x % sum != 0)
    answer = false;

  return answer;
}