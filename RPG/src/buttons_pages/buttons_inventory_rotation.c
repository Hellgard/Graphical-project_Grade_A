/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_inventory2_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 2);
    buttons[0] = create_button(1226, 495, 120, 70);
    buttons[1] = create_button(1740, 495, 120, 100);
    return (buttons);
}

sfVector2f *get_inventory2_button_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 2);
    buttons[0] = (sfVector2f){115, 103};
    buttons[1] = (sfVector2f){702, 195};
    return (buttons);
}

sfSprite **reaction_inventory2_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 2);
    reaction[0] = all->sprites->reaction_small_button;
    reaction[1] = all->sprites->reaction_big_button;
    return (reaction);
}

void buttons_inventory2(all_var *all)
{
    int res;
    int i = 0;
    int inv_page = all->var->inventory_page;
    new_button **buttons = get_inventory2_button(all);
    sfVector2f *pos = get_inventory2_button_pos(all);
    sfSprite **reaction = reaction_inventory2_button(all);

    while (i < 2) {
        res = is_button_pressed3(buttons[i], all, NULL, pos[i]);
        if (res == 2)
            all->var->easteregg_inventory_page = 0;
        if (res == 2 && i == 0)
            change_rotation_character(&all->vectors->select_char_rotation, -1);
        else if (res == 2 && i == 1)
            change_rotation_character(&all->vectors->select_char_rotation, 1);
        i++;
    }
    free(buttons);
    free(pos);
    free(reaction);
}
