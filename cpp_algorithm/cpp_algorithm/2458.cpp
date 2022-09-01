#include <iostream>
#include <vector>

void InputStudentsAndCompares(int& students, int& compares)
{
	std::cin >> students >> compares;
	return;
}

void InitCompareGraph(std::vector<std::vector<int>>& graph, int numberOfCompares)
{
	for (int i = 1; i <= numberOfCompares; i++)
	{
		int shortStudent, tallStudent;

		std::cin >> shortStudent >> tallStudent;

		graph[shortStudent][tallStudent] = 1;
		graph[tallStudent][shortStudent] = 2;
	}
}

void Floyd(std::vector<std::vector<int>>& graph, int numberOfStudents)
{
	for (int middle = 1; middle <= numberOfStudents; middle++)
	{
		for (int start = 1; start <= numberOfStudents; start++)
		{
			for (int target = 1; target <= numberOfStudents; target++)
			{
				if (graph[start][target] == 0)
				{
					if (graph[start][middle] != 0 && graph[middle][target] != 0 && graph[start][middle] == graph[middle][target])
					{
						graph[start][target] = graph[start][middle];
					}
				}
			}
		}
	}
}

int Solution2458(void)
{
	int numberOfStudents;
	int numberOfCompares;
	int answer = 0;

	InputStudentsAndCompares(numberOfStudents, numberOfCompares);

	std::vector<std::vector<int>> compareGraph(numberOfStudents + 1, std::vector<int>(numberOfStudents + 1, 0));

	InitCompareGraph(compareGraph, numberOfCompares);

	Floyd(compareGraph, numberOfStudents);

	for (int i = 1; i <= numberOfStudents; i++)
	{
		int cantCompareCount = 0;
		for (int j = 1; j <= numberOfStudents; j++)
		{
			if (compareGraph[i][j] == 0)
			{
				cantCompareCount++;
			}
			if (cantCompareCount > 1)
			{
				break;
			}
		}
		if (cantCompareCount == 1)
		{
			answer++;
		}
	}

	std::cout << answer;

	return 0;
}