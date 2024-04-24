#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define LENGTH_INIT 100001

int main(void)
{
	int length = 0, target = 0;
	int i = 0, sum = 0;
	int min_length = LENGTH_INIT;
	int start_pointer = 0, end_pointer = 0;

	scanf("%d %d", &length, &target);

	int* arr = (int*)malloc(length * sizeof(int));	

	for (i = 0; i < length; ++i)
	{
		scanf("%d", &arr[i]);
	}

	while (start_pointer <= length && end_pointer <= length)
	{
		if (sum < target)
		{
			sum += arr[end_pointer++];
		}
		if (sum >= target)
		{
			sum -= arr[start_pointer++];
			if (min_length > (end_pointer - start_pointer + 1)) { min_length = end_pointer - start_pointer + 1; }
		}
	}

	if (min_length == LENGTH_INIT)
	{
		printf("%d", 0);
	}
	else
	{
		printf("%d", min_length);
	}

	return 0;
}