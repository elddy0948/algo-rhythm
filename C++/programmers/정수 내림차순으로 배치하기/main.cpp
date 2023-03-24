#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<int> split(ll n)
{
  vector<int> digits;

  while (n != 0)
  {
    digits.push_back(n % 10);
    n /= 10;
  }

  return digits;
}

long long solution(long long n)
{
  long long answer = 0;
  string s;
  vector<int> digits = split(n);
  sort(digits.begin(), digits.end(), greater<int>());

  for (const auto &d : digits)
  {
    s.append(to_string(d));
  }

  answer = stoll(s);

  return answer;
}