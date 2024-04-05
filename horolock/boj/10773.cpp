#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
  unsigned int k, i = 0;
  unsigned int value = 0;
  unsigned int total = 0;

  stack<unsigned int> s;

  cin >> k;

  for(i = 0; i < k; ++i)
  {
    cin >> value;


    if(value == 0)
    {
      unsigned int top = s.top();
      s.pop();
      total -= top;
    }
    else
    {
      s.push(value);
      total += value;
    }
  }

  cout << total;

  return 0;
}
