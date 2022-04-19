/*
** EPITECH PROJECT, 2022
** show_square.c
** File description:
** show_square
*/

#include "my_defender.h"

void show_square(sfRenderWindow *window)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = create_vectorf(36, 36);
    sfVector2f pos = create_vectorf(2, 2);

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRectangleShape_setOutlineColor(rect, create_color(150, 0, 0, 100));
    sfRectangleShape_setFillColor(rect, create_color(255, 255, 255, 0));
    for (int y = 0; y <= 18; y++) {
        pos = create_vectorf(2, 2 + (40 * y));
        for (int x = 0; x <= 32; x++) {
            sfRectangleShape_setPosition(rect, pos);
            sfRenderWindow_drawRectangleShape(window, rect, NULL);
            pos.x += 40;
        }
    }
}