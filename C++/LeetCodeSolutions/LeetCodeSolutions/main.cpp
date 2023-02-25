#include <iostream>
#include <string>
#include <bitset>

using namespace std;

bool queryString(string s, int n) {
  for (int i = n; i > n / 2; i--) {
    const auto& iToBinary = bitset<32>(i).to_string();
    
    if (s.find(iToBinary.substr(iToBinary.find("1"))) == string::npos) { return false; }
  }
  
  return true;
}

int main(int argc, const char * argv[]) {
  bool ans = queryString("0110", 3);
  
  cout << ans << endl;
  
  return 0;
}
