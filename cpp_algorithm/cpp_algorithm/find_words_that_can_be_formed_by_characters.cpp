#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
  int countCharacters(vector<string>& words, string chars)
  {
    const auto& letterInfo = Counter(chars);
    int result = 0;

    for (const auto& word : words)
    {
      if (CanMake(word, chars, letterInfo)) { result += word.length(); }
    }

    return result;
  }

private:
  unordered_map<char, int> Counter(const string& s)
  {
    unordered_map<char, int> results;
    for (const auto& c : s) { ++results[c]; }
    return results;
  }

  bool CanMake(const string& word, const string& chars, const unordered_map<char, int>& letterInfo)
  {
    if (word.length() > chars.length()) { return false; }
    unordered_map<char, int> wordLetterInfo;

    for (auto& c : word)
    {
      ++wordLetterInfo[c];
      if (!letterInfo.count(c) || letterInfo.at(c) < wordLetterInfo[c]) { return false; }
    }

    return true;
  }
};


int main(void)
{
  Solution sol;

  vector<string> words{ "hello", "world", "leetcode" };

  int answer = sol.countCharacters(words, "welldonehoneyr");

  cout << answer;

  return 0;
}