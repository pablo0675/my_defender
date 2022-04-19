/*
** EPITECH PROJECT, 2022
** enemy_slow.c
** File description:
** enemy_slow
*/

#include "my_defender.h"
#include <math.h>

void decrease_speed(enemy_t *enemy)
{
    if (enemy->speed.x != 0) {
        if (enemy->speed.x > 0 && enemy->speed.x > enemy->slow.slow)
            enemy->speed.x -= enemy->slow.slow;
        if (enemy->speed.x < 0 && enemy->speed.x < -enemy->slow.slow)
            enemy->speed.x += enemy->slow.slow;
        enemy->move_speed = abs(enemy->speed.x);
    }
    if (enemy->speed.y != 0) {
        if (enemy->speed.y > 0 && enemy->speed.y > enemy->slow.slow)
            enemy->speed.y -= enemy->slow.slow;
        if (enemy->speed.y < 0 && enemy->speed.y < -enemy->slow.slow)
            enemy->speed.y += enemy->slow.slow;
        enemy->move_speed = abs(enemy->speed.y);
    }
}

void reset_speed(enemy_t *enemy)
{
    if (enemy->speed.x != 0) {
        if (enemy->speed.x > 0)
            enemy->speed.x = enemy->max_speed;
        if (enemy->speed.y < 0)
            enemy->speed.x = -enemy->max_speed;
    }
    if (enemy->speed.y != 0) {
        if (enemy->speed.y > 0)
            enemy->speed.y = enemy->max_speed;
        if (enemy->speed.y < 0)
            enemy->speed.y = -enemy->max_speed;
    }
}

void is_slow_enemy(enemy_t *enemy, sfClock *clock)
{
    if (enemy->slow.is_slow == sfTrue) {
        if (get_time_sec(clock) - enemy->slow.duration > 1) {
            reset_speed(enemy);
            enemy->slow.is_slow = sfFalse;
            enemy->move_speed = ENEMY_SPEED;
        }
    }
}
