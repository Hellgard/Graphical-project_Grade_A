/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void equip_element_inventory_2(all_var *all)
{
    int result = all->var->health;
    result += my_getnbr(all->var->item_propeties[1]);
    if (result >= all->game->player->max_life)
        all->game->player->life = all->game->player->max_life;
    else
        all->game->player->life = result;
    all->game->player->defense += my_getnbr(all->var->item_propeties[2]);
    all->game->player->attack += my_getnbr(all->var->item_propeties[3]);
    all->var->animation_equiped = 0;
}

void equip_element_inventory(all_var *all)
{
    t_info_inventory *tmp = get_slot_inventory(all);
    if (my_strcmp(all->var->item_propeties[4], "2") != 0) {
        tmp->in_use = 1;
        if (my_strcmp(all->var->item_propeties[4], "0") == 0 &&
        all->var->weapon == 0) {
            equip_element_inventory_2(all);
            all->var->weapon = 1;
        } else if (my_strcmp(all->var->item_propeties[4], "1") == 0 &&
        all->var->shield == 0) {
            equip_element_inventory_2(all);
            all->var->shield = 1;
        } else
            tmp->in_use = 0;
    }
    else if (all->var->health < all->game->player->max_life) {
        tmp->quantity--;
        if (tmp->quantity == 0)
            tmp->type = -1;
        equip_element_inventory_2(all);
    }
}

void delete_element_inventory(all_var *all)
{
    t_info_inventory *tmp = get_slot_inventory(all);

    unequip_element_inventory(all);
    tmp->quantity = 0;
    tmp->type = -1;
}

sfVector2f get_inventory_pos(int num)
{
    int num2 = num;
    while (num2 >= 4)
        num2 -= 4;
    float x = 340 + (166 * num2);
    float y = 270 + (153 * (num / 4));
    return ((sfVector2f) {x, y});
}
