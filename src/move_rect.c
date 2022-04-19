/*
** EPITECH PROJECT, 2022
** move_rect.c
** File description:
** move_rect
*/

#include <SFML/Graphics.h>

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset + rect->width > max_value)
        rect->left = 0;
    else
        rect->left += offset;
}