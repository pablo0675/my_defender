/*
** EPITECH PROJECT, 2022
** normalize_vec.c
** File description:
** normalize_vec
*/

#include "my_defender.h"
#include <math.h>

sfVector2f normalize_vec(sfVector2f vec)
{
    float m = sqrtf((vec.x * vec.x) + (vec.y * vec.y));
    sfVector2f norm;

    norm.x = vec.x / m;
    norm.y = vec.y / m;
    return norm;
}
