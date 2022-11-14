//첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
//
//각 테스트 케이스의 첫 줄에는 테스트 케이스의 번호가 주어지고 그 다음 줄부터는 점수가 주어진다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int testCase;

	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++)
	{
		int tcNum;
		cin >> tcNum;

		int largeScore = 0;
		vector<int> scoreVec(101, 0);

		for (int i = 0; i < 1000; i++)
		{
			int score;
			cin >> score;
			scoreVec[score]++;

			if (scoreVec[score] > scoreVec[largeScore]) { largeScore = score; }
			if (scoreVec[score] == scoreVec[largeScore] && score > largeScore) {
				largeScore = score;
			}
		}

		cout << '#' << tcNum << ' ' << largeScore << '\n';
	}

	return 0;
}