#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	char c;

	while (cin >> c)
	{
		if (c >= 97 && c <= 122)
		{
			cout << (char)(c - 32);
		}
		else
		{
			cout << c;
		}
	}

	return 0;
}