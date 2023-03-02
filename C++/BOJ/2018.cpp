#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  int sum = 1;
  int result = 1;

  int startPoint = 1;
  int endPoint = 1;

  while (startPoint != n)
  {
    if (sum < n)
    {
      endPoint++;
      sum += endPoint;
    }
    else if (sum > n)
    {
      sum -= startPoint;
      startPoint++;
    }
    else if (sum == n)
    {
      endPoint++;
      sum += endPoint;
      result++;
    }
  }

  cout << result;

  return 0;
}