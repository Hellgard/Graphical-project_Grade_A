/*
** EPITECH PROJECT, 2022
** close_game.c
** File description:
** close_game
*/

#include "rpg.h"

void close_game(all_var *all)
{
    sfRenderWindow_close(all->windows->window);
}
