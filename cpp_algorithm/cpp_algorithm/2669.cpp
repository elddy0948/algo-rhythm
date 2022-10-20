#include <iostream>
#include <array>
#include <cstdlib>

const int MaxBoardSize = 16;

int boardSize;
std::array<int, MaxBoardSize> rows;
int answer = 0;

bool Place(int row, int column)
{
	for (int prev = 0; prev < column; prev++)
	{
		if (rows[prev] == row || (std::abs(rows[prev] - row) == std::abs(prev-column)))
			return false;
	}
	return true;
}

void BackTracking(int column)
{
	if (column == boardSize)
	{
		answer ++;
	}

	for (int row = 0; row < boardSize; row++)
	{
		if (Place(row, column))
		{
			rows[column] = row;
			BackTracking(column + 1);
		}
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> boardSize;

	BackTracking(0);

	std::cout << answer;

	return 0;
}