/*
** EPITECH PROJECT, 2022
** defender
** File description:
** yellow_tower
*/

#include "../include/my_defender.h"

twr_place_t *create_yellow_tower(twr_place_t *place, int i)
{
    place->tower = malloc(sizeof(tower_t));

    place->tower->circle = (circle_t){place->pos.x + 40,
                                      place->pos.y + 40, 200};
    place->tower->pos = create_vectorf(place->tower->circle.x - 40,
                                       place->tower->circle.y - 40);
    set_range_tower(place->tower, place->tower->circle);
    place->is_tower = sfTrue;
    place->tower->texture = sfTexture_createFromFile(t1, NULL);
    place->tower->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(place->tower->rect, place->tower->pos);
    sfRectangleShape_setSize(place->tower->rect,
                             create_vectorf(TILE * 2, TILE * 2));
    sfRectangleShape_setTexture(place->tower->rect, place->tower->texture, 0);
    place->tower = create_tower(place->tower, 0.01, 2, 1);
    place->tower->proj = create_projectiles(10, 1, 1, sfYellow);
    return place;
}