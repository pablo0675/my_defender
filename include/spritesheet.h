/*
** EPITECH PROJECT, 2022
** spritesheet.h
** File description:
** spritesheet
*/

#ifndef SPRITESHEET_H_
    #define SPRITESHEET_H_
    #include <SFML/Graphics.h>

static const sfIntRect BG = {0, 600, 1280, 720};
static const sfIntRect TILE_STRAIGHT = {800, 0, 40, 40};
static const sfIntRect TILE_CORNER = {840, 0, 40, 40};
static const sfIntRect TILE_START = {880, 0, 40, 40};
static const sfIntRect BUTTON_START = {0, 0, 400, 100};
static const sfIntRect BUTTON_START_HIGHLIGHT = {0, 100, 400, 100};
static const sfIntRect BUTTON_START_PRESSED = {0, 200, 400, 100};
static const sfIntRect BUTTON_QUIT = {400, 0, 400, 100};;
static const sfIntRect BUTTON_QUIT_HIGHLIGHT = {400, 100, 400, 100};
static const sfIntRect BUTTON_QUIT_PRESSED = {400, 200, 400, 100};
static const sfIntRect BUTTON_RESUME = {0, 300, 400, 100};
static const sfIntRect BUTTON_RESUME_HIGHLIGHT = {0, 400, 400, 100};
static const sfIntRect BUTTON_RESUME_PRESSED = {0, 500, 400, 100};
static const sfIntRect BUTTON_GO_TITLE = {400, 300, 400, 100};
static const sfIntRect BUTTON_GO_TITLE_HIGHLIGHT = {400, 400, 400, 100};
static const sfIntRect BUTTON_GO_TITLE_PRESSED = {400, 500, 400, 100};
static const sfIntRect LEANDRE = {0, 1320, 545, 600};

#endif /* !SPRITESHEET_H_ */
