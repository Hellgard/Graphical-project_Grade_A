/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_prevbuttons_prev_battle_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 3);
    buttons[0] = create_button(1170, 670, 380, 125);
    buttons[1] = create_button(1550, 670, 380, 125);
    buttons[2] = create_button(1170, 843, 800, 125);
    return (buttons);
}

sfVector2f *get_prevbuttons_prev_battle_button_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 3);
    buttons[0] = (sfVector2f){1200, 717};
    buttons[1] = (sfVector2f){1540, 717};
    buttons[2] = (sfVector2f){702, 471};
    return (buttons);
}

sfSprite **reaction_prevbuttons_prev_battle_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 3);
    reaction[0] = all->sprites->reaction_battle;
    reaction[1] = all->sprites->reaction_battle;
    reaction[2] = NULL;
    return (reaction);
}

int *get_next_page_prev_battle(all_var *all)
{
    int *next_page = malloc(sizeof(int) * 3);
    next_page[0] = PAGE_BATTLE;
    next_page[1] = PAGE_INVENTORY;
    next_page[2] = PAGE_GAME;
    return (next_page);
}

void buttons_prev_battle(all_var *all)
{
    int res;
    int i = 0;
    int *next_page = get_next_page_prev_battle(all);
    new_button **buttons = get_prevbuttons_prev_battle_button(all);
    sfVector2f *pos = get_prevbuttons_prev_battle_button_pos(all);
    sfSprite **reaction = reaction_prevbuttons_prev_battle_button(all);

    while (i < 3) {
        res = is_button_pressed3(buttons[i], all, reaction[i], pos[i]);
        if (res == 2) {
            buttons_prevbattle_actions(all, next_page, i);
        }
        i++;
    }
    free(buttons);
    free(pos);
    free(reaction);
}
