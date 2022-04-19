/*
** EPITECH PROJECT, 2022
** defender
** File description:
** defender
*/

#include "../../include/my_defender.h"

void draw_inventory(game_t *game, sfRenderWindow *window)
{
    for (int i = 4; i >= 0; i--)
        sfRenderWindow_drawSprite(window, game->sprite[i].sprite, NULL);
}

sprite_t set_init_scale(sprite_t sprite, float x, float y)
{
    sprite.scale.x = x;
    sprite.scale.y = y;
    return sprite;
}

sprite_t set_init_pos(sprite_t sprite, int x, int y)
{
    sprite.pos.x = x;
    sprite.pos.y = y;
    return sprite;
}

sprite_t my_init_background(sprite_t backgrounds, char const *filepath)
{
    backgrounds.texture = sfTexture_createFromFile(filepath,  NULL);
    sfSprite_setTexture(backgrounds.sprite, backgrounds.texture, sfFalse);
    sfSprite_setPosition(backgrounds.sprite, backgrounds.pos);
    sfSprite_scale(backgrounds.sprite, backgrounds.scale);
    return backgrounds;
}

game_t *init_inventory(game_t *game)
{
    game->sprite = malloc(sizeof(sprite_t) * 6);
    game->drag_drop = malloc(sizeof(drag_drop_t));
    game->drag_drop->exist = sfFalse;
    for (int i = 0; i < 5; i++)
        game->sprite[i].sprite = sfSprite_create();
    for (int i = 0; i < 4; i++) {
        game->sprite[i] = set_init_pos(game->sprite[i], 1224 - (55 * i), 2);
        game->sprite[i] = set_init_scale(game->sprite[i], 0.3, 0.3);
    }
    game->sprite[0] = my_init_background(game->sprite[0], yellow);
    game->sprite[1] = my_init_background(game->sprite[1], green);
    game->sprite[2] = my_init_background(game->sprite[2], blue);
    game->sprite[3] = my_init_background(game->sprite[3], red);
    game->sprite[4] = set_init_pos(game->sprite[4], 1280 - 220, 0);
    game->sprite[4] = set_init_scale(game->sprite[4], 1, 1);
    game->sprite[4] = my_init_background(game->sprite[4], inventory);
    game->drag_drop->sprite = sfSprite_create();
    sfSprite_setScale(game->drag_drop->sprite, game->sprite[1].scale);
    return game;
}
