/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_save_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 8);
    buttons[0] = create_button(140, 70, 170, 130);
    buttons[1] = create_button(270, 395, 450, 260);
    buttons[2] = create_button(785, 395, 450, 260);
    buttons[3] = create_button(1292, 395, 450, 260);
    buttons[4] = create_button(605, 320, 100, 120);
    buttons[5] = create_button(1115, 320, 100, 120);
    buttons[6] = create_button(1630, 320, 100, 120);
    buttons[7] = create_button(1581, 65, 170, 130);
    return (buttons);
}

sfVector2f *get_save_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 8);
    buttons[0] = (sfVector2f){115, 103};
    buttons[1] = (sfVector2f){241, 405};
    buttons[2] = (sfVector2f){755, 405};
    buttons[3] = (sfVector2f){1273, 405};
    buttons[4] = (sfVector2f){250, 405};
    buttons[5] = (sfVector2f){755, 405};
    buttons[6] = (sfVector2f){1260, 405};
    buttons[7] = (sfVector2f){1573, 105};
    return (buttons);
}

int *get_next_page_save(all_var *all)
{
    int *next_page = malloc(sizeof(int) * 8);
    next_page[0] = 2;
    next_page[1] = 0;
    next_page[2] = 1;
    next_page[3] = 2;
    next_page[4] = 0;
    next_page[5] = 1;
    next_page[6] = 2;
    next_page[7] = 2;
    return (next_page);
}

sfSprite **reaction_save_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 8);
    reaction[0] = all->sprites->reaction_small_button;
    reaction[1] = all->sprites->reaction_giant_button;
    reaction[2] = all->sprites->reaction_giant_button;
    reaction[3] = all->sprites->reaction_giant_button;
    reaction[4] = NULL;
    reaction[5] = NULL;
    reaction[6] = NULL;
    reaction[7] = all->sprites->reaction_small_button;
    return (reaction);
}

void buttons_save(all_var *all)
{
    int res;
    int i = 0;
    int *next_page = get_next_page_save(all);
    new_button **buttons = get_save_button(all);
    sfVector2f *pos = get_save_pos(all);
    sfSprite **reaction = reaction_save_button(all);

    while (i < 8) {
        res = is_button_pressed3(buttons[i], all, reaction[i], pos[i]);
        if (res == 2)
            buttons_save_actions(all, next_page, i);
        i++;
    }
    free(next_page);
    free(buttons);
    free(pos);
    free(reaction);
}
