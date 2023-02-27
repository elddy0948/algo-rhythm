#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

vector<string> split(string input, char delimiter)
{
  vector<string> result;
  stringstream ss(input);
  string temp;

  while (getline(ss, temp, delimiter))
  {
    result.push_back(temp);
  }

  return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
  set<string> s = set(report.begin(), report.end());
  vector<string> newReport = vector(s.begin(), s.end());

  unordered_map<string, pair<vector<string>, int>> table;

  for (const auto &user : id_list)
  {
    table[user] = make_pair(vector<string>(), 0);
  }

  for (const auto &reportInfo : newReport)
  {
    vector<string> info = split(reportInfo, ' ');
    table[info[0]].first.push_back(info[1]);
    table[info[1]].second++;
  }

  vector<int> receivedMail;

  for (const auto &id : id_list)
  {
    int mailCount = 0;
    for (const auto &reportedUser : table[id].first)
    {
      if (table[reportedUser].second >= k)
      {
        mailCount++;
      }
    }
    receivedMail.push_back(mailCount);
  }

  return receivedMail;
}

int main()
{
  vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
  vector<string> report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
  vector<int> res = solution(id_list, report, 2);

  for (const auto val : res)
  {
    cout << val << endl;
  }
  return 0;
}