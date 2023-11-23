#include <stdio.h>

int main(void)
{
    unsigned int car_a, car_b;
    scanf("%d %d", &car_a, &car_b);

    if (car_a > car_b) { printf("A"); }
    else if (car_a < car_b) { printf("B"); }
    else { printf("same"); }
    return 0;
}