#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int dataCount;
	cin >> dataCount;

	vector<int> numbers(dataCount, 0);

	for (int i = 0; i < dataCount; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());

	int toFind;
	cin >> toFind;

	for (int i = 0; i < toFind; i++) {
		bool find = false;
		int target;
		cin >> target;

		int startIndex = 0;
		int endIndex = numbers.size() - 1;

		while (startIndex <= endIndex) {
			int midIndex = (startIndex + endIndex) / 2;
			int mid = numbers[midIndex];

			if (mid > target) { endIndex = midIndex - 1; }
			else if (mid < target) { startIndex = midIndex + 1; }
			else { 
				find = true;
				break;
			}
		}

		if (find) { cout << 1 << "\n"; }
		else { cout << 0 << "\n"; }
	}
}