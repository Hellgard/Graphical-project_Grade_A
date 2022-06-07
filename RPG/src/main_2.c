/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "rpg.h"

void change_sound(all_var *all)
{
    if (all->var->sound_on == 0)
        sfMusic_setVolume(all->game->scene->ambiance, 60);
    if (all->var->sound_on == 1)
        sfMusic_setVolume(all->game->scene->ambiance, 0);
}
