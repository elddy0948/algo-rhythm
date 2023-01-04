#include <vector>
#include <string>

using namespace std;


class Solution79 {
private:
  size_t boardHeight;
  size_t boardWidth;
  
public:
  bool exist(vector<vector<char>>& board, string word) {
    boardHeight = board.size();
    boardWidth = board.front().size();
    vector<vector<bool>> visited(boardHeight, vector<bool>(boardWidth, false));
    
    for (int i = 0; i < boardHeight; i++) {
      for (int j = 0; j < boardWidth; j++) {
        if (backtracking(board, visited, word, 0, i, j)) {
          return true;
        }
      }
    }
    
    return false;
  }
  
private:
  bool backtracking(vector<vector<char>> &board,
                    vector<vector<bool>> &visited,
                    string word,
                    int index,
                    int i,
                    int j) {
    if (index == word.size()) { return true; }
    if (i < 0 || j < 0 || i >= boardHeight || j >= boardWidth
        || visited[i][j] || board[i][j] != word[index]) {
      return false;
    }
    
    visited[i][j] = true;
    
    bool ret = backtracking(board, visited, word, index + 1, i +1, j)
    || backtracking(board, visited, word, index + 1, i, j + 1)
    || backtracking(board, visited, word, index + 1, i - 1, j)
    || backtracking(board, visited, word, index + 1, i, j - 1);
    
    visited[i][j] = false;
    
    return ret;
  }
};
