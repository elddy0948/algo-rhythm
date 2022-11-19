#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int testCase;

	cin >> testCase;

	for (int tc = 1; tc <= testCase; tc++)
	{
		int productCount;
		cin >> productCount;
		vector<int> products(productCount + 1, 0);

		for (int p = 0; p < productCount; p++)
		{
			cin >> products[p];
		}

		long long base = -1;
		long long sum = 0;

		for (int i = productCount - 1; i >= 0; i--)
		{
			if (base < products[i])
			{ 
				base = products[i];
				continue;
			}

			if (base >= products[i]) { sum += (base - products[i]); }
		}

		cout << '#' << tc << ' ' << sum << '\n';
	}

	return 0;
}