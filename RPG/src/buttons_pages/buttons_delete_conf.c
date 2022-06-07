/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_confirmation_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 2);
    buttons[0] = create_button(496, 649, 382, 194);
    buttons[1] = create_button(1023, 652, 382, 194);
    return (buttons);
}

sfVector2f *get_confirmation_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 2);
    buttons[0] = (sfVector2f){1580, 101};
    buttons[1] = (sfVector2f){702, 195};
    return (buttons);
}

int *get_next_page_confirmation(all_var *all)
{
    int *next_page = malloc(sizeof(int) * 2);
    next_page[0] = PAGE_GAME;
    next_page[1] = PAGE_SETTINGS;
    return (next_page);
}

sfSprite **reaction_confirmation_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 2);
    reaction[0] = NULL;
    reaction[1] = NULL;
    return (reaction);
}

void buttons_confirmation(all_var *all)
{
    int res = 0;
    int i = 0;
    int *next_page = get_next_page_confirmation(all);
    new_button **buttons = get_confirmation_button(all);
    sfVector2f *pos = get_confirmation_pos(all);
    sfSprite **reaction = reaction_confirmation_button(all);

    while (i < 2) {
        res = is_button_pressed3(buttons[i], all, reaction[i], pos[i]);
        if (res == 2)
            buttons_confirmation_actions(all, i);
        i++;
    }
    free(next_page);
    free(pos);
    free(reaction);
}
