/**
 * BOJ 2751 
 * Merge sort
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

static int *pArr = NULL;
static int *pTemp = NULL;

void merge_sort(int s, int e)
{
    if (e - s < 1)
        return;

    int m = s + (e - s) / 2;
    
    merge_sort(s, m);
    merge_sort(m + 1, e);

    for (int i = s; i <= e; ++i)
        pTemp[i] = pArr[i];
    
    int k = s;
    int index1 = s;
    int index2 = m + 1;

    while (index1 <= m && index2 <= e) {
        if (pTemp[index1] > pTemp[index2]) {
            pArr[k++] = pTemp[index2++];
        } else {
            pArr[k++] = pTemp[index1++];
        }
    }

    while (index1 <= m) 
        pArr[k++] = pTemp[index1++];

    while (index2 <= e)
        pArr[k++] = pTemp[index2++];
}

int main(void)
{
    int array_length = 0, i = 0;

    scanf("%d", &array_length);

    pArr = (int*)malloc(sizeof(int) * array_length);
    pTemp = (int*)malloc(sizeof(int) * array_length);

    for (i = 0; i < array_length; ++i) {
        scanf("%d", &pArr[i]);
    }

    merge_sort(0, array_length - 1);

    for (i = 0; i < array_length; ++i) {
        printf("%d\n", pArr[i]);
    }

    return 0;
}