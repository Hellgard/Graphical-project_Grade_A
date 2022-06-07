/*
** EPITECH PROJECT, 2022
** set_item.c
** File description:
** set_item
*/

#include "rpg.h"

void set_item(all_var *all, sfVector2f pos2, t_info_inventory *tmp)
{
    sfSprite_setPosition(all->sprites->reaction_inventory, pos2);
    sfRenderWindow_drawSprite(all->windows->window
    , all->sprites->reaction_inventory, NULL);
    all->var->item_selected = tmp->num_slot;
    show_item_properties(all);
}
