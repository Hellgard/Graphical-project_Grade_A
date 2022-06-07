/*
** EPITECH PROJECT, 2022
** second_check_quest.c
** File description:
** second_check_quest
*/

#include "rpg.h"

void check_valid(quest_t *quest_list, obj_t *obj)
{
    for (int j = 0; quest_list->elem_quest[j]; j++)
        if (my_strcmp(quest_list->elem_quest[j]->id, obj->linked_id_2) == 0
        && my_strcmp(quest_list->elem_quest[j]->quest_id, obj->linked_id) == 0
        && quest_list->elem_quest[j]->is_actual == 1)
            obj->is = 0;
}

void check_valid_quest(quest_t *quest_list, obj_t *obj)
{
    while (quest_list->prev != NULL)
        quest_list = quest_list->prev;
    for (; quest_list->str != NULL; quest_list = quest_list->next)
        if (my_strcmp(quest_list->id, obj->linked_id) == 0 &&
        quest_list->is_actual == 2)
            obj->is = 0;
}

void check_quest_valid(quest_t *quest_list, obj_t **event,
obj_t **quest, obj_t **boss)
{
    for (int i = 0; event[i]; i++) {
        while (quest_list->prev != NULL)
            quest_list = quest_list->prev;
        for (; quest_list->str != NULL; quest_list = quest_list->next) {
            check_valid(quest_list, event[i]);
        }
    }
    for (int i = 0; boss[i]; i++) {
        while (quest_list->prev != NULL)
            quest_list = quest_list->prev;
        for (; quest_list->str != NULL; quest_list = quest_list->next) {
            check_valid(quest_list, boss[i]);
        }
    }
    for (int i = 0; quest[i]; i++)
        check_valid_quest(quest_list, quest[i]);
}

int check_id(quest_t *quest_list, char *id)
{
    while (quest_list->prev != NULL)
        quest_list = quest_list->prev;
    for (; quest_list->str != NULL; quest_list = quest_list->next) {
        if (my_strcmp(quest_list->id, id) == 0)
            return (1);
    }
    return (0);
}
