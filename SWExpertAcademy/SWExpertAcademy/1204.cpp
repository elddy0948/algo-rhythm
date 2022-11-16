//ù ��° �ٿ� �׽�Ʈ ���̽��� �� T�� �־�����.
//
//�� �׽�Ʈ ���̽��� ù �ٿ��� �׽�Ʈ ���̽��� ��ȣ�� �־����� �� ���� �ٺ��ʹ� ������ �־�����.

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