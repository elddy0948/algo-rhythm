#include <iostream>

#include "Problems/1023.cpp"

using namespace std;


int main(int argc, const char * argv[]) {
  Solution sol;
  
  vector<string> inp = {
    "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"
  };
  
  vector<bool> ans = sol.camelMatch(inp, "FB");
  
  
  for (const auto result : ans) {
    cout << result << endl;
  }
  
  return 0;
}
