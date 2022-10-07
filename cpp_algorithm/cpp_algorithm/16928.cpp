#include <iostream>
#include <vector>
#include <queue>

const int BOARD_SIZE = 11;

std::vector<std::vector<int>> board(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));
std::vector<std::vector<bool>> visited(BOARD_SIZE, std::vector<bool>(BOARD_SIZE, false));
std::queue<std::pair<int, int>> q;
int ladderCount;
int snakeCount;
int rollCount = 0;

void Input()
{
	std::cin >> ladderCount >> snakeCount;

	for (int i = 0; i < ladderCount; i++)
	{
		int from, to;
		std::cin >> from >> to;
		board[from / 10][from % 10] = to;
	}

	for (int i = 0; i < snakeCount; i++)
	{
		int from, to;
		std::cin >> from >> to;
		board[from / 10][from % 10] = to;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	Input();

	q.push(std::make_pair(1, rollCount));

	while (!q.empty())
	{
		// first : space info , second : roll count
		auto space = q.front();
		q.pop();

		int currentInfo = space.first;
		int currentRollCount = space.second;

		if (currentInfo == 100)
		{
			std::cout << currentRollCount;
			break;
		}

		for (int i = 1; i <= 6; i++)
		{
			int nextSpace = currentInfo + i;

			if (board[nextSpace / 10][nextSpace % 10] != 0 && !visited[nextSpace / 10][nextSpace % 10])
			{
				q.push({ board[nextSpace / 10][nextSpace % 10], currentRollCount + 1 });
				visited[nextSpace / 10][nextSpace % 10] = true;
				continue;
			}
			else if (board[nextSpace / 10][nextSpace % 10] == 0 && !visited[nextSpace / 10][nextSpace % 10])
			{
				q.push({ nextSpace, currentRollCount + 1 });
				visited[nextSpace / 10][nextSpace % 10] = true;
			}
		}
	}

	return 0;
}