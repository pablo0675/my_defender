/*
** EPITECH PROJECT, 2022
** pause_update_dtime.c
** File description:
** pause_update_dtime
*/

#include "my_defender.h"

void update_dtime_tower(twr_place_t *place, float *last_time, float new)
{
    if (place->is_tower == sfTrue) {
        for (int j = 0; place->tower->proj[j] != NULL; j++)
            place->tower->proj[j]->dtime = new;
        place->tower->last_shot += new - *last_time;
    }
}

void update_dtime(game_t *game, float *last_time)
{
    float new = get_time_sec(game->clock);

    for (int i = 0; game->enemys[i] != NULL; i++) {
        game->enemys[i]->dtime = new;
        if (game->enemys[i]->slow.is_slow == sfTrue)
            game->enemys[i]->slow.duration += new - *last_time;
    }
    for (int i = 0; game->place[i] != NULL; i++) {
        update_dtime_tower(game->place[i], last_time, new);
    }
    *last_time = new;
}
