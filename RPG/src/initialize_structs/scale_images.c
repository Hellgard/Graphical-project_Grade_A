/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "rpg.h"

void scale_images(all_var *all)
{
    sfSprite_scale(all->sprites->game_health_bar, (sfVector2f){0.6, 0.6});
    sfSprite_scale(all->sprites->game_shield_bar, (sfVector2f){0.6, 0.6});
    sfSprite_scale(all->sprites->game_armour_bar, (sfVector2f){0.6, 0.6});
}

void scale_enemies_book(all_var *all)
{
    int i = 0;
    while (all->game->enemy[i]->sprite != NULL && i < 12) {
        sfSprite_scale(all->game->enemy[i]->sprite, (sfVector2f){0.5, 0.5});
        i++;
    }
}

void scale_reset_enemies_book(all_var *all)
{
    int i = 0;
    while (all->game->enemy[i]->sprite != NULL && i < 12) {
        sfSprite_scale(all->game->enemy[i]->sprite, (sfVector2f){2, 2});
        i++;
    }
}