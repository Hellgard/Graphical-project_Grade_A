/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_selection_player_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 4);
    buttons[0] = create_button(140, 70, 170, 130);
    buttons[1] = create_button(425, 454, 170, 130);
    buttons[2] = create_button(868, 454, 170, 130);
    buttons[3] = create_button(1317, 454, 170, 130);
    return (buttons);
}

sfVector2f *get_selection_player_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 4);
    buttons[0] = (sfVector2f){115, 103};
    buttons[1] = (sfVector2f){402, 490};
    buttons[2] = (sfVector2f){845, 490};
    buttons[3] = (sfVector2f){1297, 490};
    return (buttons);
}

int *get_next_page_selection_player(all_var *all)
{
    int *next_page = malloc(sizeof(int) * 4);
    next_page[0] = 1;
    next_page[1] = 0;
    next_page[2] = 1;
    next_page[3] = 2;
    return (next_page);
}

sfSprite **reaction_selection_player_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 4);
    reaction[0] = all->sprites->reaction_small_button;
    reaction[1] = all->sprites->reaction_small_button;
    reaction[2] = all->sprites->reaction_small_button;
    reaction[3] = all->sprites->reaction_small_button;
    return (reaction);
}

void buttons_selection_player(all_var *all)
{
    int res;
    int i = 0;
    int *next_page = get_next_page_selection_player(all);
    new_button **buttons = get_selection_player_button(all);
    sfVector2f *pos = get_selection_player_pos(all);
    sfSprite **reaction = reaction_selection_player_button(all);

    while (i < 4) {
        res = is_button_pressed3(buttons[i], all, reaction[i], pos[i]);
        if (res == 2 & i == 0)
            all->var->page = next_page[i];
        else if (res == 2 && i != 0) {
            all->var->player = next_page[i];
            all->var->page = PAGE_MAINMENU;
        }
        i++;
    }
    free(next_page);
    free(buttons);
    free(pos);
    free(reaction);
}
