/*
** EPITECH PROJECT, 2022
** defender
** File description:
** check_click
*/

#include "../include/my_defender.h"

int check_click(sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.type != sfEvtMouseButtonReleased)
            return 1;
        return 0;
    }
    return 0;
}

int check_click_place(sfEvent event, int pressed, int value)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (event.key.code == sfMouseLeft && pressed != value)
            return 1;
        return 0;
    }
    return 0;
}