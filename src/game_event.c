/*
** EPITECH PROJECT, 2022
** game_event.c
** File description:
** game_event
*/

#include "my_defender.h"
#include "my.h"
#include <stddef.h>

static int check = 0;

static int check_tower(game_t *game, sfVector2i mouse)
{
    if ((mouse.x < 1115 && mouse.x > 1050) && (mouse.y < 60))
        return 3;
    if ((mouse.x < 1170 && mouse.x > 1120) && (mouse.y < 60))
        return 2;
    if ((mouse.x < 1220 && mouse.x > 1174) && (mouse.y < 60))
        return 1;
    if ((mouse.x < 1275 && mouse.x > 1228) && (mouse.y < 60))
        return 0;
    return 84;
}

game_t *check_pos_tower(game_t *game, sfEvent event,
                        sfRenderWindow *window, sfVector2i mouse)
{
    int i = check_tower(game, mouse);

    if (i == 84 && game->drag_drop->exist != sfFalse)
        return game;
    if (i == 0 && game->drag_drop->exist == sfFalse)
        game->drag_drop->texture = sfTexture_createFromFile(t1, NULL);
    if (i == 1 && game->drag_drop->exist == sfFalse)
        game->drag_drop->texture = sfTexture_createFromFile(t2, NULL);
    if (i == 2 && game->drag_drop->exist == sfFalse)
        game->drag_drop->texture = sfTexture_createFromFile(t3, NULL);
    if (i == 3 && game->drag_drop->exist == sfFalse)
        game->drag_drop->texture = sfTexture_createFromFile(t4, NULL);
    if (i < 4 && i >= 0) {
        game->drag_drop->exist = sfTrue;
    }
    game->drag_drop->type = i;
    return game;
}

int place_turret(game_t *game, sfVector2i mouse)
{
    for (int i = 0; game->place[i] != NULL; i++) {
        tower_check_pos(game->drag_drop->type, game, i, mouse);
    }
    return 0;
}

void check_input_game(sfRenderWindow *window, sfEvent event, game_t *game)
{
    if (event.key.code == sfKeyEscape) {
        sfMusic_pause(game->music);
        pause_menu(window, event, game);
        sfMusic_play(game->music);
    }
}

game_t *game_event(sfRenderWindow *window, sfEvent event, game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    sfVector2i mouse;

    while (sfRenderWindow_pollEvent(window, &event)) {
        mouse = sfMouse_getPositionRenderWindow(window);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            check_input_game(window, event, game);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game = check_pos_tower(game, event, window, mouse);
            place_turret(game, mouse);
        }
        game->drag_drop->pos = set_pos(game->drag_drop->pos, mouse.x, mouse.y);
        sfSprite_setPosition(game->drag_drop->sprite,
                             game->drag_drop->pos);
    }
    return game;
}
