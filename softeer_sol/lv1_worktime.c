#include <stdio.h>

int main(void)
{
    int days;
    int total_minutes = 0;
    int start_hours, start_minutes;
    int end_hours, end_minutes;
    int tmp = 0;

    for (days = 0; days < 5; ++days)
    {
        scanf("%d:%d %d:%d", &start_hours, &start_minutes, &end_hours, &end_minutes);
        tmp = ((end_hours * 60) + end_minutes) - ((start_hours * 60) + start_minutes);
        total_minutes += tmp;
    }

    printf("%d", total_minutes);

    return 0;
}