#include <iostream>
#include <deque>

using namespace std;

int n, l;
deque<pair<int, int>> dq;

void input()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> l;
}

void solve()
{
  for (int i = 0; i < n; i++)
  {
    int current;
    cin >> current;

    while (dq.size() && dq.back().first > current)
    {
      dq.pop_back();
    }
    dq.push_back(make_pair(current, i));

    if (dq.front().second <= i - l)
    {
      dq.pop_front();
    }

    cout << dq.front().first << ' ';
  }
}

int main()
{
  input();
  solve();
  return 0;
}