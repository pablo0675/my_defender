/*
** EPITECH PROJECT, 2022
** defender
** File description:
** drag_drop
*/

#ifndef DEFENDER_DRAG_DROP_H
    #define DEFENDER_DRAG_DROP_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <unistd.h>
    #include <stdlib.h>

static char t1[] = "assets/tower1.png";
static char t2[] = "assets/tower2.png";
static char t3[] = "assets/tower3.png";
static char t4[] = "assets/tower4.png";

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} sprite_t;

typedef struct drag_drop_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    int type;
    sfBool exist;
} drag_drop_t;

sprite_t set_init_pos(sprite_t sprite, int x, int y);
sfVector2f set_pos(sfVector2f pos, int x, int y);

#endif //DEFENDER_DRAG_DROP_H
