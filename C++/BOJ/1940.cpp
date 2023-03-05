#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int resources[15001];
int target = 0;
int resourceCount = 0;
int answer = 0;

void input()
{
  cin >> resourceCount;
  cin >> target;

  for (int i = 0; i < resourceCount; i++)
  {
    cin >> resources[i];
  }
}

void solve()
{
  int startPointer = 0;
  int endPointer = resourceCount - 1;

  while (startPointer < endPointer)
  {
    int resource = resources[startPointer] + resources[endPointer];
    if (resource == target)
    {
      answer++;
      startPointer++;
      endPointer--;
    }
    else if (resource < target)
    {
      startPointer++;
    }
    else if (resource > target)
    {
      endPointer--;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  input();

  sort(resources, resources + resourceCount);

  solve();

  cout << answer;

  return 0;
}