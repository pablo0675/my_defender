/*
** EPITECH PROJECT, 2022
** go_title_button.c
** File description:
** go_title_button
*/

#include "my_defender.h"

void check_go_title_button
(button_t *button, sfRenderWindow *window, sfEvent event, game_t *game)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f size = sfRectangleShape_getSize(button->rect);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > pos.x &&
        mouse.x < pos.x + size.x &&
        mouse.y > pos.y &&
        mouse.y < pos.y + size.y) {
        game->state = title_e;
    }
}

void go_title_button
(button_t *button, sfRenderWindow *window, sfEvent event, game_t *game)
{

    if (event.type == sfEvtMouseButtonReleased) {
        if (event.key.code == sfMouseLeft)
            check_go_title_button(button, window, event, game);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        change_color_pressed(button, window, event);
    }
}

button_t *create_button_go_title
(sfVector2f pos, sfVector2f size, sfTexture *spritesheet)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    button->button = BUTTON_GO_TITLE;
    button->highlight = BUTTON_GO_TITLE_HIGHLIGHT;
    button->pressed = BUTTON_GO_TITLE_PRESSED;
    button->spritesheet = spritesheet;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setTexture(button->rect, button->spritesheet, 0);
    sfRectangleShape_setTextureRect(button->rect, button->button);
    button->is_on = sfFalse;
    button->sound = create_sound(SOUND_BUTTON);
    button->update = update_button;
    button->action = go_title_button;
    return button;
}
