#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Element {
    int index;
    int value;
};

int comparator(const void *lhs, const void *rhs)
{
    int l = ((struct Element*)lhs)->value;
    int r = ((struct Element*)rhs)->value;

    return (l - r);
}

int main(void) 
{
    int array_size = 0, i = 0, value = 0, most_moved = -1;
    struct Element *arr = NULL;

    scanf("%d", &array_size);

    arr = (struct Element*)malloc(sizeof(struct Element) * array_size);

    for (i = 0; i < array_size; ++i) {
        scanf("%d", &value);
        struct Element e = {i, value};
        arr[i] = e;
    }

    qsort(arr, array_size, sizeof(struct Element), comparator);

    for (i = 0; i < array_size; ++i) {
        if (most_moved < arr[i].index - i)
            most_moved = arr[i].index - i;
    }

    printf("%d", most_moved + 1);

    free(arr);

    return 0;
}