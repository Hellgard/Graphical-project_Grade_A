/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_pause_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 4);
    buttons[0] = create_button(1600, 70, 170, 130);
    buttons[1] = create_button(730, 164, 450, 150);
    buttons[2] = create_button(730, 440, 450, 150);
    buttons[3] = create_button(730, 725, 450, 150);
    return (buttons);
}

sfVector2f *get_pause_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 4);
    buttons[0] = (sfVector2f){1580, 101};
    buttons[1] = (sfVector2f){702, 195};
    buttons[2] = (sfVector2f){702, 471};
    buttons[3] = (sfVector2f){702, 756};
    return (buttons);
}

int *get_next_page_pause(all_var *all)
{
    int *next_page = malloc(sizeof(int) * 4);
    next_page[0] = PAGE_GAME;
    next_page[1] = PAGE_SETTINGS;
    next_page[2] = PAGE_SAVE;
    next_page[3] = PAGE_MAINMENU;
    return (next_page);
}

sfSprite **reaction_pause_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 4);
    reaction[0] = NULL;
    reaction[1] = all->sprites->reaction_big_button;
    reaction[2] = all->sprites->reaction_big_button;
    reaction[3] = all->sprites->reaction_big_button;
    return (reaction);
}

void buttons_pause(all_var *all)
{
    int res = 0;
    int i = 0;
    int *next_page = get_next_page_pause(all);
    new_button **buttons = get_pause_button(all);
    sfVector2f *pos = get_pause_pos(all);
    sfSprite **reaction = reaction_pause_button(all);

    while (i < 4) {
        res = is_button_pressed3(buttons[i], all, reaction[i], pos[i]);
        if (res == 2)
            buttons_pause_actions(all, next_page, i);
        i++;
    }
    free(next_page);
    free(pos);
    free(reaction);
}
