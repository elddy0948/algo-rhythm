#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int n) {
    char* answer = (char*)malloc(n * sizeof(char) + 1);
    unsigned int size = 0;
    unsigned int i = 0;
    unsigned int k = 0;

    for(size = 0; my_string[size]; ++size);

    for(i = size - n; i < size; ++i)
    {
        answer[k] = my_string[i];
        k++;
    }
    answer[k] = '\0';

    return answer;
}
