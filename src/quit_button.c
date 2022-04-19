/*
** EPITECH PROJECT, 2022
** quit_button.c
** File description:
** quit_button
*/

#include "my_defender.h"

void check_quit_button
(button_t *button , sfRenderWindow *window, sfEvent event)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f size = sfRectangleShape_getSize(button->rect);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > pos.x &&
        mouse.x < pos.x + size.x &&
        mouse.y > pos.y &&
        mouse.y < pos.y + size.y) {
        sfRenderWindow_close(window);
    }
}

void quit_button
(button_t *button, sfRenderWindow *window, sfEvent event, game_t *game)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (event.key.code == sfMouseLeft)
            check_quit_button(button, window, event);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        change_color_pressed(button, window, event);
    }
}

button_t *create_button_quit
(sfVector2f pos, sfVector2f size, sfTexture *spritesheet)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    button->button = BUTTON_QUIT;
    button->highlight = BUTTON_QUIT_HIGHLIGHT;
    button->pressed = BUTTON_QUIT_PRESSED;
    button->rect = sfRectangleShape_create();
    button->spritesheet = spritesheet;
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setTexture(button->rect, button->spritesheet, 0);
    sfRectangleShape_setTextureRect(button->rect, button->button);
    button->is_on = sfFalse;
    button->sound = create_sound(SOUND_BUTTON);
    button->update = update_button;
    button->action = quit_button;
    return button;
}
