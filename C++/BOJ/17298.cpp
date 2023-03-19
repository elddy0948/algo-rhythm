#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> answer;
vector<int> numbers;
stack<int> s;

int n;

void input()
{
  cin >> n;

  numbers = vector<int>(n, 0);
  answer = vector<int>(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }

  return;
}

void solve()
{
  s.push(0);

  for (int i = 1; i < n; i++)
  {
    while (!s.empty() && numbers[s.top()] < numbers[i])
    {
      answer[s.top()] = numbers[i];
      s.pop();
    }

    s.push(i);
  }

  while (!s.empty())
  {
    answer[s.top()] = -1;
    s.pop();
  }

  return;
}

void printAnswer()
{
  for (const auto &n : answer)
  {
    cout << n << ' ';
  }
}

int main()
{
  input();
  solve();
  printAnswer();
  return 0;
}