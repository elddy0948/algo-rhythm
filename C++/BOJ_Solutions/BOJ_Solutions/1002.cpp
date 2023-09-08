#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; ++i)
	{
		int answer = 0;
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

		double subtract = r1 > r2 ? r1 - r2 : r2 - r1;

		if (distance == 0 && r1 == r2)
			answer = -1;
		else if (distance < r1 + r2 && subtract < distance)
			answer = 2;
		else if (distance == r1 + r2 || subtract == distance)
			answer = 1;
		else
			answer = 0;

		cout << answer << '\n';
	}
	
	return 0;
}