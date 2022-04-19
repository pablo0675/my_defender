/*
** EPITECH PROJECT, 2022
** create_tower_place.c
** File description:
** create_tower_place.c
*/

#include "../include/my_defender.h"

twr_place_t *create_place(sfVector2f pos)
{
    twr_place_t *place = malloc(sizeof(twr_place_t));

    place->pos = pos;
    place->hitbox = create_rect(0, 0, TILE * 2, TILE * 2);
    place->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(place->rect, place->pos);
    sfRectangleShape_setSize(place->rect, create_vectorf(TILE * 2, TILE * 2));
    sfRectangleShape_setFillColor(place->rect, create_color(40, 120, 20, 150));
    place->is_tower = sfFalse;
    place->tower = NULL;
    return place;
}

void add_place(twr_place_t **place, int *id, sfVector2i pos, char **map)
{
    if (map[pos.y][pos.x] == 'T') {
        place[*id] = create_place(create_vectorf(pos.x * TILE, pos.y * TILE));
        *id = *id + 1;
    }
}

twr_place_t **create_tower_place(char **map, int nb_place)
{
    twr_place_t **place = malloc(sizeof(twr_place_t *) * (nb_place + 1));
    int id = 0;

    place[0] = NULL;
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            add_place(place, &id, create_vectori(x, y), map);
        }
    }
    place[id] = NULL;
    return place;
}

void free_places(twr_place_t **place)
{
    for (int i = 0; place[i] != NULL; i++) {
        if (place[i]->is_tower == sfTrue)
            free_tower(place[i]->tower);
        sfRectangleShape_destroy(place[i]->rect);
        free(place[i]);
    }
    free(place);
}
