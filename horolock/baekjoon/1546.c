/**
 * BOJ 1546
 * 평균
 * Math
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int number_of_subjects = 0, i = 0, sum = 0, score = 0, max = -1;
    double average = 0.0f;

    scanf("%d", &number_of_subjects);

    for (i = 0; i < number_of_subjects; ++i) {
        scanf("%d", &score);

        if (max < score)
            max = score;
        
        sum += score;
    }

    average = ((double)sum / (double)max) * 100;
    average /= (double)number_of_subjects;

    printf("%f", average);
    
    return 0;
}