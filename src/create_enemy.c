/*
** EPITECH PROJECT, 2022
** create_enemy.c
** File description:
** create_enemy
*/

#include "my_defender.h"

void create_sprite_enemy(enemy_t *enemy, sfVector2f pos)
{
    enemy->max_speed = ENEMY_SPEED;
    enemy->texture_rect = LEANDRE;
    enemy->hp_bar = create_hp_bar
            (create_vectorf(pos.x - 5, pos.y - 10), create_vectorf(42, 5));
    sfRectangleShape_setPosition
        (enemy->rect, (sfVector2f)
        {enemy->pos.x - enemy->replace, enemy->pos.y - enemy->replace});
    sfRectangleShape_setTexture(enemy->rect, enemy->spritesheet, 0);
    sfRectangleShape_setSize(enemy->rect, (sfVector2f){40, 40});
    sfRectangleShape_setTextureRect(enemy->rect, enemy->texture_rect);
}

enemy_t *create_enemy(sfVector2f pos, sfTexture *spritesheet)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    sfVector2f size = ENEMY_SIZE;

    enemy->pos = pos;
    enemy->dtime = 0.0;
    enemy->rect = sfRectangleShape_create();
    enemy->speed = create_vectorf(ENEMY_SPEED, 0);
    enemy->move = move_enemy;
    enemy->checkpoint = 0;
    enemy->move_speed = ENEMY_SPEED;
    enemy->hitbox = create_rect(0, 0, size.x, size.y);
    enemy->hp = ENEMY_HP;
    enemy->max_hp = ENEMY_HP;
    enemy->value = 5;
    enemy->damage = 1;
    enemy->last_time = 0.0;
    enemy->replace = 5;
    enemy->spritesheet = spritesheet;
    create_sprite_enemy(enemy, pos);
    return enemy;
}

void create_sprite_big_enemy(enemy_t *enemy, sfVector2f pos)
{
    enemy->max_speed = BIG_ENEMY_SPEED;
    enemy->texture_rect = LEANDRE;
    enemy->hp_bar = create_hp_bar
            (create_vectorf(pos.x - 5, pos.y - 10), create_vectorf(42, 5));
    sfRectangleShape_setPosition
        (enemy->rect, (sfVector2f)
        {enemy->pos.x - enemy->replace, enemy->pos.y - enemy->replace});
    sfRectangleShape_setTexture(enemy->rect, enemy->spritesheet, 0);
    sfRectangleShape_setSize(enemy->rect, (sfVector2f){50, 50});
    sfRectangleShape_setTextureRect(enemy->rect, enemy->texture_rect);
}

enemy_t *create_big_enemy(sfVector2f pos, sfTexture *spritesheet)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    sfVector2f size = ENEMY_SIZE;

    enemy->pos = pos;
    enemy->dtime = 0.0;
    enemy->rect = sfRectangleShape_create();
    enemy->speed = create_vectorf(ENEMY_SPEED, 0);
    enemy->move = move_enemy;
    enemy->checkpoint = 0;
    enemy->move_speed = BIG_ENEMY_SPEED;
    enemy->hitbox = create_rect(0, 0, size.x, size.y);
    enemy->hp = BIG_ENEMY_HP;
    enemy->max_hp = BIG_ENEMY_HP;
    enemy->value = 5;
    enemy->damage = 1;
    enemy->last_time = 0.0;
    enemy->replace = 7;
    enemy->spritesheet = spritesheet;
    create_sprite_big_enemy(enemy, pos);
    return enemy;
}
