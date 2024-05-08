#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define ARRAY_MAX_SIZE 10001

int arr[ARRAY_MAX_SIZE];

int main(void)
{
	int length = 0;
	int target = 0;
	int start_point = 0, end_point = 0;
	int i = 0;
	int count = 0;
	int sum = 0;

	scanf("%d %d", &length, &target);

	for (i = 0; i < length; ++i)
	{
		scanf("%d", &arr[i]);
	}

	while (start_point <= length && end_point <= length)
	{
		if (sum < target)
		{
			sum += arr[end_point++];
		}
		else if (sum > target)
		{
			sum -= arr[start_point++];
		}
		else if (sum == target)
		{
			count++;
			sum -= arr[start_point++];
		}
	}

	printf("%d", count);

	return 0;
}