/*
** EPITECH PROJECT, 2022
** button.c
** File description:
** button
*/

#include "my_defender.h"

void change_color_pressed
(button_t *button , sfRenderWindow *window, sfEvent event)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f size = sfRectangleShape_getSize(button->rect);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > pos.x &&
        mouse.x < pos.x + size.x &&
        mouse.y > pos.y &&
        mouse.y < pos.y + size.y) {
        sfRectangleShape_setTextureRect(button->rect, button->pressed);
    }
    else
        sfRectangleShape_setTextureRect(button->rect, button->button);
}

void update_button(button_t *button, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f size = sfRectangleShape_getSize(button->rect);

    if (mouse.x > pos.x && mouse.x < pos.x + size.x &&
        mouse.y > pos.y && mouse.y < pos.y + size.y) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse)
            sfRectangleShape_setTextureRect(button->rect, button->highlight);
        if (button->is_on == sfFalse) {
            button->is_on = sfTrue;
            sfSound_stop(button->sound->sound);
            sfSound_play(button->sound->sound);
        }
    } else {
        sfRectangleShape_setTextureRect(button->rect, button->button);
        button->is_on = sfFalse;
    }
}
