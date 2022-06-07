/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_game_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 1);
    buttons[0] = create_button(1730, 55, 100, 100);
    return (buttons);
}

sfVector2f *get_game_button_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 1);
    buttons[0] = (sfVector2f){0, 0};
    return (buttons);
}

sfSprite **reaction_game_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 1);
    reaction[0] = NULL;
    return (reaction);
}

void buttons_game(all_var *all)
{
    int res;
    int i = 0;
    new_button **buttons = get_game_button(all);
    sfVector2f *pos = get_game_button_pos(all);
    sfSprite **reaction = reaction_game_button(all);

    while (i < 1) {
        res = is_button_pressed3(buttons[i], all, NULL, pos[i]);
        if (res == 2 && i == 0)
            all->var->page = PAGE_PAUSE;
        i++;
    }
    free(buttons);
    free(pos);
    free(reaction);
}
