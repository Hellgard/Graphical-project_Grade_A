/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "rpg.h"

void create_clocks(all_var *all)
{
    all->clocks->clock_button = sfClock_create();
    all->clocks->clock_animation_equiped = sfClock_create();
    all->clocks->clock_key = sfClock_create();
    all->clocks->clock_event = sfClock_create();
    all->clocks->clock_show = sfClock_create();
    all->clocks->clock_player_name = sfClock_create();
}
