/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_settings_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 8);
    buttons[0] = create_button(140, 70, 170, 130);
    buttons[1] = create_button(1050, 233, 170, 130);
    buttons[2] = create_button(1300, 233, 170, 130);
    buttons[3] = create_button(1050, 481, 170, 130);
    buttons[4] = create_button(1300, 481, 170, 130);
    buttons[5] = create_button(1540, 481, 170, 130);
    buttons[6] = create_button(1050, 735, 170, 130);
    buttons[7] = create_button(1300, 735, 170, 130);
    return (buttons);
}

sfVector2f *get_settings_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 8);
    buttons[0] = (sfVector2f){115, 103};
    buttons[1] = (sfVector2f){1032, 270};
    buttons[2] = (sfVector2f){1280, 270};
    buttons[3] = (sfVector2f){1032, 518};
    buttons[4] = (sfVector2f){1280, 518};
    buttons[5] = (sfVector2f){1518, 518};
    buttons[6] = (sfVector2f){1032, 772};
    buttons[7] = (sfVector2f){1280, 772};
    return (buttons);
}

int *get_next_page_settings(all_var *all)
{
    int *next_page = malloc(sizeof(int) * 8);
    next_page[0] = all->var->prevpage;
    next_page[1] = 0;
    next_page[2] = 1;
    next_page[3] = 0;
    next_page[4] = 1;
    next_page[5] = 2;
    next_page[6] = 0;
    next_page[7] = 1;
    return (next_page);
}

sfSprite **reaction_settings_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 8);
    reaction[0] = all->sprites->reaction_small_button;
    reaction[1] = all->sprites->reaction_small_button;
    reaction[2] = all->sprites->reaction_small_button;
    reaction[3] = all->sprites->reaction_small_button;
    reaction[4] = all->sprites->reaction_small_button;
    reaction[5] = all->sprites->reaction_small_button;
    reaction[6] = all->sprites->reaction_small_button;
    reaction[7] = all->sprites->reaction_small_button;
    return (reaction);
}

void buttons_settings(all_var *all)
{
    int res;
    int i = 0;
    int *action = get_next_page_settings(all);
    new_button **buttons = get_settings_button(all);
    sfVector2f *pos = get_settings_pos(all);
    sfSprite **reaction = reaction_settings_button(all);

    while (i < 8) {
        res = is_button_pressed3(buttons[i], all, reaction[i], pos[i]);
        if (res == 2)
            buttons_settings_actions(all, action, i);
        i++;
    }
    free(action);
    free(buttons);
    free(pos);
    free(reaction);
}
