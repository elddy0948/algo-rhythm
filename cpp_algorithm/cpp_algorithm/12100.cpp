#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const int maxBoardSize = 21;

int n;
int maxNumber = -1;
std::vector<std::vector<int>> board(maxBoardSize, std::vector<int>(maxBoardSize, 0));

void Input() {
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> board[i][j];
		}
	}
}

// Move block
void Shift(int type)
{
	std::queue<int> q;

	switch (type) {
	case 0: // Shift Left
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j]) { q.push(board[i][j]); }
				board[i][j] = 0;
			}
			int index = 0;
			
			while (!q.empty()) {
				int data = q.front(); 
				q.pop();

				if (board[i][index] == 0) { board[i][index] = data; }
				else if (board[i][index] == data) {
					board[i][index] *= 2;
					index++;
				}
				else {
					index++;
					board[i][index] = data;
				}
			}
		}
		break;
	case 1:	// Right
		for (int i = 0; i < n; i++) {
			for (int j = n; j >= 0; j--) {
				if (board[i][j]) { q.push(board[i][j]); }
				board[i][j] = 0;
			}
			int index = n - 1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[i][index] == 0) { board[i][index] = data; }
				else if (board[i][index] == data) {
					board[i][index] *= 2;
					index--;
				}
				else {
					index--;
					board[i][index] = data;
				}
			}
		}
		break;
	case 2:	// Up
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[j][i]) { q.push(board[j][i]); }
				board [j][i] = 0;
			}
			int index = 0;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[index][i] == 0) { board[index][i] = data; }
				else if (board[index][i] == data) {
					board[index][i] *= 2;
					index++;
				}
				else {
					index++;
					board[index][i] = data;
				}
			}
		}
		break;
	case 3:	 // Down
		for (int i = 0; i < n; i++) {
			for (int j = n; j >= 0; j--) {
				if (board[j][i]) { q.push(board[j][i]); }
				board[j][i] = 0;
			}
			int index = n - 1;

			while (!q.empty()) {
				int data = q.front();
				q.pop();

				if (board[index][i] == 0) { board[index][i] = data; }
				else if (board[index][i] == data) {
					board[index][i] *= 2;
					index--;
				}
				else {
					index--;
					board[index][i] = data;
				}
			}
		}
		break;
	}
}

void BackTracking(int count) {
	if (count == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				maxNumber = std::max(maxNumber, board[i][j]);
			}
		}
		return;
	}

	std::vector<std::vector<int>> tempBoard(maxBoardSize, std::vector<int>(maxBoardSize, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tempBoard[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		Shift(i);
		BackTracking(count + 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = tempBoard[i][j];
			}
		}
	}
}


int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	Input();
	BackTracking(0);

	std::cout << maxNumber;

	return 0;
}