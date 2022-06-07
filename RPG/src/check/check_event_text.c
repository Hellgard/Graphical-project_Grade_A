/*
** EPITECH PROJECT, 2022
** check_event.c
** File description:
** Function that manage npc text
*/

#include "rpg.h"

void text_event(obj_t *obj, char event)
{
    if (my_strcmp(obj->loot, "none") != 0) {
        if (compare_char(event, obj->texts[0][0]) == 0
        && obj->texts[obj->i + 1] &&
        obj->texts[obj->i + 2]) {
            obj->i += 1;
        }
        return;
    }
    if (compare_char(event, obj->texts[0][0]) == 0 && obj->texts[obj->i + 1])
        obj->i += 1;
}

void check_event_text(obj_t **obj, char event)
{
    for (int i = 0; obj[i]; i++) {
        if (obj[i]->is == 1 && obj[i]->perm->Text == 1) {
            text_event(obj[i], event);
        }
    }
}

void special_item(all_var *all)
{
    for (; all->game->quest_list->prev;
    all->game->quest_list = all->game->quest_list->prev);
    for (; all->game->quest_list->str != NULL;
    all->game->quest_list = all->game->quest_list->next) {
        if (my_strcmp(all->game->quest_list->id, "2") == 0)
            break;
    }
    if (all->game->quest_list->str != NULL &&
    all->game->quest_list->is_actual != 2) {
        add_element_inventory(all, "./itemprop/armour/sword_1", 1);
        all->game->quest_list->is_actual = 2;
    }
}

void secret_event(all_var *all, obj_t *obj, char event)
{
    if (check_id(all->game->quest_list, "2") == 1 &&
    my_strcmp(all->game->scene->id, "2") == 0 && obj->x == 1
    && obj->y == 20 && compare_char(event, 'f') == 0)
        special_item(all);
}

void event_text(scene_t *scene, char event)
{
    check_event_text(scene->elems->player, event);
    check_event_text(scene->elems->portal, event);
    check_event_text(scene->elems->pet, event);
    check_event_text(scene->elems->collision, event);
    check_event_text(scene->elems->cutscene, event);
    check_event_text(scene->elems->enemy, event);
    check_event_text(scene->elems->event, event);
    check_event_text(scene->elems->movable, event);
    check_event_text(scene->elems->boss, event);
    check_event_text(scene->elems->quest, event);
}
