#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int find_number(int l, int r, int target)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (arr[m] == target)
			return 1;
		if (arr[m] < target)
			l = m + 1;
		else
			r = m - 1;
	}
	return 0;
}

int main(void)
{
	int arr_length = 0;
	int i = 0;
	int element = 0;
	int test_case = 0;
	int target = 0;

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> arr_length;

	for (i = 0; i < arr_length; ++i)
	{
		cin >> element;
		arr.push_back(element);
	}

	sort(arr.begin(), arr.end());

	cin >> test_case;

	for (i = 0; i < test_case; ++i)
	{
		cin >> target;
		cout << find_number(0, arr.size() - 1, target) << '\n';
	}

	return 0;
}