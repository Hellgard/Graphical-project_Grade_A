/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_inventory_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 6);
    buttons[0] = create_button(115, 175, 120, 70);
    buttons[1] = create_button(126, 325, 120, 100);
    buttons[2] = create_button(127, 715, 120, 100);
    buttons[3] = create_button(115, 900, 120, 70);
    buttons[4] = create_button(1450, 247, 120, 130);
    buttons[5] = create_button(1730, 0, 50, 70);
    return (buttons);
}

sfVector2f *get_inventory_button_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 6);
    buttons[0] = (sfVector2f){115, 103};
    buttons[1] = (sfVector2f){702, 195};
    buttons[2] = (sfVector2f){702, 471};
    buttons[3] = (sfVector2f){702, 756};
    buttons[4] = (sfVector2f){0, 0};
    buttons[5] = (sfVector2f){0, 0};
    return (buttons);
}

sfSprite **reaction_inventory_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 6);
    reaction[0] = all->sprites->reaction_small_button;
    reaction[1] = all->sprites->reaction_big_button;
    reaction[2] = all->sprites->reaction_big_button;
    reaction[3] = all->sprites->reaction_big_button;
    reaction[4] = NULL;
    reaction[5] = NULL;
    return (reaction);
}

void buttons_inventory(all_var *all)
{
    int res;
    int i = 0;
    int inv_page = all->var->inventory_page;
    new_button **buttons = get_inventory_button(all);
    sfVector2f *pos = get_inventory_button_pos(all);
    sfSprite **reaction = reaction_inventory_button(all);

    while (i < 6) {
        if (i == 1 && inv_page > 0 || i == 2 && inv_page < 3 ||
        i != 1 && i != 2)
            res = is_button_pressed3(buttons[i], all, NULL, pos[i]);
        if (res == 2)
            buttons_inventory_actions(all, inv_page, i);
        i++;
    }
    free(buttons);
    free(pos);
    free(reaction);
}
