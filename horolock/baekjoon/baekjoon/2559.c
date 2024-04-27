#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdint.h>

#define TEMP_MIN		10000000
#define DAY_MAX			100001

int day_length = 0;
int max_days = 0;
int i = 0;
int temp_table[DAY_MAX];
int left_pointer = 0, right_pointer = 0;
int temperature = 0;
int highest_temp = TEMP_MIN;

int main(void)
{
	scanf("%d %d", &day_length, &max_days);

	right_pointer = left_pointer + max_days - 1;

	for (i = 0; i < day_length; ++i)
	{
		scanf("%d", &temp_table[i]);
	}

	for (i = left_pointer; i <= right_pointer; ++i)
	{
		temperature += temp_table[i];
	}

	highest_temp = temperature;

	while (right_pointer < day_length)
	{
		if (temperature > highest_temp) { highest_temp = temperature; }

		right_pointer++;
		temperature -= temp_table[left_pointer];
		temperature += temp_table[right_pointer];
		left_pointer++;
		
	}

	printf("%d", highest_temp);

	return 0;
}