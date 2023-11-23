#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Table {
    char* room_name;
    int time_line[25];
};

int main(void)
{
    unsigned int room_count, reservation_count;
    char* rooms[50] = {};
    char* room_name = NULL;

    Table*
    

    scanf("%d %d", &room_count, &reservation_count);

    for (int i = 0; i < room_count; ++i)
    {
        room_name = malloc(sizeof(char) * 10);
        scanf("%s", room_name);
        rooms[i] = room_name;
        room_name = NULL;
    }

    room_name = malloc(sizeof(char) * 10);
    int start, end;
    scanf("%s %d %d", room_name, &start, &end);

    for (int i = 0; i < room_count; ++i)
    {
        printf("%s\n", rooms[i]);
    }


    free(room_name);
    return 0;
}