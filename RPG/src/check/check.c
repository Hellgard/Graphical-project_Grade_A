/*
** EPITECH PROJECT, 2021
** check.c
** File description:
** check
*/

#include "rpg.h"

void check_elem(obj_t **obj, scene_t *scene)
{
    int pos_x;
    int pos_y;

    for (int i = 0; obj[i]; i++) {
        if (obj[i]->is == 1 && (obj[i]->perm->Texture == 1)) {
            pos_x = obj[i]->x * (scene->map_size_x / scene->tile_size_x) *
            scene->scale_1;
            pos_y = obj[i]->y * (scene->map_size_y / scene->tile_size_y) *
            scene->scale_2;
            pos_y -= (scene->map_size_y / scene->tile_size_y) *
            (scene->scale_2);
            obj[i]->sprite = obj_create(pos_x, pos_y, obj[i]->texture);
            sfVector2f scale = {scene->scale_1, scene->scale_2};
            sfSprite_setScale(obj[i]->sprite, scale);
        }
    }
}

void check_elem_text(obj_t **obj, scene_t *scene)
{
    int pos_x;
    int pos_y;

    for (int i = 0; obj[i]; i++) {
        obj[i]->i = 0;
        if (obj[i]->is == 1 && obj[i]->perm->Text == 1) {
            pos_x = obj[i]->x * (scene->map_size_x / scene->tile_size_x) *
            scene->scale_1;
            pos_y = obj[i]->y * (scene->map_size_y / scene->tile_size_y) *
            scene->scale_2;
            pos_y -= (scene->map_size_y / scene->tile_size_y) *
            (scene->scale_2);
            create_txt(pos_x, pos_y, obj[i]);
        }
    }
}

void check_draw(all_var *all, obj_t **obj)
{
    for (int i = 0; obj[i]; i++) {
        if (obj[i]->is == 1 && obj[i]->perm->Texture == 1) {
            sfRenderWindow_drawSprite(all->windows->window,
            obj[i]->sprite, NULL);
        }
    }
}

void add_to_list(quest_t *quest_list, obj_t *obj)
{
    for (; quest_list->str != NULL; quest_list = quest_list->next);
    quest_list->id = my_strdup(obj->linked_id);
    quest_list->str = my_strdup(obj->texts[obj->i]);
    quest_list->how_many = my_getnbr(obj->linked_id_2);
    quest_list->is_actual = 1;
    quest_list->state = 0;
    quest_list->i = 0;
    quest_list->elem_quest = malloc(sizeof(elem_quest_t *) *
    quest_list->how_many);
    quest_list->elem_quest[0] = NULL;
    quest_list->next = malloc(sizeof(quest_t));
    quest_list->next->prev = quest_list;
    quest_list = quest_list->next;
    quest_list->str = NULL;
    quest_list->next = NULL;
}
