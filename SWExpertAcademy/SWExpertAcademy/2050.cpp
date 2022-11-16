#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	char c;

	while (cin >> c)
	{
		if (c - 'a' < 0) { cout << c - 'A' << ' '; }
		else { cout << c - 'a' << ' '; }
	}
	return 0;
}