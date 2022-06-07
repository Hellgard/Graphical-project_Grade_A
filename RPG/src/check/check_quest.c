/*
** EPITECH PROJECT, 2022
** check_quest.c
** File description:
** check_quest
*/

#include "rpg.h"

void check_quest(all_var *all, obj_t *obj)
{
    if ((obj->perm->isQuest == 1 && obj->texts[obj->i + 1] == NULL) ||
    (obj->perm->isQuest == 1 && my_strcmp(obj->loot, "none") != 0 &&
    obj->texts[obj->i + 2] == NULL)) {
        if (check_id(all->game->quest_list, obj->linked_id) == 0)
            add_to_list(all->game->quest_list, obj);
    }
    if (obj->perm->isQuest != 1 && obj->texts[obj->i + 1] == NULL &&
    my_strcmp(obj->linked_id, "none") != 0) {
        if (check_id(all->game->quest_list, obj->linked_id) == 1) {
            add_to_quest(all->game->quest_list, obj);
            check_boss(all, obj);
        }
    }
}

void check_quest_loot(all_var *all, obj_t *obj)
{
    int i;

    while (all->game->quest_list->prev != NULL)
        all->game->quest_list = all->game->quest_list->prev;
    for (; all->game->quest_list->str != NULL;
    all->game->quest_list = all->game->quest_list->next)
        if (my_strcmp(all->game->quest_list->id, obj->linked_id) == 0)
            break;
    for (i = 0; obj->texts[i]; i++);
    if (all->game->quest_list->str != NULL &&
    all->game->quest_list->state == all->game->quest_list->how_many) {
        if (my_strcmp(obj->loot, "none") != 0 &&
        all->game->quest_list->is_actual != 2) {
            obj->i = i - 1;
            add_element_inventory(all, obj->loot, 1);
        }
        all->game->quest_list->is_actual = 2;
    }
}

void add_to_quest(quest_t *quest, obj_t *obj)
{
    while (quest->prev != NULL)
        quest = quest->prev;
    for (; my_strcmp(quest->id, obj->linked_id) != 0;
    quest = quest->next);
    for (int i = 0; quest->elem_quest[i]; i++) {
        if (my_strcmp(quest->elem_quest[i]->id, obj->linked_id_2) == 0)
            return;
    }
    quest->elem_quest[quest->i] = malloc(sizeof(elem_quest_t));
    quest->elem_quest[quest->i]->id = my_strdup(obj->linked_id_2);
    quest->elem_quest[quest->i]->quest_id = my_strdup(obj->linked_id);
    if (obj->perm->isBoss == 1) {
        quest->elem_quest[quest->i]->is_actual = 0;
    } else {
        quest->state += 1;
        quest->elem_quest[quest->i]->is_actual = 1;
    }
    quest->i += 1;
    quest->elem_quest[quest->i] = NULL;
}

void check_boss(all_var *all, obj_t *obj)
{
    if (obj->perm->isBoss == 1) {
        all->game->on_attack = 1;
        sfMusic_play(all->game->battle);
        all->game->attack_id = my_getnbr(obj->linked_id_2);
        obj->i -= 3;
    }
}
