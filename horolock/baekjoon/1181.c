#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparator(const void *lhs, const void *rhs)
{
    const char* lhs_str = (const char*)lhs;
    const char* rhs_str = (const char*)rhs;

    size_t lhs_len = strlen(lhs_str);
    size_t rhs_len = strlen(rhs_str);

    if (lhs_len == rhs_len) { return strcmp(lhs_str, rhs_str); }

    return (lhs_len - rhs_len);
}

int main(void)
{
    int number_of_words = 0, i = 0;
    char arr[20001][51];

    scanf("%d", &number_of_words);

    for (i = 0; i < number_of_words; ++i) {
        scanf("%s", arr[i]);
    }

    qsort(arr, number_of_words, 51, comparator);

    for (int i = 0; i < number_of_words; i++) {
		if (strcmp(arr[i], arr[i+1]) != 0 || i == number_of_words - 1)
			printf("%s\n", arr[i]);
	}

    return 0;
}