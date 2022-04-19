/*
** EPITECH PROJECT, 2022
** defender
** File description:
** call create tower
*/

/* this function will call the tower create function*/

#include "../include/my_defender.h"
#include "../include/my.h"
#include <stdio.h>

int check_pos(twr_place_t *place, sfVector2i mouse)
{
    int x = place->hitbox.width;
    int y = place->hitbox.height;

    if ((mouse.x <= place->pos.x + x && mouse.x >= place->pos.x) &&
        (mouse.y <= place->pos.y + y && mouse.y >= place->pos.y)) {
        return 84;
    }
    return 0;
}

twr_place_t *create_green_tower(twr_place_t *place, int i)
{
    place->tower = malloc(sizeof(tower_t));

    place->tower->circle = (circle_t){place->pos.x + 40,
                                      place->pos.y + 40, 350};
    place->tower->pos = create_vectorf(place->tower->circle.x - 40,
                                       place->tower->circle.y - 40);
    set_range_tower(place->tower, place->tower->circle);
    place->is_tower = sfTrue;
    place->tower->texture = sfTexture_createFromFile(t2, NULL);
    place->tower->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(place->tower->rect, place->tower->pos);
    sfRectangleShape_setSize(place->tower->rect,
                             create_vectorf(TILE * 2, TILE * 2));
    sfRectangleShape_setTexture(place->tower->rect, place->tower->texture, 0);
    place->tower = create_tower(place->tower, 0.7, 15, 10);
    place->tower->proj = create_projectiles(10, 15, 10, sfGreen);
    return place;
}

twr_place_t *create_blue_tower(twr_place_t *place, int i)
{
    place->tower = malloc(sizeof(tower_t));

    place->tower->circle = (circle_t){place->pos.x + 40,
                                      place->pos.y + 40, 300};
    place->tower->pos = create_vectorf(place->tower->circle.x - 40,
                                       place->tower->circle.y - 40);
    set_range_tower(place->tower, place->tower->circle);
    place->is_tower = sfTrue;
    place->tower->texture = sfTexture_createFromFile(t3, NULL);
    place->tower->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(place->tower->rect, place->tower->pos);
    sfRectangleShape_setSize(place->tower->rect,
                             create_vectorf(TILE * 2, TILE * 2));
    sfRectangleShape_setTexture(place->tower->rect, place->tower->texture, 0);
    place->tower = create_tower(place->tower, 1, 5, 40);
    place->tower->proj = create_projectiles(10, 10, 40, sfBlue);
    return place;
}

int tower_check_pos_two(int pressed, game_t *game,
                        int i, sfVector2i mouse)
{
    if (pressed == 2 && check_pos(game->place[i], mouse) == 84) {
        create_blue_tower(game->place[i], i);
        game->drag_drop->exist = sfFalse;
        sfTexture_destroy(game->drag_drop->texture);
        return 84;
    }
    if (pressed == 3 && check_pos(game->place[i], mouse) == 84) {
        create_red_tower(game->place[i], i);
        game->drag_drop->exist = sfFalse;
        sfTexture_destroy(game->drag_drop->texture);
        return 84;
    }
    return 0;
}


int tower_check_pos(int pressed, game_t *game,
                    int i, sfVector2i mouse)
{
    if (pressed == 0 && check_pos(game->place[i], mouse) == 84) {
        create_yellow_tower(game->place[i], i);
        game->drag_drop->exist = sfFalse;
        sfTexture_destroy(game->drag_drop->texture);
        return 84;
    }
    if (pressed == 1 && check_pos(game->place[i], mouse) == 84) {
        create_green_tower(game->place[i], i);
        game->drag_drop->exist = sfFalse;
        sfTexture_destroy(game->drag_drop->texture);
        return 84;
    }
    if (tower_check_pos_two(pressed, game, i, mouse) == 84)
        return 84;
    return 0;
}
