#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int p, k;

	cin >> p >> k;

	int rotateCount = 0;

	if (p < k) 
	{
		rotateCount = (999 - k);
		rotateCount += (p + 1);
	}
	else
	{
		rotateCount = (p - k + 1);
	}

	cout << rotateCount;

	return 0;
}