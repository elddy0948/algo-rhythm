#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int n;

  cin >> n;

  queue<int> q;

  for (int i = 1; i <= n; i++)
  {
    q.push(i);
  }

  bool flag = true;

  while (q.size() != 1)
  {
    if (flag)
    {
      q.pop();
      flag = false;
    }
    else
    {
      int temp = q.front();
      q.pop();
      q.push(temp);
      flag = true;
    }
  }

  cout << q.front();

  return 0;
}