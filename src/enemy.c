/*
** EPITECH PROJECT, 2022
** enemy.c
** File description:
** enemy
*/

#include "my_defender.h"

void speed_to_checkpoint(enemy_t *enemy, sfVector2f *checkpoint, int i)
{
    if (checkpoint[i + 1].x != -1) {
        if (checkpoint[i].x > checkpoint[i + 1].x)
            enemy->speed = create_vectorf(-enemy->move_speed, 0);
        if (checkpoint[i].x < checkpoint[i + 1].x)
            enemy->speed = create_vectorf(enemy->move_speed, 0);
        if (checkpoint[i].y > checkpoint[i + 1].y)
            enemy->speed = create_vectorf(0, -enemy->move_speed);
        if (checkpoint[i].y < checkpoint[i + 1].y)
            enemy->speed = create_vectorf(0, enemy->move_speed);
    }
}

void update_speed_y
(enemy_t *enemy, sfVector2f *checkpoint, int i, int before_cp)
{
    if (enemy->speed.y > 0 && enemy->pos.y >= checkpoint[i].y &&
        enemy->pos.x == checkpoint[i].x && before_cp == enemy->checkpoint) {
        speed_to_checkpoint(enemy, checkpoint, i);
        enemy->pos = create_vectorf(checkpoint[i].x, checkpoint[i].y);
        enemy->checkpoint++;
    }
    if (enemy->speed.y < 0 && enemy->pos.y <= checkpoint[i].y &&
        enemy->pos.x == checkpoint[i].x && before_cp == enemy->checkpoint) {
        speed_to_checkpoint(enemy, checkpoint, i);
        enemy->pos = create_vectorf(checkpoint[i].x, checkpoint[i].y);
        enemy->checkpoint++;
    }
}

void update_speed(enemy_t *enemy, sfVector2f *checkpoint, int i)
{
    int before_cp = enemy->checkpoint;

    if (enemy->speed.x > 0 && enemy->pos.x >= checkpoint[i].x &&
        enemy->pos.y == checkpoint[i].y && before_cp == enemy->checkpoint) {
        speed_to_checkpoint(enemy, checkpoint, i);
        enemy->pos = create_vectorf(checkpoint[i].x, checkpoint[i].y);
        enemy->checkpoint++;
    }
    if (enemy->speed.x < 0 && enemy->pos.x <= checkpoint[i].x &&
        enemy->pos.y == checkpoint[i].y && before_cp == enemy->checkpoint) {
        speed_to_checkpoint(enemy, checkpoint, i);
        enemy->pos = create_vectorf(checkpoint[i].x, checkpoint[i].y);
        enemy->checkpoint++;
    }
    update_speed_y(enemy, checkpoint, i, before_cp);
}

void move_enemy(enemy_t *enemy, sfVector2f *checkpoint, sfClock *clock)
{
    for (int i = 0; checkpoint[i].x != -1; i++) {
        if (i == enemy->checkpoint)
            update_speed(enemy, checkpoint, i);
    }
    is_slow_enemy(enemy, clock);
    enemy->pos.x += enemy->speed.x * (get_time_sec(clock) - enemy->dtime);
    enemy->pos.y += enemy->speed.y * (get_time_sec(clock) - enemy->dtime);
    sfRectangleShape_setPosition
        (enemy->rect, (sfVector2f)
        {enemy->pos.x - enemy->replace, enemy->pos.y - enemy->replace});
    enemy->dtime = get_time_sec(clock);
}
