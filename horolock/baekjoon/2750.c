#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int number_size = 0, i = 0, j = 0;
    int *arr = NULL;

    scanf("%d", &number_size);

    arr = (int*)malloc(sizeof(int) * number_size);

    for (i = 0; i < number_size; ++i) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < number_size - 1; ++i) {
        for (j = 0; j < number_size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < number_size; ++i)
        printf("%d\n", arr[i]);

    free(arr);

    return 0;
}