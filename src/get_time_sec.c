/*
** EPITECH PROJECT, 2022
** get_time_sec.c
** File description:
** get_time_sec
*/

#include <SFML/Graphics.h>

float get_time_sec(sfClock *clock)
{
    sfTime time;
    float seconds = 0.0;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return seconds;
}