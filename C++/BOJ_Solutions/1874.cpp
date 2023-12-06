#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<int> vec(n, 0);
  vector<char> answer;

  stack<int> s;
  int current = 1;
  bool result = true;

  for (int i = 0; i < n; i++)
  {
    int num;
    cin >> num;

    if (num >= current)
    {
      while (num >= current)
      {
        s.push(current++);
        answer.push_back('+');
      }
      s.pop();
      answer.push_back('-');
    }
    else
    {
      int n = s.top();
      s.pop();

      if (n > num)
      {
        cout << "NO";
        result = false;
        break;
      }
      else
      {
        answer.push_back('-');
      }
    }
  }

  if (result)
  {
    for (const auto &c : answer)
    {
      cout << c << '\n';
    }
  }

  return 0;
}