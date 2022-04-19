/*
** EPITECH PROJECT, 2022
** projectiles.c
** File description:
** projectiles
*/

#include "my_defender.h"

proj_t **create_projectiles(int nb, int damage, float slow, sfColor color)
{
    proj_t **proj = malloc(sizeof(proj_t *) * (nb + 1));

    for (int i = 0; i < nb; i++) {
        proj[i] = malloc(sizeof(proj_t));
        proj[i]->pos = create_vectorf(0, 0);
        proj[i]->hitbox = create_rect(0, 0, 5, 5);
        proj[i]->target = -1;
        proj[i]->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(proj[i]->rect, create_vectorf(5, 5));
        sfRectangleShape_setFillColor(proj[i]->rect, color);
        sfRectangleShape_setPosition(proj[i]->rect,
            create_vectorf(proj[i]->pos.x - 1, proj[i]->pos.y - 1));
        proj[i]->move = create_vectorf(0, 0);
        proj[i]->speed = 700.0;
        proj[i]->dtime = 0.0;
        proj[i]->damage = damage;
        proj[i]->slow = slow;
    }
    proj[nb] = NULL;
    return proj;
}

void shoot_proj(tower_t *tower, enemy_t *enemy, int target_nb, sfClock *clock)
{
    int i = 0;

    for (i = 0; tower->proj[i] != NULL && tower->proj[i]->target != -1; i++);
    if (tower->proj[i] == NULL)
        return;
    tower->proj[i]->pos = create_vectorf(tower->circle.x, tower->circle.y);
    sfRectangleShape_setPosition(tower->proj[i]->rect,
        create_vectorf(tower->circle.x, tower->circle.y));
    tower->proj[i]->target = target_nb;
    tower->proj[i]->dtime = get_time_sec(clock);
}

void update_proj(enemy_t **enemys, proj_t *proj, game_t *game)
{
    sfVector2f dist;
    sfVector2f norm;

    dist.x = (enemys[proj->target]->pos.x + (ENEMY_SIZE.x / 2)) - proj->pos.x;
    dist.y = (enemys[proj->target]->pos.y + (ENEMY_SIZE.x / 2)) - proj->pos.y;
    norm = normalize_vec(dist);
    proj->pos.x +=
        norm.x * proj->speed * (get_time_sec(game->clock) - proj->dtime);
    proj->pos.y +=
        norm.y * proj->speed * (get_time_sec(game->clock) - proj->dtime);
    proj->dtime = get_time_sec(game->clock);
    sfRectangleShape_setPosition(proj->rect, proj->pos);
    if (collide_rects(proj->pos, proj->hitbox, enemys[proj->target]->pos,
        enemys[proj->target]->hitbox) == sfTrue) {
        damage_enemy(enemys, proj, game);
    }
}

void update_all_proj(game_t *game, tower_t *tower)
{
    for (int j = 0; tower->proj[j] != NULL; j++) {
        if (tower->proj[j]->target != -1) {
            update_proj
                (game->enemys, tower->proj[j], game);
        }
    }
}

void free_projectiles(proj_t **proj)
{
    for (int i = 0; proj[i] != NULL; i++) {
        sfRectangleShape_destroy(proj[i]->rect);
        free(proj[i]);
    }
    free(proj);
}
