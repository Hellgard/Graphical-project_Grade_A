/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_mainmenu_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 6);
    buttons[0] = create_button(140, 70, 170, 130);
    buttons[1] = create_button(1600, 70, 170, 130);
    buttons[2] = create_button(730, 164, 450, 150);
    buttons[3] = create_button(730, 440, 450, 150);
    buttons[4] = create_button(730, 725, 450, 150);
    buttons[5] = NULL;
    return (buttons);
}

sfVector2f *get_mainmenu_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 5);
    buttons[0] = (sfVector2f){115, 103};
    buttons[1] = (sfVector2f){1580, 101};
    buttons[2] = (sfVector2f){702, 195};
    buttons[3] = (sfVector2f){702, 471};
    buttons[4] = (sfVector2f){702, 756};
    return (buttons);
}

int *get_next_page_mainmenu(all_var *all)
{
    int *next_page = malloc(sizeof(int) * 5);
    next_page[0] = PAGE_PORTADA;
    next_page[1] = PAGE_SETTINGS;
    next_page[2] = PAGE_LEVELS;
    next_page[3] = PAGE_SAVE;
    next_page[4] = PAGE_GAME;
    return (next_page);
}

sfSprite **reaction_mainmenu_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 6);
    reaction[0] = all->sprites->reaction_small_button;
    reaction[1] = all->sprites->reaction_small_button;
    reaction[2] = all->sprites->reaction_big_button;
    reaction[3] = all->sprites->reaction_big_button;
    reaction[4] = all->sprites->reaction_big_button;
    reaction[5] = NULL;
    return (reaction);
}

void buttons_mainmenu(all_var *all)
{
    int res = 0;
    int i = 0;
    int *next_page = get_next_page_mainmenu(all);
    new_button **buttons = get_mainmenu_button(all);
    sfVector2f *pos = get_mainmenu_pos(all);
    sfSprite **reaction = reaction_mainmenu_button(all);
    all->clocks->time_show = sfClock_getElapsedTime(
    all->clocks->clock_show);
    while (i < 5) {
        res = is_button_pressed3(buttons[i], all, reaction[i], pos[i]);
        if (res == 2)
            buttons_mainmenu_actions(all, next_page, i);
        i++;
    }
    if (sfTime_asSeconds(all->clocks->time_show) > 1) {
        all->var->show_msg = false;
        sfClock_restart(all->clocks->clock_show);
    }
    free(next_page);
    free(pos);
    free(reaction);
}
