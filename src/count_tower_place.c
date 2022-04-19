/*
** EPITECH PROJECT, 2022
** create_tower_place.c
** File description:
** create_tower_place
*/

#include "my_defender.h"
#include "my.h"

void add_count_tower(char **map, int y, int x, int *count)
{
    if (map[y][x] == 'T') {
        *count = *count + 1;
    }
}

int count_nb_place(char **map)
{
    int count = 0;

    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            add_count_tower(map, y, x, &count);
        }
    }
    return count;
}
