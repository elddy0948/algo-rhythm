#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int p, q, r, s, w;

		cin >> p >> q >> r >> s >> w;

		int costA = p * w;
		int costB = 0;

		if (r >= w) { costB = q; }
		else { costB = (w - r) * s + q; }

		cout << '#' << test_case << ' ' << ((costA < costB) ? costA : costB) << '\n';
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}