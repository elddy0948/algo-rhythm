#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int num)
{
  string answer = "";
  int absNum = abs(num);

  if (absNum % 2 == 1)
    answer = "Odd";
  else
    answer = "Even";

  return answer;
}