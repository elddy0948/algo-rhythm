#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE      5000000

int number_size = 0, target = 0;
int *arr = NULL;

void swap(int lhs, int rhs)
{
    int temp = arr[lhs];
    arr[lhs] = arr[rhs];
    arr[rhs] = temp;
}

int partition(int arr[], int low, int high)
{
    if (low + 1 == high) {
        if (arr[low] > arr[high])
            swap(low, high);
        return high;
    }

    int mid = (low + high) / 2;
    swap(low, mid);

    int pivot = arr[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (pivot < arr[j] && j > 0) {
            j--;
        }
        
        while (pivot > arr[i] && i < number_size - 1) {
            i++;
        }

        if (i <= j) {
            swap(i++, j--);
        }
    }

    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

void quick_sort(int arr[], int low, int high)
{
    int partition_index = partition(arr, low, high);

    if (partition_index == target) {
        return;
    } else if (target < partition_index) {
        quick_sort(arr, low, partition_index - 1);
    } else {
        quick_sort(arr, partition_index + 1, high);
    }
}

int main(void)
{
    int i = 0;

    scanf("%d %d", &number_size, &target);

    arr = (int*)malloc(sizeof(int) * number_size);

    for (i = 0; i < number_size; ++i) {
        scanf("%d", &arr[i]);
    }

    target -= 1;

    quick_sort(arr, 0, number_size - 1);

    printf("%d", arr[target]);

    free(arr);

    return 0;
}