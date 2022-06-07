/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

obj_t *valid_boss_death(int i, int j, all_var *all)
{
    if (my_strcmp(all->game->quest_list->elem_quest[j]->id,
    all->game->enemy[i]->id) == 0) {
        if (all->game->quest_list->elem_quest[j]->is_actual == 1) {
            all->game->enemy[i]->life = 0;
            all->game->enemy[i]->li = 0;
        }
    }
}

void check_boss_load(all_var *all, combat_t **enemy)
{
    while (all->game->quest_list->prev != NULL)
        all->game->quest_list = all->game->quest_list->prev;
    for (int i = 0; all->game->quest_list->str && my_strcmp(all->game->quest_list->id, "0") != 0; all->game->quest_list = all->game->quest_list->next);
    if (all->game->quest_list->str != NULL && my_strcmp(all->game->quest_list->id, "0") == 0) {
        for (int j = 0; all->game->quest_list->elem_quest[j]; j++) {
            for (int i = 0; enemy[i]; i++)
                valid_boss_death(i, j, all);
        }
    }
}
