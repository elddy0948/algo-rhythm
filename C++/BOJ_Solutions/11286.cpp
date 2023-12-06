#include <iostream>
#include <queue>

using namespace std;

struct compare
{
  bool operator()(int lhs, int rhs)
  {
    int lhsAbs = abs(lhs);
    int rhsAbs = abs(rhs);

    if (lhsAbs == rhsAbs)
    {
      return lhs > rhs;
    }
    else
    {
      return lhsAbs > rhsAbs;
    }
  }
};

int main()
{
  int n;

  priority_queue<int, vector<int>, compare> pq;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int x;

    cin >> x;

    if (x == 0)
    {
      if (pq.empty())
        cout << 0 << '\n';
      else
      {
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
    else
    {
      pq.push(x);
    }
  }

  return 0;
}