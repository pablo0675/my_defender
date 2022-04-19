/*
** EPITECH PROJECT, 2022
** create_path_tile_utils.c
** File description:
** create_path_tile_utils
*/

#include "my_defender.h"

void count_path(char **map, int x, int y, int *count)
{
    if (map[y][x] == '#')
        *count = *count + 1;
}

int nb_path_tile(char **map)
{
    int count = 2;

    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\n' && map[y][x] != '\0'; x++) {
            count_path(map, x, y, &count);
        }
    }
    return count;
}

void rotate_sprite(sfSprite *sprite, float angle)
{
    if (angle == 90) {
        sfSprite_setOrigin(sprite, create_vectorf(0, TILE));
        sfSprite_setRotation(sprite, angle);
    }
    if (angle == 180) {
        sfSprite_setOrigin(sprite, create_vectorf(TILE, TILE));
        sfSprite_setRotation(sprite, angle);
    }
    if (angle == 270) {
        sfSprite_setOrigin(sprite, create_vectorf(TILE, 0));
        sfSprite_setRotation(sprite, angle);
    }
}
