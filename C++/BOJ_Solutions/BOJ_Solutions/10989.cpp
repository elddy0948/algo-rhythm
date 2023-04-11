#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> numbers(10001, 0);

	for (auto i = 0; i < n; i++) { 
		int number;
		cin >> number;
		numbers[number]++;
	}

	for (auto i = 0; i <= 10000; i++) {
		if (numbers[i] != 0) {
			for (auto j = 0; j < numbers[i]; j++) {
				cout << i << '\n';
			}
		}
	}

	return 0;
}