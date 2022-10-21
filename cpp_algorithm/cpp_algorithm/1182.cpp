#include <iostream>
#include <array>

const int MaxNumberCount = 21;

int numberCount;
int targetNumber;
std::array<int, MaxNumberCount> numbers;
int answer = 0;

void Input()
{
	std::cin >> numberCount >> targetNumber;

	for (int i = 0; i < numberCount; i++)
	{
		std::cin >> numbers[i];
	}
}

void BackTracking(int cursor, int sum)
{
	if (cursor == numberCount)
	{
		if (sum == targetNumber) answer++;
		return;
	}

	BackTracking(cursor + 1, sum);
	BackTracking(cursor + 1, sum + numbers[cursor]);
}

int main(void)
{
	Input();

	// 공집합 제외 (아무것도 선택하지 않은 경우)
	if (targetNumber == 0) answer = -1;

	BackTracking(0, 0);

	std::cout << answer;

	return 0;
}