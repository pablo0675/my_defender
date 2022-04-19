/*
** EPITECH PROJECT, 2022
** tower_target.c
** File description:
** tower_target
*/

#include "my_defender.h"
#include <stdlib.h>

int get_max_checkpoint(tower_t *tower, enemy_t **enemys)
{
    int max = -1;

    for (int i = 0; enemys[i] != NULL; i++) {
        if (enemys[i]->hp > 0 &&
            is_coll_enemy_circ(enemys[i], tower->circle) == sfTrue &&
            enemys[i]->checkpoint > max)
            max = enemys[i]->checkpoint;
    }
    return max;
}

float dist_to_next(enemy_t *enemy, sfVector2f checkpoint)
{
    float dist = 0;

    dist += abs(checkpoint.x - enemy->pos.x);
    dist += abs(checkpoint.y - enemy->pos.y);
    return dist;
}

int id_further_enemy(tower_t *tower, enemy_t **enemys, sfVector2f *checkpoint)
{
    int max_cp = get_max_checkpoint(tower, enemys);
    int id = -1;

    if (max_cp == -1)
        return id;
    for (int i = 0; enemys[i] != NULL; i++) {
        if (enemys[i]->hp > 0 &&
            enemys[i]->checkpoint == max_cp &&
            is_coll_enemy_circ(enemys[i], tower->circle) == sfTrue &&
            id == -1)
            id = i;
        else if (enemys[i]->hp > 0 &&
            enemys[i]->checkpoint == max_cp &&
            is_coll_enemy_circ(enemys[i], tower->circle) == sfTrue &&
            dist_to_next(enemys[i], checkpoint[max_cp]) <
            dist_to_next(enemys[id], checkpoint[max_cp]))
            id = i;
    }
    return id;
}
