#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[501][501];
bool visited[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int paintCounter = 0;
int largestPaint = 0;

int main() {
  ios::sync_with_stdio();
  cin.tie();

  cin >> n >> m;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j] || board[i][j] == 0) {
        continue;
      }
      queue<pair<int, int>> Q;
      paintCounter++;
      visited[i][j] = true;
      Q.push({i, j});
      int paintSize = 0;
      
      while (!Q.empty()) {
        paintSize++;
        pair<int, int> current = Q.front();
        Q.pop();
        
        for (int direction = 0; direction < 4; direction++) {
          int nextX = current.first + dx[direction];
          int nextY = current.second + dy[direction];
          
          if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
            continue;
          }
          
          if (visited[nextX][nextY] || board[nextX][nextY] != 1) {
            continue;
          }

          visited[nextX][nextY] = true;
          Q.push({nextX, nextY});
        }
      }
      
      largestPaint = max(largestPaint, paintSize);
    }
  }
  
  cout << paintCounter << "\n" << largestPaint << endl;
}
