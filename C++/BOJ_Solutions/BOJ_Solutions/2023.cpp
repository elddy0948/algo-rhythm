#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(const int n) {
	if (n <= 1) { return false; }
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) { return false; }
	}
	return true;
}

void backtracking(const int number, const int n, const int targetN) {
	if (n == targetN) {
		cout << number << '\n';
		return;
	}

	for (int i = 0; i <= 9; i++) {
		const auto nextNumber = number * 10 + i;
		if (isPrime(nextNumber)) {
			backtracking(nextNumber, n + 1, targetN);
		}
	}
}

int main() {
	int targetN;
	cin >> targetN;

	for (int i = 1; i <= 9; i++) {
		if (isPrime(i)) {
			backtracking(i, 1, targetN);
		}
	}
	
	return 0;
}