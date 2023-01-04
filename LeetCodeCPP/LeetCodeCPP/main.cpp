#include <iostream>
#include "Solution79.cpp"

int main() {
  
  Solution79 sol = Solution79();
  
  vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  string word = "ABCCED";
  
  std::cout << sol.exist(board, word) << std::endl;
  
  return 0;
}
