#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

const int MaxLength = 9;

int arrayLength;
int answer = 0;
std::vector<int> arr(MaxLength, 0);
std::vector<int> pickedNumbers(MaxLength, 0);

void Input() {
	std::cin >> arrayLength;

	for (int index = 0; index < arrayLength; index++)
	{
		std::cin >> arr[index];
	}
}

int BackTracking(int index, int bitMask) {
	if (index == arrayLength) {
		int sum = 0;
		for (int i = 0; i < arrayLength - 1; i++) {
			sum += std::abs(arr[pickedNumbers[i + 1]] - arr[pickedNumbers[i]]);
		}
		return sum;
	}

	int sum = 0;
	for (int i = 0; i < arrayLength; i++) {
		if ((bitMask & (1 << i)) != 0) { continue; }
		pickedNumbers[index] = i;
		sum = std::max(sum, BackTracking(index + 1, bitMask | (1 << i)));
	}

	return sum;
}

int main(void) 
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	Input();
	std::cout << BackTracking(0, 0);
	
	return 0;
}