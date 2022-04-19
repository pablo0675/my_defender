/*
** EPITECH PROJECT, 2022
** game.c
** File description:
** game
*/

#include "my_defender.h"
#include "my.h"

game_t *create_game(sfTexture *spritesheet)
{
    game_t *game = malloc(sizeof(game_t));

    game->spritesheet = spritesheet;
    game->map = create_map(MAP, game);
    game->enemys = create_enemys(game->map->checkpoint, spritesheet);
    game->clock = sfClock_create();
    game->last_time = 0.0;
    game->bg = create_game_bg(game->map->map, spritesheet);
    game = init_inventory(game);
    game->money = 300;
    game->base_hp = 3;
    game->state = play;
    game->base_hp_bar =
        create_hp_bar((sfVector2f){440, 5}, (sfVector2f){400, 30});
    game->sound = create_sound("assets/sounds/hit.ogg");
    return game;
}

void free_game(game_t *game)
{
    for (int i = 0; game->enemys[i] != NULL; i++) {
        sfRectangleShape_destroy(game->enemys[i]->rect);
        free_hp_bar(game->enemys[i]->hp_bar);
        free(game->enemys[i]);
    }
    sfSprite_destroy(game->bg->sprite);
    for (int i = 0; game->bg->path[i] != NULL; i++) {
        sfSprite_destroy(game->bg->path[i]->sprite);
        free(game->bg->path[i]);
    }
    for (int i = 0; game->map->map[i] != NULL; i++)
        free(game->map->map[i]);
    free(game->map->map);
    free_hp_bar(game->base_hp_bar);
    free_places(game->place);
    free(game->bg->path);
    free(game->bg);
    free(game->map->checkpoint);
    free(game->map);
    destroy_sound(game->sound);
}

game_t *init_music(game_t *game)
{
    game->music = sfMusic_createFromFile(MUSIC);
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_play(game->music);
    game->music_volume = sfMusic_getVolume(game->music);
    return game;
}

void game_loop(sfRenderWindow *window, sfEvent event, sfTexture *spritesheet)
{
    game_t *game = create_game(spritesheet);

    game = init_music(game);
    while (sfRenderWindow_isOpen(window) && game->state == play) {
        game_event(window, event, game);
        if (get_time_sec(game->clock) - game->last_time > 1 / FPS) {
            sfRenderWindow_clear(window, sfBlack);
            update_game(game);
            apply_game(window, game);
            is_win(game);
            game->last_time = get_time_sec(game->clock);
        }
    }
    sfClock_destroy(game->clock);
    sfMusic_destroy(game->music);
    free_game(game);
    free(game->enemys);
    free(game);
}
