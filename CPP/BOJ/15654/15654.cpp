#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_N = 9;
const int MAX_M = 9;

int n, m;
std::vector<int> numberToUse(MAX_N, 0);
std::vector<int> seq(MAX_M, 0);
std::bitset<MAX_N> visited;

void InputAndSort()
{
  std::cin >> n >> m;

  for (int i = 0; i < n; i++)
    std::cin >> numberToUse[i];

  std::sort(numberToUse.begin(), numberToUse.begin() + n);
}

void BackTracking(int length)
{
  if (length == m)
  {
    for (int i = 0; i < length; i++)
      std::cout << seq[i] << ' ';
    std::cout << '\n';
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      seq[length] = numberToUse[i];
      visited[i] = true;
      BackTracking(length + 1);
      visited[i] = false;
    }
  }
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  InputAndSort();

  for (int i = 0; i < n; i++)
  {
    seq[0] = numberToUse[i];
    visited[i] = true;
    BackTracking(1);
    visited[i] = false;
  }

  return 0;
}