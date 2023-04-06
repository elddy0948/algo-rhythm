#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<pair<int, int>> vec(n, pair<int, int>());

  for (int i = 0; i < n; i++)
  {
    cin >> vec[i].first;
    vec[i].second = i;
  }

  sort(vec.begin(), vec.end());

  int maxDiff = 0;

  for (int i = 0; i < n; i++)
  {
    if (maxDiff < vec[i].second - i)
    {
      maxDiff = vec[i].second - i;
    }
  }

  cout << maxDiff + 1;

  return 0;
}