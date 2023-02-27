#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number)
{
  string answer = "";

  for (int i = 0; i < phone_number.length() - 4; i++)
  {
    answer += "*";
  }

  for (int i = phone_number.length() - 4; i < phone_number.length(); i++)
  {
    answer += phone_number[i];
  }

  return answer;
}

string solution2(string phone_number)
{
  for (int i = 0; i < phone_number.length() - 4; i++)
  {
    phone_number.replace(i, 1, "*");
  }
  return phone_number;
}

int main()
{
  string sol = solution2("01012341234");

  cout << sol;

  return 0;
}