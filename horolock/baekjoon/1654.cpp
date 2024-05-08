#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> lans;

	int lan_wire = 0;
	int lan_count = 0;
	int required_lan = 0;
	int i = 0;
	int answer = 0;

	ll left = 1;
	ll right = 1;
	ll mid = 0;

	cin >> lan_count >> required_lan;

	for (i = 0; i < lan_count; ++i)
	{
		cin >> lan_wire;
		lans.push_back(lan_wire);
	}

	sort(lans.begin(), lans.end());

	right = lans[lan_count - 1];

	while (left <= right)
	{
		mid = (left + right) / 2;
		int count = 0;

		for (i = 0; i < lan_count; ++i)
			count += lans[i] / mid;

		if (count >= required_lan)
		{
			left = mid + 1;
			if (answer < mid) answer = mid;
		}
		else
			right = mid - 1;
	}

	cout << answer;

	return 0;
}