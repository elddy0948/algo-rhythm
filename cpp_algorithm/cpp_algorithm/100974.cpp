#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

const int MaxArraySize = 9;
int n;
std::array<int, MaxArraySize> arr;

void CreatePermutation()
{
	do
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	} while (std::next_permutation(arr.begin(), arr.begin() + n));
}

int main(void)
{
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	CreatePermutation();

	return 0;
}