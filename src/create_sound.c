/*
** EPITECH PROJECT, 2022
** create_sound.c
** File description:
** create_sound
*/

#include "my_defender.h"

sound_t *create_sound(const char *file)
{
    sound_t *struct_sound = malloc(sizeof(sound_t));
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(file);
    sfSound *sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);
    struct_sound->buffer = buffer;
    struct_sound->sound = sound;
    return struct_sound;
}

void destroy_sound(sound_t *sound)
{
    sfSound_stop(sound->sound);
    sfSoundBuffer_destroy(sound->buffer);
    sfSound_destroy(sound->sound);
    free(sound);
}
