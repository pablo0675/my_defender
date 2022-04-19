/*
** EPITECH PROJECT, 2022
** pause_menu.c
** File description:
** pause_menu
*/

#include "my_defender.h"

button_t **create_buttons_menu(sfTexture *spritesheet)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    sfVector2f pos = {440, 150};
    sfVector2f size = {400, 100};

    buttons[0] = create_button_go_title
                    (create_vectorf(440, 275), size, spritesheet);
    buttons[1] = create_button_quit
                    (create_vectorf(440, 400), size, spritesheet);
    buttons[2] = create_button_resume
                    (create_vectorf(440, 150), size, spritesheet);
    buttons[3] = NULL;
    return buttons;
}

void pause_event
(sfRenderWindow *window, sfEvent event, button_t **buttons, game_t *game)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        for (int i = 0; buttons[i] != NULL; i++)
            buttons[i]->action(buttons[i], window, event, game);
    }
}

void apply_pause
(sfRenderWindow *window, game_t *game)
{
    sfSprite_setTexture(game->bg->sprite, game->bg->texture, 0);
    sfSprite_setTextureRect(game->bg->sprite, game->bg->rect);
    sfSprite_setPosition(game->bg->sprite, game->bg->pos);
    sfRenderWindow_drawSprite(window, game->bg->sprite, NULL);
    for (int i = 0; game->bg->path[i] != NULL; i++) {
        sfSprite_setTexture
            (game->bg->path[i]->sprite, game->bg->path[i]->texture, 0);
        sfSprite_setTextureRect
            (game->bg->path[i]->sprite, game->bg->path[i]->rect);
        sfSprite_setPosition
            (game->bg->path[i]->sprite, game->bg->path[i]->pos);
        sfRenderWindow_drawSprite(window, game->bg->path[i]->sprite, NULL);
    }
    apply_tower_places(window, game);
    apply_towers(window, game->place);
    for (int i = 0; game->place[i] != NULL; i++) {
        if (game->place[i]->is_tower == sfTrue)
            apply_proj(window, game->place[i]->tower);
    }
    apply_enemys(window, game->enemys);
}

void pause_menu(sfRenderWindow *window, sfEvent event, game_t *game)
{
    button_t **buttons = create_buttons_menu(game->spritesheet);
    float last_time = get_time_sec(game->clock);
    while (sfRenderWindow_isOpen(window) && game->state == play) {
        pause_event(window, event, buttons, game);
        for (int i = 0; buttons[i] != NULL; i++)
            buttons[i]->update(buttons[i], window);
        if (get_time_sec(game->clock) - game->last_time > 1 / FPS) {
            update_dtime(game, &last_time);
            sfRenderWindow_clear(window, sfBlack);
            apply_pause(window, game);
            for (int i = 0; buttons[i] != NULL; i++)
                sfRenderWindow_drawRectangleShape
                            (window, buttons[i]->rect, NULL);
            sfRenderWindow_display(window);
            game->last_time = get_time_sec(game->clock);
        }
    }
    if (game->state == resume)
        game->state = play;
    free_buttons(buttons);
}
