#include <algorithm>
#include <iostream>

using namespace std;

int numbers[2001];
int n;
int answer = 0;

void Input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }
  return;
}

void FindGoodNumbers()
{
  for (int i = 0; i < n; i++)
  {
    int target = numbers[i];
    int startIndex = 0;
    int endIndex = n - 1;

    while (startIndex < endIndex)
    {
      if (numbers[startIndex] + numbers[endIndex] == target)
      {
        if (startIndex != i && endIndex != i)
        {
          answer++;
          break;
        }
        else if (startIndex == i)
        {
          startIndex++;
        }
        else if (endIndex == i)
        {
          endIndex--;
        }
      }
      else if (numbers[startIndex] + numbers[endIndex] < target)
      {
        startIndex++;
      }
      else if (numbers[startIndex] + numbers[endIndex] > target)
      {
        endIndex--;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Input();
  sort(numbers, numbers + n);
  FindGoodNumbers();

  cout << answer;
  return 0;
}