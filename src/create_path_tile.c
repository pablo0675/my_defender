/*
** EPITECH PROJECT, 2022
** create_path_tile.c
** File description:
** create_path_tile
*/

#include "my_defender.h"

int start_angle
(char **map, sfVector2u *pos, path_t **path, is_changed_t *check)
{
    if (map[pos->y][pos->x + 1] == '#') {
        pos->x++;
        check->last_dir = 1;
        return 90;
    }
    if (pos->x != 0 && map[pos->y][pos->x - 1] == '#') {
        pos->x--;
        check->last_dir = 2;
        return 270;
    }
    if (pos->y != 0 && map[pos->y - 1][pos->x] == '#') {
        pos->y--;
        check->last_dir = 4;
        return 180;
    }
    if (map[pos->y + 1] != NULL && map[pos->y + 1][pos->x] == '#') {
        pos->y++;
        check->last_dir = 3;
    }
    return 0;
}

void create_start_tile
(char **map, sfVector2u *pos, path_t **path, is_changed_t *check)
{
    sfSprite *sprite = sfSprite_create();

    path[0] = malloc(sizeof(path_t));
    path[0]->pos = create_vectorf(pos->x * TILE, pos->y * TILE);
    rotate_sprite(sprite, start_angle(map, pos, path, check));
    path[0]->sprite = sprite;
    path[0]->rect = TILE_START;
}

void create_end_tile
(char **map, sfVector2u *pos, path_t **path, is_changed_t *check)
{
    sfSprite *sprite = sfSprite_create();

    path[check->id] = malloc(sizeof(path_t));
    path[check->id]->pos = create_vectorf(pos->x * TILE, pos->y * TILE);
    if (check->last_dir == 1)
        rotate_sprite(sprite, 270);
    if (check->last_dir == 2)
        rotate_sprite(sprite, 90);
    if (check->last_dir == 4)
        rotate_sprite(sprite, 180);
    path[check->id]->sprite = sprite;
    path[check->id]->rect = TILE_START;
    check->id++;
}

void loop_path_tile
(char **map, sfVector2u *pos, is_changed_t *check, path_t **path)
{
    for (;map[pos->y][pos->x] != 'E'; check->is_changed = 0) {
        if (check->last_dir != 2 && (map[pos->y][pos->x + 1] == '#' ||
            map[pos->y][pos->x + 1] == 'E'))
            create_tile_right(map, pos, check, path);
        if (check->is_changed == 0 && check->last_dir != 1 && pos->x != 0 &&
            (map[pos->y][pos->x - 1] == '#' || map[pos->y][pos->x - 1] == 'E'))
            create_tile_left(map, pos, check, path);
        if (check->is_changed == 0 && check->last_dir != 4 &&
            map[pos->y + 1] != NULL && (map[pos->y + 1][pos->x] == '#' ||
            map[pos->y + 1][pos->x] == 'E'))
            create_tile_down(map, pos, check, path);
        if (check->is_changed == 0 && check->last_dir != 3 && pos->y != 0 &&
            (map[pos->y - 1][pos->x] == '#' || map[pos->y - 1][pos->x] == 'E'))
            create_tile_up(map, pos, check, path);
    }
}

path_t **create_path_tile(char **map, sfTexture *spritesheet)
{
    path_t **path = malloc(sizeof(path_t *) * (nb_path_tile(map) + 1));
    sfVector2u pos;
    is_changed_t check = {0, 0, 1};

    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\n' && map[y][x] != '\0'; x++)
            get_pos_start(map, x, y, &pos);
    }
    create_start_tile(map, &pos, path, &check);
    loop_path_tile(map, &pos, &check, path);
    create_end_tile(map, &pos, path, &check);
    path[check.id] = NULL;
    for (int i = 0; path[i] != NULL; i++)
        path[i]->texture = spritesheet;
    return path;
}
