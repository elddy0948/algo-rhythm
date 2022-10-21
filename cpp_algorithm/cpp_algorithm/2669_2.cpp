#include <iostream>
#include <bitset>
#include <vector>

//15 * 2 - 1
std::bitset<30> rw, ld, rd;
int boardSize;
int answer = 0;

void BackTracking(int column)
{
	if (column == boardSize) { answer++; return; }
	for (int row = 0; row < boardSize; row++)
	{
		if (!rw[row] && !ld[row - column + boardSize - 1] && !rd[row + column])
		{
			rw[row] = ld[row - column + boardSize - 1] = rd[row + column] = true;
			BackTracking(column + 1);
			rw[row] = ld[row - column + boardSize - 1] = rd[row + column] = false;
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