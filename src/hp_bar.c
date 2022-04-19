/*
** EPITECH PROJECT, 2022
** hp_bar.c
** File description:
** hp_bar
*/

#include "my_defender.h"

hp_bar_t *create_hp_bar(sfVector2f pos, sfVector2f size)
{
    hp_bar_t *hp_bar = malloc(sizeof(hp_bar_t));

    hp_bar->pos = pos;
    hp_bar->black = sfRectangleShape_create();
    sfRectangleShape_setPosition(hp_bar->black, hp_bar->pos);
    sfRectangleShape_setSize(hp_bar->black, size);
    sfRectangleShape_setFillColor(hp_bar->black, create_color(0, 0, 0, 100));
    hp_bar->red = sfRectangleShape_create();
    sfRectangleShape_setPosition(hp_bar->red, hp_bar->pos);
    sfRectangleShape_setSize(hp_bar->red, size);
    sfRectangleShape_setFillColor(hp_bar->red, create_color(225, 5, 0, 255));
    return hp_bar;
}

void update_hp_bar(hp_bar_t *hp_bar, int current, int max)
{
    sfVector2f size_max = sfRectangleShape_getSize(hp_bar->black);
    int percent = (100 * current) / max;
    float new_size = (percent * size_max.x) / 100;

    sfRectangleShape_setSize
        (hp_bar->red, create_vectorf(new_size, size_max.y));
}

void update_pos_hp_bar(enemy_t *enemy)
{
    sfRectangleShape_setPosition
        (enemy->hp_bar->black,
        create_vectorf(enemy->pos.x - 5, enemy->pos.y - 10));
    sfRectangleShape_setPosition
        (enemy->hp_bar->red,
        create_vectorf(enemy->pos.x - 5, enemy->pos.y - 10));
}

void free_hp_bar(hp_bar_t *hp_bar)
{
    sfRectangleShape_destroy(hp_bar->black);
    sfRectangleShape_destroy(hp_bar->red);
    free(hp_bar);
}
