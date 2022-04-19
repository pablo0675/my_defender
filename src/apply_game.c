/*
** EPITECH PROJECT, 2022
** apply_game.c
** File description:
** apply_game
*/

#include "my_defender.h"
#include "my.h"

void apply_enemys(sfRenderWindow *window, enemy_t **enemys)
{
    for (int i = 0; enemys[i] != NULL; i++) {
        if (enemys[i]->hp > 0)
            sfRenderWindow_drawRectangleShape(window, enemys[i]->rect, NULL);
        if (enemys[i]->hp < enemys[i]->max_hp && enemys[i]->hp > 0) {
            sfRenderWindow_drawRectangleShape
                (window, enemys[i]->hp_bar->black, NULL);
            sfRenderWindow_drawRectangleShape
                (window, enemys[i]->hp_bar->red, NULL);
        }
    }
}

void apply_towers(sfRenderWindow *window, twr_place_t **place)
{
    for (int i = 0; place[i] != NULL; i++) {
        if (place[i]->is_tower == sfTrue) {
            sfRenderWindow_drawCircleShape
                (window, place[i]->tower->range, NULL);
            sfRenderWindow_drawRectangleShape
                (window, place[i]->tower->rect, NULL);
        }
    }
}

void apply_proj(sfRenderWindow *window, tower_t *tower)
{
    for (int j = 0; tower->proj[j] != NULL; j++) {
        if (tower->proj[j]->target != -1) {
            sfRenderWindow_drawRectangleShape
                (window, tower->proj[j]->rect, NULL);
        }
    }
}

void apply_tower_places(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; game->place[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape
                (window, game->place[i]->rect, NULL);
    }
    draw_inventory(game, window);
    if (game->drag_drop->exist == sfTrue) {
        sfSprite_setTexture(game->drag_drop->sprite,
                            game->drag_drop->texture, 0);
        sfRenderWindow_drawSprite(window, game->drag_drop->sprite, NULL);
    }
}

void apply_game(sfRenderWindow *window, game_t *game)
{
    sfSprite_setTexture(game->bg->sprite, game->bg->texture, 0);
    sfSprite_setTextureRect(game->bg->sprite, game->bg->rect);
    sfSprite_setPosition(game->bg->sprite, game->bg->pos);
    sfRenderWindow_drawSprite(window, game->bg->sprite, NULL);
    apply_path(window, game);
    apply_tower_places(window, game);
    apply_towers(window, game->place);
    for (int i = 0; game->place[i] != NULL; i++) {
        if (game->place[i]->is_tower == sfTrue)
            apply_proj(window, game->place[i]->tower);
    }
    apply_enemys(window, game->enemys);
    sfRenderWindow_drawRectangleShape
        (window, game->base_hp_bar->black, NULL);
    sfRenderWindow_drawRectangleShape
        (window, game->base_hp_bar->red, NULL);
    sfRenderWindow_display(window);
}
