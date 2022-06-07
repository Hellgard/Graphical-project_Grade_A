/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void buttons_prevbattle_actions(all_var *all, int *next_page, int i)
{
    all->var->prevpage = PAGE_PREV_BATTLE;
    all->var->page = next_page[i];

    if (i == 2) {
        sfClock_restart(all->game->clock);
        all->game->on_attack = 0;
    }
}

void ext_buttons_save_actions(all_var *all, int *next_page, int i)
{
    printf("current: %d, slot: %d\n", all->var->current_game, i);
    if (all->var->prevpage != PAGE_PAUSE) {
        if (all->var->current_game != -1)
            save_all(all);
        all->var->current_game = i - 1;
        load_all(all);
    }
    else {
        all->var->current_game = i - 1;
        save_all(all);
    }
}

void update_list(all_var *all, int i, int *next_page)
{
    if (all->var->list_saved[i - 1] == 0) {
        all->var->current_game = i - 1;
        load_all(all);
        all->var->list_name_saved[i - 1] = my_strdup(all->var->player_name);
        all->var->list_saved[i - 1] = 1;
    }
    else
        ext_buttons_save_actions(all, next_page, i);
}

void buttons_save_actions(all_var *all, int *next_page, int i)
{
    if (i == 0)
        all->var->page = all->var->prevpage;
    if (i >= 1 && i <= 3)
        update_list(all, i, next_page);
    if ( i == 7) {
        if (all->var->autosave == true)
            all->var->autosave = false;
        else
            all->var->autosave = true;
    }
    //if (all->var->current_game == (i - 1)) {
    //    printf("iguales\n");
    //    all->var->current_game = -1;
    //}
    if (i >= 4 && i <= 6) {
        all->var->page = PAGE_CONFIRMATION;
        all->var->item_to_delete = i - 4;
    }
}

void buttons_settings_actions(all_var *all, int *action, int i)
{
    if (i == 0)
        all->var->page = action[i];
    if (i >= 1 && i <= 2)
        all->var->sound_on = action[i];
    if (i >= 3 && i <= 5)
        all->var->prev_fps = action[i];
    if (i >= 6 && i <= 7)
        all->var->quality = action[i];
}
