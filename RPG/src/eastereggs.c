/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void easteregg_inventory_page(all_var *all)
{
    if (true &&
    sfTime_asSeconds(all->clocks->time_animation) > 0.1) {
        all->var->player++;
        if (all->var->player > 2)
            all->var->player = 0;
        sfClock_restart(all->clocks->clock_animation_equiped);
    }
}
