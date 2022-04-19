/*
** EPITECH PROJECT, 2022
** apply_path.c
** File description:
** apply_path
*/

#include "my_defender.h"

void apply_path(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; game->bg->path[i] != NULL; i++) {
        sfSprite_setTexture
            (game->bg->path[i]->sprite, game->bg->path[i]->texture, 0);
        sfSprite_setTextureRect
            (game->bg->path[i]->sprite, game->bg->path[i]->rect);
        sfSprite_setPosition
            (game->bg->path[i]->sprite, game->bg->path[i]->pos);
        sfRenderWindow_drawSprite(window, game->bg->path[i]->sprite, NULL);
    }
}
