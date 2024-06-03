#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_NUMBER      10001

int main(void)
{
    int number_count[MAX_NUMBER] = {0};
    int number_size = 0, i = 0, number = 0, j = 0;

    scanf("%d", &number_size);

    for (i = 0; i < number_size; ++i) {
        scanf("%d", &number);
        number_count[number]++;
    }

    for (i = 0; i < MAX_NUMBER; ++i) {
        if (number_count[i]) {
            for (j = 0; j < number_count[i]; ++j)
                printf("%d\n", i);
        }
    }

    return 0;
}