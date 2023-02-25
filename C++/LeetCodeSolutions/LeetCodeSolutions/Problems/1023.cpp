#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> result;
    
    for (const auto& query : queries) {
      result.emplace_back(isMatch(query, pattern));
    }
    
    return result;
  }
  
private:
  bool isMatch(const string& query, const string& pattern) {
    int matchCount = 0;
    
    for (const auto& c : query) {
      if (matchCount < pattern.length() && pattern[matchCount] == c) { matchCount++; }
      else if (isupper(c)) { return false; }
    }
    
    return matchCount == pattern.length();
  }
};
