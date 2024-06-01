#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define NEEDED_NUMBER       666

int main(void)
{
    int target_movie_number = 0, counter = 1, temp = 0;
    int number = 0;
    
    scanf("%d", &target_movie_number);

    if (target_movie_number == 1) { 
        printf("666");
        return 0;
    }

    for (number = 667; ; number++) {
        for (temp = number; temp / 100 != 0; temp /= 10) {
            if (temp % 1000 == NEEDED_NUMBER) {
                counter++;
                break;
            }
        }

        if (counter == target_movie_number) {
            printf("%d", number);
            break;
        }
    }

    return 0;
}