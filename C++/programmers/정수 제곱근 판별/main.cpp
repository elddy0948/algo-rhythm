#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

long long solution(long long n)
{
  ll answer = -1;
  ll possible = sqrt(n);

  if (possible * possible == n)
  {
    answer = pow(possible + 1, 2);
  }

  return answer;
}
