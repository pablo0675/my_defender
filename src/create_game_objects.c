/*
** EPITECH PROJECT, 2022
** create_game_objects.c
** File description:
** create_game_objects
*/

#include "my_defender.h"

int create_enemys_other_waves
(enemy_t **enemys, sfVector2f *checkpoint, sfTexture *spritesheet, int posx)
{
    int i = 15;

    posx -= 1500;
    for (; i < 60; i++) {
        enemys[i] = create_enemy
            (create_vectorf(posx, checkpoint[0].y), spritesheet);
        posx -= 55;
        i++;
        enemys[i] = create_enemy
            (create_vectorf(posx, checkpoint[0].y), spritesheet);
        posx -= 55;
        i++;
        enemys[i] = create_big_enemy
            (create_vectorf(posx, checkpoint[0].y), spritesheet);
        posx -= 55;
    }
    return i;
}

enemy_t **create_enemys(sfVector2f *checkpoint, sfTexture *spritesheet)
{
    enemy_t **enemys = malloc(sizeof(enemy_t *) * 111);
    int i = 0;
    int posx = 0;

    if (enemys == NULL)
        return NULL;
    for (i = 0; i < 15; i++) {
        enemys[i] = create_enemy
            (create_vectorf(posx, checkpoint[0].y), spritesheet);
        posx -= 60;
    }
    i = create_enemys_other_waves(enemys, checkpoint, spritesheet, posx);
    posx -= 2500;
    for (; i < 110; i++) {
        enemys[i] = create_enemy
            (create_vectorf(posx, checkpoint[0].y), spritesheet);
        posx -= 45;
    }
    enemys[i] = NULL;
    return enemys;
}

bg_t *create_game_bg(char **map, sfTexture *spritesheet)
{
    bg_t *bg = malloc(sizeof(bg_t));

    if (bg == NULL)
        return NULL;
    bg->pos = create_vectorf(0, 0);
    bg->texture = spritesheet;
    bg->sprite = sfSprite_create();
    bg->rect = BG;
    bg->path = create_path_tile(map, spritesheet);
    return bg;
}
