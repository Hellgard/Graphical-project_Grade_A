/*
** EPITECH PROJECT, 2022
** equip_delete_selected
** File description:
** equip_delete_selected
*/

#include "rpg.h"

void equip_delete_selected(all_var *all)
{
    new_button *delete = create_button(1056, 114, 170, 100);
    new_button *equip = create_button(1228, 114, 170, 100);
    sfVector2f pos = {450, 480};

    if (is_button_pressed3(delete, all, NULL, pos) == 2) {
        delete_element_inventory(all);
        all->var->item_selected = -1;
    }
    if (is_button_pressed3(equip, all, NULL, pos) == 2) {
        if (get_slot_inventory(all)->in_use == 0)
            equip_element_inventory(all);
        else
            unequip_element_inventory(all);
        if (get_slot_inventory(all)->quantity == 0)
            all->var->item_selected = -1;
    }
}
