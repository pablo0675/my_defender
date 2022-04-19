/*
** EPITECH PROJECT, 2022
** count_checkpoint.c
** File description:
** count_checkpoint
*/

#include "my_defender.h"
#include "my.h"

sfVector2u get_pos_start(char **map, int x, int y, sfVector2u *pos)
{
    if (map[y][x] == 'S') {
        pos->x = x;
        pos->y = y;
    }
}

void count_horizontal
(char **map, sfVector2u *pos, int *count, is_changed_t *check)
{
    if (check->last_dir != 2 && (map[pos->y][pos->x + 1] == '#' ||
        map[pos->y][pos->x + 1] == 'E')) {
        for (; map[pos->y][pos->x + 1] == '#' ||
            map[pos->y][pos->x + 1] == 'E';)
            pos->x++;
        *count = *count + 1;
        check->is_changed++;
        check->last_dir = 1;
    }
    if (check->last_dir != 1 && check->is_changed == 0 &&
        pos->x != 0 && map[pos->y][pos->x - 1] == '#') {
        for (; pos->x != 0 && (map[pos->y][pos->x - 1] == '#' ||
            map[pos->y][pos->x - 1] == 'E');)
            pos->x--;
        *count = *count + 1;
        check->is_changed++;
        check->last_dir = 2;
    }
}

void count_vertical
(char **map, sfVector2u *pos, int *count, is_changed_t *check)
{
    if (check->last_dir != 4 && check->is_changed == 0 &&
        map[pos->y + 1] != NULL && (map[pos->y + 1][pos->x] == '#' ||
        map[pos->y + 1][pos->x] == 'E')) {
        for (; map[pos->y + 1] != NULL && (map[pos->y + 1][pos->x] == '#' ||
            map[pos->y + 1][pos->x] == 'E');)
            pos->y++;
        *count = *count + 1;
        check->is_changed++;
        check->last_dir = 3;
    }
    if (check->last_dir != 3 && check->is_changed == 0 &&
        pos->y != 0 && (map[pos->y - 1][pos->x] == '#' ||
        map[pos->y - 1][pos->x] == 'E')) {
        for (; pos->y != 0 && (map[pos->y - 1][pos->x] == '#' ||
            map[pos->y - 1][pos->x] == 'E');)
            pos->y--;
        *count = *count + 1;
        check->is_changed++;
        check->last_dir = 4;
    }
}

int count_checkpoint(char **map, sfVector2u *pos)
{
    int count = 1;
    is_changed_t check = {0, 0};

    for (; map[pos->y][pos->x] != 'E'; check.is_changed = 0) {
        count_horizontal(map, pos, &count, &check);
        count_vertical(map, pos, &count, &check);
    }
    return count;
}

int nb_checkpoint(char **map)
{
    sfVector2u pos;

    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0' && map[y][x] != '\n'; x++) {
            get_pos_start(map, x, y, &pos);
        }
    }
    return count_checkpoint(map, &pos);
}

