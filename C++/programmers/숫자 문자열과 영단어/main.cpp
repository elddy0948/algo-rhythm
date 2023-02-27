#include <string>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;

int solution(string s)
{
  int answer = 0;

  vector<pair<string, string>> vec = {{"zero", "0"},
                                      {"one", "1"},
                                      {"two", "2"},
                                      {"three", "3"},
                                      {"four", "4"},
                                      {"five", "5"},
                                      {"six", "6"},
                                      {"seven", "7"},
                                      {"eight", "8"},
                                      {"nine", "9"}};

  for (int i = 0; i < vec.size(); i++)
  {
    s = regex_replace(s, regex(vec[i].first), vec[i].second);
  }

  answer = stoi(s);

  return answer;
}

int main()
{
  int answer = solution("oneone");

  cout << answer << endl;

  return 0;
}