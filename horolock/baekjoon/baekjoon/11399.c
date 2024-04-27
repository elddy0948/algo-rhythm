#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE		1001

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int number_of_people = 0;
int withdraw_time = 0;
int time_array[MAX_ARRAY_SIZE];
int sum = 0;

int main(void)
{
	int i = 0;

	scanf("%d", &number_of_people);

	for (i = 0; i < number_of_people; ++i)
	{
		scanf("%d", &time_array[i]);
	}

	qsort(time_array, number_of_people, sizeof(int), compare);

	int time = 0;

	for (i = 0; i < number_of_people; ++i)
	{
		time = time + time_array[i];
		sum += time;
	}

	printf("%d", sum);

	return 0;
}