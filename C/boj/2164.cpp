#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
  unsigned int n, i = 0;
  unsigned int value = 0;

  queue<unsigned int> q;

  cin >> n;

  for(i = 1; i <= n; ++i) { q.push(i); }

  while(q.size() != 1)
  {
    q.pop();  // throw

    if(q.size() == 1)
    {
      break;
    }

    value = q.front();
    q.pop();
    q.push(value);
  }

  cout << q.front();

  return 0;
}
