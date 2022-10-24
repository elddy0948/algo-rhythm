#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxBoardSize = 9;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int rowCount, colCount;
int answer = 0;

int board1[MaxBoardSize][MaxBoardSize];
int board2[MaxBoardSize][MaxBoardSize];

vector<pair<int, int>> cctv;

void Input()
{
	cin >> rowCount >> colCount;

	for (int r = 0; r < rowCount; r++)
	{
		for (int c = 0; c < colCount; c++)
		{
			cin >> board1[r][c];
			if (board1[r][c] != 0 && board1[r][c] != 6) { cctv.push_back({ r, c }); }
			if (board1[r][c] == 0) { answer++; }
		}
	}
}

bool IsSafe(int row, int col)
{
	return (row >= 0 && row < rowCount&& col >= 0 && col < colCount);
}

void upd(int row, int col, int direction)
{
	direction %= 4;
	while (true)
	{
		row += dy[direction];
		col += dx[direction];

		if (!IsSafe(row, col) || board2[row][col] == 6) return;
		if (board2[row][col] != 0) continue;
		board2[row][col] = 7;
	}
}

void CountSpace()
{
	int space = 0;
	for (int r = 0; r < rowCount; r++)
	{
		for (int c = 0; c < colCount; c++)
		{
			if (board2[r][c] == 0) space++;
		}
	}
	answer = min(answer, space);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Input();

	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++)
	{
		for (int r = 0; r < rowCount; r++)
		{
			for (int c = 0; c < colCount; c++)
			{
				board2[r][c] = board1[r][c];
			}
		}

		int brute = tmp;

		for (int i = 0; i < cctv.size(); i++)
		{
			int dir = brute % 4;
			brute /= 4;

			int cctvRow = cctv[i].first;
			int cctvCol = cctv[i].second;

			if (board1[cctvRow][cctvCol] == 1) { upd(cctvRow, cctvCol, dir); }
			else if (board1[cctvRow][cctvCol] == 2)
			{
				upd(cctvRow, cctvCol, dir);
				upd(cctvRow, cctvCol, dir + 2);
			}
			else if (board1[cctvRow][cctvCol] == 3)
			{
				upd(cctvRow, cctvCol, dir);
				upd(cctvRow, cctvCol, dir + 1);
			}
			else if (board1[cctvRow][cctvCol] == 4)
			{
				upd(cctvRow, cctvCol, dir);
				upd(cctvRow, cctvCol, dir + 1);
				upd(cctvRow, cctvCol, dir + 2);
			}
			else
			{
				upd(cctvRow, cctvCol, dir);
				upd(cctvRow, cctvCol, dir + 1);
				upd(cctvRow, cctvCol, dir + 2);
				upd(cctvRow, cctvCol, dir + 3);
			}
		}
		CountSpace();
	}

	cout << answer;

	return 0;
}