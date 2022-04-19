/*
** EPITECH PROJECT, 2021
** create_rect.c
** File description:
** create_rect
*/

#include "my_defender.h"

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}

sfFloatRect create_rectf(int top, int left, int width, int height)
{
    sfFloatRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}
