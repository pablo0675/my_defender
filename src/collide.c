/*
** EPITECH PROJECT, 2022
** collide.c
** File description:
** collide
*/

#include "my_defender.h"
#include <math.h>
#include <stdlib.h>

sfBool is_coll_enemy_circ(enemy_t *enemy, circle_t circle)
{
    float dist = 0;
    float check_x = circle.x;
    float check_y = circle.y;
    float dist_x = 0;
    float dist_y = 0;

    if (circle.x < enemy->pos.x)
        check_x = enemy->pos.x;
    else if (circle.x > enemy->pos.x + enemy->hitbox.width)
        check_x = enemy->pos.x + enemy->hitbox.width;
    if (circle.y < enemy->pos.y)
        check_y = enemy->pos.y;
    else if (circle.y > enemy->pos.y + enemy->hitbox.height)
        check_y = enemy->pos.y + enemy->hitbox.height;
    dist_x = circle.x - check_x;
    dist_y = circle.y - check_y;
    dist = sqrtf((dist_x * dist_x) + (dist_y * dist_y));
    if (dist <= circle.radius)
        return sfTrue;
    return sfFalse;
}

sfBool is_coll_rect_circ(sfIntRect rect, circle_t circle)
{
    float dist = 0;
    float check_x = 0;
    float check_y = 0;
    float dist_x = 0;
    float dist_y = 0;

    if (circle.x < rect.left)
        check_x = rect.left;
    else if (circle.x > rect.left + rect.width)
        check_x = rect.left + rect.width;
    if (circle.y < rect.top)
        check_y = rect.top;
    else if (circle.y > rect.top + rect.height)
        check_y = rect.top + rect.height;
    dist_x = circle.x - check_x;
    dist_y = circle.y - check_y;
    dist = sqrtf(powf(dist_x, 2) + powf(dist_y, 2));
    if (dist <= circle.radius)
        return sfTrue;
    return sfFalse;
}

sfBool collide_rects
(sfVector2f pos1, sfIntRect rect1, sfVector2f pos2, sfIntRect rect2)
{
    if (pos1.x < pos2.x + rect2.width && pos1.x + rect1.width > pos2.x &&
        pos1.y < pos2.y + rect2.height && pos1.y + rect1.height > pos2.y)
        return sfTrue;
    else
        return sfFalse;
}
