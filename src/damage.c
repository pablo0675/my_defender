/*
** EPITECH PROJECT, 2022
** damage_enemy.c
** File description:
** damage_enemy
*/

#include "my_defender.h"

void damage_enemy(enemy_t **enemys, proj_t *proj, game_t *game)
{
    int tmp = enemys[proj->target]->hp;

    enemys[proj->target]->hp -= proj->damage;
    if (proj->slow > 0) {
        enemys[proj->target]->slow.duration = get_time_sec(game->clock);
        enemys[proj->target]->slow.is_slow = sfTrue;
        enemys[proj->target]->slow.slow = proj->slow;
        decrease_speed(enemys[proj->target]);
    }
    if (enemys[proj->target]->hp <= 0 && tmp > 0) {
        game->money += enemys[proj->target]->value;
    }
    proj->target = -1;
}

void damage_base(game_t *game)
{
    int nb = 0;

    for (nb = 0; game->map->checkpoint[nb].x != -1; nb++);
    for (int i = 0; game->enemys[i] != NULL; i++) {
        if (game->enemys[i]->hp > 0 && game->enemys[i]->checkpoint == nb) {
            sfSound_stop(game->sound->sound);
            sfSound_play(game->sound->sound);
            game->base_hp -= game->enemys[i]->damage;
            game->enemys[i]->hp = 0;
        }
    }
}
