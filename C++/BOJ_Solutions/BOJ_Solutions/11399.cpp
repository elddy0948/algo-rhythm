#include <iostream>
#include <vector>

using namespace std;

void InsertSort(vector<int> &arr, int n)
{
  for (int i = 1; i < n; i++)
  {
    int insert_point = i;
    int insert_value = arr[i];

    for (int j = i - 1; j >= 0; j--)
    {
      if (arr[j] < arr[i])
      {
        insert_point = j + 1;
        break;
      }
      if (j == 0)
        insert_point = 0;
    }
    for (int j = i; j > insert_point; j--)
      arr[j] = arr[j - 1];
    arr[insert_point] = insert_value;
  }
}

int CalculateSum(vector<int> arr, int n)
{
  vector<int> sum(n, 0);
  sum[0] = arr[0];

  for (int i = 1; i < n; i++)
  {
    sum[i] = sum[i - 1] + arr[i];
  }

  int total = 0;
  for (const auto &n : sum)
  {
    total += n;
  }

  return total;
}

int main()
{
  int n;
  cin >> n;

  vector<int> numbers(n, 0);

  for (int i = 0; i < n; i++)
    cin >> numbers[i];

  InsertSort(numbers, n);
  int ans = CalculateSum(numbers, n);
  cout << ans;
  return 0;
}