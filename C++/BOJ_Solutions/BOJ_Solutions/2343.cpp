#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	cin.tie(0);
	cout.tie(0);

	int rectureCount;
	int blurayCount;
	int start = 0;
	int end = 0;

	// count input
	cin >> rectureCount >> blurayCount;

	// input lesson lengths
	vector<int> lessonLengths(rectureCount, 0);
	
	for (int i = 0; i < rectureCount; i++)
	{
		cin >> lessonLengths[i];
		if (start < lessonLengths[i]) { start = lessonLengths[i]; }
		end += lessonLengths[i];
	}

	while (start <= end)
	{
		int middle = (start + end) / 2;
		int brCount = 0;
		int sum = 0;

		for (const auto& length : lessonLengths)
		{
			if (sum + length > middle)
			{
				brCount++;
				sum = 0;
			}
			sum += length;
		}

		if (sum != 0) { brCount++; }
		if (brCount > blurayCount) { start = middle + 1; }
		else { end = middle - 1; }
	}

	cout << start;

	return 0;
}