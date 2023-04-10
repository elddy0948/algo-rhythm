#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct {
	int age;
	string name;
	int memberNumber;
} Member;

void merge(vector<Member>& members, const int left, const int mid, const int right) {
	const int leftArraySize = mid - left + 1;
	const int rightArraySize = right - mid;

	Member* leftArray = new Member[leftArraySize];
	Member* rightArray = new Member[rightArraySize];

	for (auto i = 0; i < leftArraySize; i++) { leftArray[i] = members[left + i]; }
	for (auto i = 0; i < rightArraySize; i++) { rightArray[i] = members[mid + 1 + i]; }

	auto indexOfLeftArray = 0;
	auto indexOfRightArray = 0;
	int indexOfMergedArray = left;

	while (indexOfLeftArray < leftArraySize && indexOfRightArray < rightArraySize) {
		if (leftArray[indexOfLeftArray].age < rightArray[indexOfRightArray].age) {
			members[indexOfMergedArray] = leftArray[indexOfLeftArray];
			indexOfLeftArray++;
		}
		else if (leftArray[indexOfLeftArray].age == rightArray[indexOfRightArray].age) {
			if (leftArray[indexOfLeftArray].memberNumber < rightArray[indexOfRightArray].memberNumber) {
				members[indexOfMergedArray] = leftArray[indexOfLeftArray];
				indexOfLeftArray++;
			}
			else {
				members[indexOfMergedArray] = rightArray[indexOfRightArray];
				indexOfRightArray++;
			}
		}
		else {
			members[indexOfMergedArray] = rightArray[indexOfRightArray];
			indexOfRightArray++;
		}
		indexOfMergedArray++;
	}

	while (indexOfLeftArray < leftArraySize) {
		members[indexOfMergedArray] = leftArray[indexOfLeftArray];
		indexOfLeftArray++;
		indexOfMergedArray++;
	}

	while (indexOfRightArray < rightArraySize) {
		members[indexOfMergedArray] = rightArray[indexOfRightArray];
		indexOfRightArray++;
		indexOfMergedArray++;
	}

	delete[] leftArray;
	delete[] rightArray;
}

void merge_sort(vector<Member>& members, const int begin, const int end) {
	if (begin >= end) { return; }
	auto mid = begin + (end - begin) / 2;

	merge_sort(members, begin, mid);
	merge_sort(members, mid + 1, end);
	merge(members, begin, mid, end);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<Member> members;

	for (auto i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		members.emplace_back(Member{ age, name, i });
	}

	merge_sort(members, 0, members.size() - 1);

	for (const auto& m : members) {
		cout << m.age << ' ' << m.name << '\n';
	}

	return 0;
}