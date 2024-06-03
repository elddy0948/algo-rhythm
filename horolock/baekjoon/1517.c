/**
 * BOJ Problem 1517
 * 2024.06.03
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

static int *pArray = NULL;
static int *pTemp = NULL;
static long result = 0;

void merge_sort(int left, int right)
{
    if (right - left < 1)
        return;

    int mid = left + (right - left) / 2;

    merge_sort(left, mid);
    merge_sort(mid + 1, right);

    for (int i = left; i <= right; ++i)
        pTemp[i] = pArray[i];
    
    int k = left;
    int n1 = left;
    int n2 = mid + 1;

    while (n1 <= mid && n2 <= right) {
        if (pTemp[n1] > pTemp[n2]) {
            result = result + n2 - k;
            pArray[k++] = pTemp[n2++];
        } else {
            pArray[k++] = pTemp[n1++];
        }
    }

    while (n1 <= mid)
        pArray[k++] = pTemp[n1++];
    
    while (n2 <= right)
        pArray[k++] = pTemp[n2++];
}

int main(void)
{
    int array_size = 0, i = 0;

    scanf("%d", &array_size);

    pArray = (int*)malloc(sizeof(int) * array_size + 1);
    pTemp = (int*)malloc(sizeof(int) * array_size + 1);

    pArray[0] = 0;
    pTemp[0] = 0;

    for (i = 1; i <= array_size; ++i)
        scanf("%d", &pArray[i]);

    result = 0;

    merge_sort(1, array_size);

    printf("%ld", result);

    free(pArray);
    free(pTemp);

    return 0;
}