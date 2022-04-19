/*
** EPITECH PROJECT, 2022
** window.c
** File description:
** window
*/

#include "my_defender.h"

int create_window(void)
{
    unsigned int width = 1920;
    unsigned int height = 1080;
    sfTexture *spritesheet =
        sfTexture_createFromFile("assets/spritesheet.png", NULL);
    sfVideoMode mode = {width, height, 32};
    sfEvent event;
    sfRenderWindow *window =
    sfRenderWindow_create(mode, "TEST", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, FPS);
    title(window, event, spritesheet);
    sfTexture_destroy(spritesheet);
    sfRenderWindow_destroy(window);
    return 0;
}
