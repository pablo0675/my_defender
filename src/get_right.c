/*
** EPITECH PROJECT, 2022
** defender
** File description:
** defender
*/

#include "my_defender.h"
#include "my.h"
#include <stdio.h>
#include <unistd.h>

void get_right
    (char **map, sfVector2u *pos, sfVector2f *checkpoint, is_changed_t *check)
{
    int len = 0;

    for (len = 0; checkpoint[len].x != -1; len++);
    if (check->last_dir != 2 && (map[pos->y][pos->x + 1] == '#' ||
                                 map[pos->y][pos->x + 1] == 'E')) {
        for (; map[pos->y][pos->x + 1] == '#' ||
               map[pos->y][pos->x + 1] == 'E';)
            pos->x++;
        checkpoint[len].x = (pos->x * 40) + ((40 - ENEMY_SIZE.x) / 2);
        checkpoint[len].y = (pos->y * 40) + ((40 - ENEMY_SIZE.y) / 2);
        checkpoint[len + 1] = create_vectorf(-1, -1);
        check->is_changed++;
        check->last_dir = 1;
    }
}
