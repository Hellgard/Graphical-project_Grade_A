/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void buttons_mainmenu_actions(all_var *all,  int *next_page, int i)
{
    if (i < 4 || (i == 4 && all->var->level != -1 && all->var->player != -1)) {
            all->var->prevpage = all->var->page;
            all->var->page = next_page[i];
    }
    if (i == 4 && (all->var->level == -1 || all->var->player == -1)) {
        all->var->show_msg = true;
        all->clocks->clock_show;
    }
}

void buttons_battle_actions(all_var *all, int i)
{
    switch (i) {
        case 0:
            attack(all->game->player->competencies->first,
            all->game->enemy[all->game->attack_id], all);
            break;
        case 1:
            attack(all->game->player->competencies->second,
            all->game->enemy[all->game->attack_id], all);
            break;
        case 2:
            attack(all->game->player->competencies->third,
            all->game->enemy[all->game->attack_id], all);
            break;
        case 3:
            attack(all->game->player->competencies->fourth,
            all->game->enemy[all->game->attack_id], all);
            break;
    }
    all->game->turn_combat = 1;
    all->var->page = PAGE_PREV_BATTLE;
    sfClock_restart(all->game->clock_combat);
}

void buttons_confirmation_actions(all_var *all, int i)
{
    if (i == 0) {
        delete_all(all);
        all->var->current_game = -1;
        all->var->list_saved[all->var->item_to_delete] = 0;
        reset_game(all);
        all->var->page = PAGE_SAVE;
    }
    else if (i == 1)
        all->var->page = PAGE_SAVE;
}

void buttons_inventory_actions(all_var *all, int inv_page, int i)
{
    if (i <= 1 && inv_page > 0) {
        all->var->inventory_page--;
        all->var->item_selected = -1;
        all->var->easteregg_inventory_page = 0;
    }
    if (i >= 2 && i <= 3 && inv_page < 3) {
        all->var->inventory_page++;
        all->var->item_selected = -1;
        all->var->easteregg_inventory_page = 0;
    }
    if (i == 4)
        all->var->easteregg_inventory_page++;
    if (i == 5)
        all->var->page = all->var->prevpage;
}

void buttons_pause_actions(all_var *all, int *next_page, int i)
{
    if (i != 2) {
        all->var->prevpage = all->var->page;
        all->var->page = next_page[i];
    }
    if (i == 2) {
        if (all->var->current_game == -1) {
            all->var->prevpage = all->var->page;
            all->var->page = next_page[i];
        }
        else
            save_all(all);
    }
}
