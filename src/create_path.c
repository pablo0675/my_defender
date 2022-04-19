/*
** EPITECH PROJECT, 2022
** create_map.c
** File description:
** create_path
*/

#include "my_defender.h"
#include "my.h"
#include <stdio.h>
#include <unistd.h>

void get_left
(char **map, sfVector2u *pos, sfVector2f *checkpoint, is_changed_t *check)
{
    int len = 0;

    for (len = 0; checkpoint[len].x != -1; len++);
    if (check->last_dir != 1 && (map[pos->y][pos->x - 1] == '#' ||
        map[pos->y][pos->x - 1] == 'E')) {
        for (; pos->x != 0 &&
            (map[pos->y][pos->x - 1] == '#' ||
            map[pos->y][pos->x - 1] == 'E');)
            pos->x--;
        checkpoint[len].x = (pos->x * 40) + ((40 - ENEMY_SIZE.x) / 2);
        checkpoint[len].y = (pos->y * 40) + ((40 - ENEMY_SIZE.y) / 2);
        checkpoint[len + 1] = create_vectorf(-1, -1);
        check->is_changed++;
        check->last_dir = 2;
    }
}

void get_down
(char **map, sfVector2u *pos, sfVector2f *checkpoint, is_changed_t *check)
{
    int len = 0;

    for (len = 0; checkpoint[len].x != -1; len++);
    if (check->last_dir != 4 && check->is_changed == 0 &&
        map[pos->y + 1] != NULL && (map[pos->y + 1][pos->x] == '#' ||
        map[pos->y + 1][pos->x] == 'E')) {
        for (; map[pos->y + 1] != NULL && (map[pos->y + 1][pos->x] == '#' ||
            map[pos->y + 1][pos->x] == 'E');)
            pos->y++;
        checkpoint[len].x = (pos->x * 40) + ((40 - ENEMY_SIZE.x) / 2);
        checkpoint[len].y = (pos->y * 40) + ((40 - ENEMY_SIZE.y) / 2);
        checkpoint[len + 1] = create_vectorf(-1, -1);
        check->is_changed++;
        check->last_dir = 3;
    }
}

void get_up
(char **map, sfVector2u *pos, sfVector2f *checkpoint, is_changed_t *check)
{
    int len = 0;

    for (len = 0; checkpoint[len].x != -1; len++);
    if (check->last_dir != 3 && check->is_changed == 0 &&
        pos->y != 0 && (map[pos->y - 1][pos->x] == '#' ||
        map[pos->y - 1][pos->x] == 'E')) {
        for (; pos->y != 0 &&
            (map[pos->y - 1][pos->x] == '#' ||
            map[pos->y - 1][pos->x] == 'E');)
            pos->y--;
        checkpoint[len].x = (pos->x * 40) + ((40 - ENEMY_SIZE.x) / 2);
        checkpoint[len].y = (pos->y * 40) + ((40 - ENEMY_SIZE.y) / 2);
        checkpoint[len + 1] = create_vectorf(-1, -1);
        check->is_changed++;
        check->last_dir = 4;
    }
}

sfVector2f *get_checkpoint(char **map, int nb_checkpoint)
{
    sfVector2f *checkpoint = malloc(sizeof(sfVector2f) * nb_checkpoint);
    sfVector2u pos;
    is_changed_t check = {0, 0, 0};

    if (checkpoint == NULL)
        return NULL;
    checkpoint[0] = create_vectorf(-1, -1);
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0' && map[y][x] != '\n'; x++) {
            get_pos_start(map, x, y, &pos);
        }
    }
    for (;map[pos.y][pos.x] != 'E'; check.is_changed = 0) {
        get_right(map, &pos, checkpoint, &check);
        get_left(map, &pos, checkpoint, &check);
        get_down(map, &pos, checkpoint, &check);
        get_up(map, &pos, checkpoint, &check);
    }
    return checkpoint;
}

map_t *create_map(const char *path, game_t *game)
{
    map_t *map_struct = malloc(sizeof(map_t));
    char *buf = NULL;
    size_t size;
    ssize_t len = 0;
    FILE *file = fopen(path, "r");
    int i = 0;

    map_struct->map = malloc(sizeof(char *) * 20);
    for (i = 0; len >= 0; i++) {
        len = getline(&buf, &size, file);
        map_struct->map[i] = my_strdup(buf);
    }
    map_struct->map[i] = NULL;
    free(buf);
    fclose(file);
    map_struct->checkpoint = get_checkpoint
                            (map_struct->map, nb_checkpoint(map_struct->map));
    game->place =
        create_tower_place(map_struct->map, count_nb_place(map_struct->map));
    return map_struct;
}
