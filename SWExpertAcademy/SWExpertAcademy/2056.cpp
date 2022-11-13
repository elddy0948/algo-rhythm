#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	unordered_map<int, int> calendarInfo{
		{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31} 
	};


	int testCase;

	cin >> testCase;

	for (int tc = 1; tc <= testCase; tc++)
	{
		string date;

		cin >> date;
		
		string year = string(date.begin(), date.begin() + 4);
		string month = string(date.begin() + 4, date.begin() + 6);
		string day = string(date.begin() + 6, date.end());

		int intMonth = stoi(month);

		if (intMonth >= 1 && intMonth <= 12)
		{
			int intDay = stoi(day);
			if (intDay >= 1 && intDay <= calendarInfo[intMonth]) {
				cout << '#' << tc << ' ' << year << '/' << month << '/' << day << '\n';
				continue;
			}
		}

		cout << '#' << tc << ' ' << "-1\n";
	}

	return 0;
}