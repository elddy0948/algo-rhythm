#include<iostream>
#include <map>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int numberOfPeople;
		cin >> numberOfPeople;
		map<int, int> distMap;

		for (int n = 0; n < numberOfPeople; n++)
		{
			int dist;
			cin >> dist;
			(dist < 0) ? distMap[-dist]++ : distMap[dist]++;
		}

		cout << '#' << test_case << ' ' << distMap.begin()->first << ' ' << distMap.begin()->second << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}