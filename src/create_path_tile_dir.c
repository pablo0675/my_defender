/*
** EPITECH PROJECT, 2022
** create_path_tile_dir.c
** File description:
** create_path_tile_dir
*/

#include "my_defender.h"

void update_pos_tile
(sfVector2u *pos, is_changed_t *check, int last_dir, sfVector2i move)
{
    pos->x += move.x;
    pos->y += move.y;
    check->last_dir = last_dir;
    check->id++;
    check->is_changed++;
}

void create_tile_right
(char **map, sfVector2u *pos, is_changed_t *check, path_t **path)
{
    path[check->id] = malloc(sizeof(path_t));
    path[check->id]->pos = create_vectorf(pos->x * TILE, pos->y * TILE);
    path[check->id]->sprite = sfSprite_create();
    if (check->last_dir == 1) {
        path[check->id]->rect = TILE_STRAIGHT;
        rotate_sprite(path[check->id]->sprite, 90);
    }
    if (check->last_dir == 3) {
        path[check->id]->rect = TILE_CORNER;
        rotate_sprite(path[check->id]->sprite, 0);
    }
    if (check->last_dir == 4) {
        path[check->id]->rect = TILE_CORNER;
        rotate_sprite(path[check->id]->sprite, 90);
    }
    update_pos_tile(pos, check, 1, create_vectori(1, 0));
}

void create_tile_left
(char **map, sfVector2u *pos, is_changed_t *check, path_t **path)
{
    path[check->id] = malloc(sizeof(path_t));
    path[check->id]->pos = create_vectorf(pos->x * TILE, pos->y * TILE);
    path[check->id]->sprite = sfSprite_create();
    if (check->last_dir == 2) {
        path[check->id]->rect = TILE_STRAIGHT;
        rotate_sprite(path[check->id]->sprite, 90);
    }
    if (check->last_dir == 3) {
        path[check->id]->rect = TILE_CORNER;
        rotate_sprite(path[check->id]->sprite, 270);
    }
    if (check->last_dir == 4) {
        path[check->id]->rect = TILE_CORNER;
        rotate_sprite(path[check->id]->sprite, 180);
    }
    update_pos_tile(pos, check, 2, create_vectori(-1, 0));
}

void create_tile_down
(char **map, sfVector2u *pos, is_changed_t *check, path_t **path)
{
    path[check->id] = malloc(sizeof(path_t));
    path[check->id]->pos = create_vectorf(pos->x * TILE, pos->y * TILE);
    path[check->id]->sprite = sfSprite_create();
    if (check->last_dir == 3) {
        path[check->id]->rect = TILE_STRAIGHT;
    }
    if (check->last_dir == 1) {
        path[check->id]->rect = TILE_CORNER;
        rotate_sprite(path[check->id]->sprite, 180);
    }
    if (check->last_dir == 2) {
        path[check->id]->rect = TILE_CORNER;
        rotate_sprite(path[check->id]->sprite, 90);
    }
    update_pos_tile(pos, check, 3, create_vectori(0, 1));
}

void create_tile_up
(char **map, sfVector2u *pos, is_changed_t *check, path_t **path)
{
    path[check->id] = malloc(sizeof(path_t));
    path[check->id]->pos = create_vectorf(pos->x * TILE, pos->y * TILE);
    path[check->id]->sprite = sfSprite_create();
    if (check->last_dir == 4) {
        path[check->id]->rect = TILE_STRAIGHT;
    }
    if (check->last_dir == 1) {
        path[check->id]->rect = TILE_CORNER;
        rotate_sprite(path[check->id]->sprite, 270);
    }
    if (check->last_dir == 2) {
        path[check->id]->rect = TILE_CORNER;
    }
    update_pos_tile(pos, check, 4, create_vectori(0, -1));
}
