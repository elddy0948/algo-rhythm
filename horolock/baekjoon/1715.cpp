#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	priority_queue<int, vector<int>, greater<int>> shuffles;
	int test_case = 0;
	int i = 0;
	int card_size = 0;
	int answer = 0;

	cin >> test_case;

	for (i = 0; i < test_case; ++i)
	{
		cin >> card_size;
		shuffles.push(card_size);
	}

	while (shuffles.size() != 1)
	{
		int lhs = shuffles.top();
		shuffles.pop();
		int rhs = shuffles.top();
		shuffles.pop();

		answer += (lhs + rhs);

		shuffles.push(lhs + rhs);
	}

	cout << answer;

	return 0;
}