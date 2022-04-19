/*
** EPITECH PROJECT, 2022
** title.c
** File description:
** title
*/

#include "my_defender.h"

void event_title
(sfRenderWindow *window, sfEvent event, button_t **buttons)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtResized) {
        }
        for (int i = 0; buttons[i] != NULL; i++)
            buttons[i]->action(buttons[i], window, event, NULL);
    }
}

button_t **create_buttons_title(sfTexture *spritesheet)
{
    button_t **buttons = malloc(sizeof(button_t) * 3);
    sfVector2f pos = {440, 200};
    sfVector2f size = {400, 100};

    buttons[0] = create_button_start(pos, size, spritesheet);
    pos.y += 200;
    buttons[1] = create_button_quit(pos, size, spritesheet);
    buttons[2] = NULL;
    return buttons;
}

void free_buttons(button_t **buttons)
{
    for (int i = 0; buttons[i] != NULL; i++) {
        sfRectangleShape_destroy(buttons[i]->rect);
        destroy_sound(buttons[i]->sound);
        free(buttons[i]);
    }
    free(buttons);
}

void title(sfRenderWindow *window, sfEvent event, sfTexture *spritesheet)
{
    button_t **buttons = create_buttons_title(spritesheet);

    while (sfRenderWindow_isOpen(window)) {
        event_title(window, event, buttons);
        sfRenderWindow_clear(window, sfBlack);
        for (int i = 0; buttons[i] != NULL; i++) {
            buttons[i]->update(buttons[i], window);
            sfRenderWindow_drawRectangleShape(window, buttons[i]->rect, NULL);
        }
        sfRenderWindow_display(window);
    }
    free_buttons(buttons);
}
