#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  bool isClose(char c)
  {
    return c == ')' || c == '}' || c == ']';
  }

  bool isPair(char lhs, char rhs)
  {
    return (lhs == '(' && rhs == ')') || (lhs == '[' && rhs == ']') || (lhs == '{' && rhs == '}');
  }

  bool ispar(string x)
  {
    stack<char> s;

    for (const auto &c : x)
    {
      if (s.empty())
      {
        if (isClose(c))
          return false;
        s.push(c);
        continue;
      }

      if (isClose(c))
      {
        if (isPair(s.top(), c))
          s.pop();
        else
          return false;
      }
      else
        s.push(c);
    }

    if (s.empty())
      return true;
    else
      return false;
  }
};