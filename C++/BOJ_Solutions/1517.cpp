#include <iostream>
#include <vector>

using namespace std;

static long swapCount = 0;

void merge(vector<int>& numbers, const int left, const int mid, const int right) {
	const auto leftArraySize = mid - left + 1;
	const auto rightArraySize = right - mid;

	auto* leftArray = new int[leftArraySize];
	auto* rightArray = new int[rightArraySize];

	for (int i = 0; i < leftArraySize; i++) { leftArray[i] = numbers[left + i]; }
	for (int i = 0; i < rightArraySize; i++) { rightArray[i] = numbers[mid + 1 + i]; }

	auto indexOfLeft = 0;
	auto indexOfRight = 0;
	int indexOfMerged = left;

	while (indexOfLeft < leftArraySize && indexOfRight < rightArraySize) {
		if (leftArray[indexOfLeft] <= rightArray[indexOfRight]) {
			numbers[indexOfMerged] = leftArray[indexOfLeft];
			indexOfLeft++;
		}
		else {
			numbers[indexOfMerged] = rightArray[indexOfRight];
			swapCount += (leftArraySize - indexOfLeft);
			indexOfRight++;
		}
		indexOfMerged++;
	}

	while (indexOfLeft < leftArraySize) {
		numbers[indexOfMerged] = leftArray[indexOfLeft];
		indexOfLeft++;
		indexOfMerged++;
	}

	while (indexOfRight < rightArraySize) {
		numbers[indexOfMerged] = rightArray[indexOfRight];
		indexOfRight++;
		indexOfMerged++;
	}

	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(vector<int>& numbers, const int begin, const int end) {
	if (begin >= end) { return; }
	auto mid = begin + (end - begin) / 2;
	mergeSort(numbers, begin, mid);
	mergeSort(numbers, mid + 1, end);
	merge(numbers, begin, mid, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;
	vector<int> numbers(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	mergeSort(numbers, 0, numbers.size() - 1);

	cout << swapCount;
	return 0;
}