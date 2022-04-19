/*
** EPITECH PROJECT, 2022
** update_game.c
** File description:
** update_game
*/

#include "my_defender.h"

void update_sprites(game_t *game)
{
    for (int i = 0; game->enemys[i] != NULL; i++) {
        if (get_time_sec(game->clock) - game->enemys[i]->last_time > 0.3) {
            move_rect(&game->enemys[i]->texture_rect, 545, 1090);
            sfRectangleShape_setTextureRect
                (game->enemys[i]->rect, game->enemys[i]->texture_rect);
            game->enemys[i]->last_time = get_time_sec(game->clock);
        }
    }
}

void is_win(game_t *game)
{
    for (int i = 0; game->enemys[i] != NULL; i++) {
        if (game->enemys[i]->hp > 0)
            return;
    }
    game->state = win;
}

void update_game(game_t *game)
{
    for (int i = 0; game->place[i] != NULL; i++) {
        if (game->place[i]->is_tower == sfTrue) {
            game->place[i]->tower->attack
                (game->place[i]->tower, game->enemys,
                game->clock, game->map->checkpoint);
            update_all_proj(game, game->place[i]->tower);
        }
    }
    for (int i = 0; game->enemys[i] != NULL; i++) {
        game->enemys[i]->move(game->enemys[i], game->map->checkpoint,
                                game->clock);
        update_pos_hp_bar(game->enemys[i]);
        update_hp_bar(game->enemys[i]->hp_bar,
                    game->enemys[i]->hp, game->enemys[i]->max_hp);
    }
    damage_base(game);
    if (game->base_hp <= 0)
        game->state = game_over;
    update_sprites(game);
    update_hp_bar(game->base_hp_bar, game->base_hp, 3);
}
