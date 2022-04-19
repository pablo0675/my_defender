/*
** EPITECH PROJECT, 2022
** my_defender.h
** File description:
** my_defender
*/

#ifndef MY_DEFENDER_H_
    #define MY_DEFENDER_H_

    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include "drag_drop.h"
    #include "spritesheet.h"

static const int FPS = 60;
static const int TILE = 40;
static const char SOUND_BUTTON[] = "assets/sounds/button.wav";

//MUSIC
static const char MUSIC[] = "assets/defender_theme.ogg";

// MAPS
static const char MAP[] = "maps/path.txt";

//inventory
static const char yellow[] = "assets/yellow.png";
static const char green[] = "assets/green.png";
static const char blue[] = "assets/blue.png";
static const char red[] = "assets/red.png";
static const char inventory[] = "assets/wow.png";

enum state_e {
    play,
    resume,
    title_e,
    game_over,
    win
};

typedef struct sound_s {
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound_t;

typedef struct hp_bar_s {
    sfVector2f pos;
    sfRectangleShape *black;
    sfRectangleShape *red;
} hp_bar_t;

typedef struct slow_s {
    sfBool is_slow;
    float slow;
    float duration;
} slow_t;

typedef struct enemy_s {
    sfVector2f pos;
    sfRectangleShape *rect;
    hp_bar_t *hp_bar;
    sfIntRect hitbox;
    sfIntRect texture_rect;
    sfVector2f speed;
    sfTexture *spritesheet;
    slow_t slow;
    float move_speed;
    float max_speed;
    int checkpoint;
    int hp;
    int max_hp;
    float dtime;
    int value;
    int damage;
    float last_time;
    int replace;
    void (*move)(struct enemy_s *, sfVector2f *, sfClock *);
} enemy_t;

typedef struct path_s {
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} path_t;

typedef struct bg_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    path_t **path;
} bg_t;

typedef struct is_changed_s {
    int is_changed;
    int last_dir;
    int id;
} is_changed_t;

typedef struct circle_s {
    int x;
    int y;
    int radius;
} circle_t;

typedef struct proj_s {
    sfVector2f pos;
    sfVector2f move;
    sfRectangleShape *rect;
    sfIntRect hitbox;
    float speed;
    float slow;
    int target;
    float dtime;
    int damage;
} proj_t;

typedef struct tower_s {
    circle_t circle;
    sfCircleShape *range;
    sfRectangleShape *rect;
    sfVector2f pos;
    sfTexture *texture;
    float cd;
    float last_shot;
    int damage;
    int last_target;
    float slow;
    proj_t **proj;
    void (*attack)(struct tower_s *, enemy_t **, sfClock *, sfVector2f *);
} tower_t;

typedef struct twr_place_s {
    sfVector2f pos;
    sfRectangleShape *rect;
    sfIntRect hitbox;
    sfBool is_tower;
    tower_t *tower;
} twr_place_t;

typedef struct map_s {
    char **map;
    sfVector2f *checkpoint;
} map_t;

typedef struct game_s {
    enemy_t **enemys;
    sfClock *clock;
    float last_time;
    bg_t *bg;
    map_t *map;
    sfMusic *music;
    float music_volume;
    int money;
    int base_hp;
    hp_bar_t *base_hp_bar;
    enum state_e state;
    twr_place_t **place;
    sfTexture *spritesheet;
    sprite_t *sprite;
    drag_drop_t *drag_drop;
    sound_t *sound;
} game_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfTexture *spritesheet;
    sfIntRect button;
    sfIntRect highlight;
    sfIntRect pressed;
    sound_t *press_sound;
    sfBool is_on;
    sound_t *sound;
    void (*update)(struct button_s *, sfRenderWindow *);
    void (*action)
        (struct button_s *, sfRenderWindow *, sfEvent, game_t *game);
} button_t;

float get_time_sec(sfClock *clock);
void move_rect(sfIntRect *rect, int offset, int max_value);

void game_loop(sfRenderWindow *window, sfEvent event, sfTexture *spritesheet);
sfVector2f create_vectorf(float x, float y);
sfColor create_color(int red, int green, int blue, int alpha);
sfIntRect create_rect(int top, int left, int width, int height);
int nb_checkpoint(char **map);
map_t *create_map(const char *path, game_t *game);
sfFloatRect create_rectf(int top, int left, int width, int height);
sfVector2u get_pos_start(char **map, int x, int y, sfVector2u *pos);
path_t **create_path_tile(char **map, sfTexture *spritesheet);
sfVector2i create_vectori(int x, int y);

sfVector2f normalize_vec(sfVector2f vec);

// WINDOW
int create_window(void);

// UPDATE GAME
void update_game(game_t *game);
void is_win(game_t *game);

// TITLE
void title(sfRenderWindow *window, sfEvent event, sfTexture *spritesheet);

// CREATE_TILE
void create_tile_right
(char **map, sfVector2u *pos, is_changed_t *check, path_t **path);
void create_tile_left
(char **map, sfVector2u *pos, is_changed_t *check, path_t **path);
void create_tile_down
(char **map, sfVector2u *pos, is_changed_t *check, path_t **path);
void create_tile_up
(char **map, sfVector2u *pos, is_changed_t *check, path_t **path);
void rotate_sprite(sfSprite *sprite, float angle);
int nb_path_tile(char **map);
void count_path(char **map, int x, int y, int *count);

// BUTTON
void change_color_pressed
(button_t *button , sfRenderWindow *window, sfEvent event);
void update_button(button_t *button ,sfRenderWindow *window);
void free_buttons(button_t **buttons);

// START BUTTON
void check_start_button
(button_t *button , sfRenderWindow *window, sfEvent event);
button_t *create_button_start
(sfVector2f pos, sfVector2f size, sfTexture *spritesheet);

// QUIT BUTTON
void quit_button
(button_t *button, sfRenderWindow *window, sfEvent event, game_t *game);
button_t *create_button_quit
(sfVector2f pos, sfVector2f size, sfTexture *spritesheet);

// RESUME BUTTON
button_t *create_button_resume
(sfVector2f pos, sfVector2f size, sfTexture *spritesheet);

// GO TITLE BUTTON
button_t *create_button_go_title
(sfVector2f pos, sfVector2f size, sfTexture *spritesheet);

// ENEMY
static const sfVector2f ENEMY_SIZE = {32, 32};
static const int ENEMY_HP = 30;
static const int BIG_ENEMY_HP = 45;
static const int ENEMY_SPEED = 70;
static const int BIG_ENEMY_SPEED = 50;

void speed_to_checkpoint(enemy_t *enemy, sfVector2f *checkpoint, int i);
void update_speed_y
(enemy_t *enemy, sfVector2f *checkpoint, int i, int before_cp);
void update_speed(enemy_t *enemy, sfVector2f *checkpoint, int i);
void move_enemy(enemy_t *enemy, sfVector2f *checkpoint, sfClock *clock);
enemy_t *create_enemy(sfVector2f pos, sfTexture *spritesheet);
enemy_t *create_big_enemy(sfVector2f pos, sfTexture *spritesheet);
void get_right
    (char **map, sfVector2u *pos, sfVector2f *checkpoint, is_changed_t *check);
twr_place_t *create_yellow_tower(twr_place_t *place, int i);


// GAME EVENT
game_t *game_event(sfRenderWindow *window, sfEvent event, game_t *game);

// CREATE GAME OBJECTS
enemy_t **create_enemys(sfVector2f *checkpoint, sfTexture *spritesheet);
bg_t *create_game_bg(char **map, sfTexture *spritesheet);

// COLLIDE
sfBool is_coll_rect_circ(sfIntRect rect, circle_t circle);
sfBool is_coll_enemy_circ(enemy_t *enemy, circle_t circle);
sfBool collide_rects
(sfVector2f pos1, sfIntRect rect1, sfVector2f pos2, sfIntRect rect2);

// TOWER
void create_towers(game_t *game);
void free_tower(tower_t *tower);
int id_further_enemy(tower_t *tower, enemy_t **enemys, sfVector2f *checkpoint);
int tower_check_pos(int pressed, game_t *game,
                    int i, sfVector2i mouse);
int check_click(sfEvent event);
int check_click_place(sfEvent event, int pressed, int value);
void set_range_tower(tower_t *tower, circle_t circle);
void tower_attack
    (tower_t *tower, enemy_t **enemys, sfClock *clock, sfVector2f *checkpoint);
tower_t *create_tower(tower_t *tower, float cd, int damage, float slow);
twr_place_t *create_red_tower(twr_place_t *place, int i);

// HP BAR
hp_bar_t *create_hp_bar(sfVector2f pos, sfVector2f size);
void update_hp_bar(hp_bar_t *hp_bar, int current, int max);
void update_pos_hp_bar(enemy_t *enemy);
void free_hp_bar(hp_bar_t *hp_bar);

// APPLY GAME
void apply_game(sfRenderWindow *window, game_t *game);
void apply_enemys(sfRenderWindow *window, enemy_t **enemys);
void apply_proj(sfRenderWindow *window, tower_t *tower);
void apply_towers(sfRenderWindow *window, twr_place_t **place);
void apply_tower_places(sfRenderWindow *window, game_t *game);
void apply_path(sfRenderWindow *window, game_t *game);

// PROJECTILES
void shoot_proj(tower_t *tower, enemy_t *enemy, int target_nb, sfClock *clock);
void free_projectiles(proj_t **proj);
void update_proj(enemy_t **enemys, proj_t *proj, game_t *game);
proj_t **create_projectiles(int nb, int damage, float slow, sfColor color);
void update_all_proj(game_t *game, tower_t *tower);

// PAUSE MENU
void pause_menu(sfRenderWindow *window, sfEvent event, game_t *game);
void update_dtime_tower(twr_place_t *place, float *last_time, float new);
void update_dtime(game_t *game, float *last_time);

// SOUND
sound_t *create_sound(const char *file);
void destroy_sound(sound_t *sound);

// DAMAGE
void damage_enemy(enemy_t **enemys, proj_t *proj, game_t *game);
void damage_base(game_t *game);

// TOWER PLACE
twr_place_t **create_tower_place(char **map, int nb_place);
int count_nb_place(char **map);
void free_places(twr_place_t **place);
game_t *init_inventory(game_t *game);
void draw_inventory(game_t *game, sfRenderWindow *window);

// SLOW ENEMY
void decrease_speed(enemy_t *enemy);
void is_slow_enemy(enemy_t *enemy, sfClock *clock);

#endif /* !MY_DEFENDER_H_ */
