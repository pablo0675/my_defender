/*
** EPITECH PROJECT, 2022
** tower.c
** File description:
** tower
*/

#include "my_defender.h"

void tower_attack
(tower_t *tower, enemy_t **enemys, sfClock *clock, sfVector2f *checkpoint)
{
    int id = 0;

    if (get_time_sec(clock) - tower->last_shot > tower->cd &&
    is_coll_enemy_circ(enemys[tower->last_target], tower->circle) == sfTrue &&
    enemys[tower->last_target]->hp > 0) {
        shoot_proj
            (tower, enemys[tower->last_target], tower->last_target, clock);
        tower->last_shot = get_time_sec(clock);
        return;
    }
    id = id_further_enemy(tower, enemys, checkpoint);
    if (id == -1) return;
    if (enemys[id]->hp > 0 &&
        get_time_sec(clock) - tower->last_shot > tower->cd &&
        is_coll_enemy_circ(enemys[id], tower->circle) == sfTrue) {
        tower->last_target = id;
        shoot_proj(tower, enemys[id], id, clock);
        tower->last_shot = get_time_sec(clock);
    }
}

void set_range_tower(tower_t *tower, circle_t circle)
{
    tower->range = sfCircleShape_create();
    sfCircleShape_setPosition(tower->range,
        create_vectorf(circle.x - circle.radius, circle.y - circle.radius));
    sfCircleShape_setRadius(tower->range, circle.radius);
    sfCircleShape_setOutlineColor(tower->range,
                                create_color(200, 200, 200, 80));
    sfCircleShape_setOutlineThickness(tower->range, 3);
    sfCircleShape_setFillColor(tower->range, create_color(0, 0, 100, 10));
}

tower_t *create_tower(tower_t *tower, float cd, int damage, float slow)
{
    tower->last_shot = 0;
    tower->damage = damage;
    tower->cd = cd;
    tower->last_target = 0;
    tower->attack = tower_attack;
    tower->slow = slow;
    return tower;
}

twr_place_t *create_red_tower(twr_place_t *place, int i)
{
    place->tower = malloc(sizeof(tower_t));

    place->tower->circle = (circle_t){place->pos.x + 40,
                                      place->pos.y + 40, 400};
    place->tower->pos = create_vectorf(place->tower->circle.x - 40,
                                       place->tower->circle.y - 40);
    set_range_tower(place->tower, place->tower->circle);
    place->is_tower = sfTrue;
    place->tower->texture = sfTexture_createFromFile(t4, NULL);
    place->tower->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(place->tower->rect, place->tower->pos);
    sfRectangleShape_setSize(place->tower->rect,
                             create_vectorf(TILE * 2, TILE * 2));
    sfRectangleShape_setTexture(place->tower->rect, place->tower->texture, 0);
    place->tower = create_tower(place->tower, 3, 40, 0);
    place->tower->proj = create_projectiles(10, 40, 0, sfRed);
    return place;
}

void free_tower(tower_t *tower)
{
    sfRectangleShape_destroy(tower->rect);
    sfCircleShape_destroy(tower->range);
    free_projectiles(tower->proj);
    free(tower);
}
