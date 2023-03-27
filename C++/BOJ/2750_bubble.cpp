#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &v, int leftIndex, int rightIndex)
{
  if (v[leftIndex] > v[rightIndex])
  {
    int temp = v[leftIndex];
    v[leftIndex] = v[rightIndex];
    v[rightIndex] = temp;
  }
  return;
}

int main()
{
  int n;
  cin >> n;

  vector<int> v(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    {
      swap(v, j, j + 1);
    }
  }

  for (const auto &n : v)
  {
    cout << n << '\n';
  }

  return 0;
}