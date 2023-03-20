#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n)
{
  int answer = 0;

  vector<int> trigonometric;

  while (n != 0)
  {
    trigonometric.push_back(n % 3);
    n /= 3;
  }

  int length = trigonometric.size();

  for (int i = 0; i < length; i++)
  {
    int exponent = (length - 1) - i;
    int temp = trigonometric[i] * pow(3, exponent);
    answer += temp;
  }

  return answer;
}
