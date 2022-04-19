/*
** EPITECH PROJECT, 2022
** resume_button.c
** File description:
** resume_button
*/

#include "my_defender.h"

void check_resume_button
(button_t *button, sfRenderWindow *window, sfEvent event, game_t *game)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f size = sfRectangleShape_getSize(button->rect);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > pos.x &&
        mouse.x < pos.x + size.x &&
        mouse.y > pos.y &&
        mouse.y < pos.y + size.y) {
        game->state = resume;
    }
}

void resume_button
(button_t *button, sfRenderWindow *window, sfEvent event, game_t *game)
{
    int ret = 0;

    if (event.type == sfEvtMouseButtonReleased) {
        if (event.key.code == sfMouseLeft)
            check_resume_button(button, window, event, game);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        change_color_pressed(button, window, event);
    }
}

button_t *create_button_resume
(sfVector2f pos, sfVector2f size, sfTexture *spritesheet)
{
    button_t *button = malloc(sizeof(button_t));

    if (button == NULL)
        return NULL;
    button->button = BUTTON_RESUME;
    button->highlight = BUTTON_RESUME_HIGHLIGHT;
    button->pressed = BUTTON_RESUME_PRESSED;
    button->spritesheet = spritesheet;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setTexture(button->rect, button->spritesheet, 0);
    sfRectangleShape_setTextureRect(button->rect, button->button);
    button->is_on = sfFalse;
    button->sound = create_sound(SOUND_BUTTON);
    button->update = update_button;
    button->action = resume_button;
    return button;
}
