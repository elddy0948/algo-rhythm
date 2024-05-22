#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX(lhs, rhs)       (((lhs) > (rhs) ? lhs : rhs))

int main(void)
{
    unsigned int array_size = 0;
    int i = 0;
    int* arr = NULL;
    int* dp = NULL;
    int answer = 0;

    scanf("%d", &array_size);
    arr = (int*)malloc(sizeof(int) * array_size);
    dp = (int*)malloc(sizeof(int) * array_size);

    for (i = 0; i < array_size; ++i) {
        scanf("%d", &arr[i]);
    }

    dp[0] = arr[0];
    answer = arr[0];

    for (i = 1; i < array_size; ++i) {
        dp[i] = MAX(dp[i - 1] + arr[i], arr[i]);

        if (dp[i] > answer) {
            answer = dp[i];
        }
    }

    printf("%d", answer);

    free(arr);
    free(dp);

    return 0;
}