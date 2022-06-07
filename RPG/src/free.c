/*
** EPITECH PROJECT, 2021
** free.c
** File description:
** free
*/

#include "rpg.h"

void need_free(obj_t **obj, int i)
{
    int j = 0;
    free(obj[i]->name);

    if (obj[i]->perm->Texture == 1) {
        free(obj[i]->texture);
        sfSprite_destroy(obj[i]->sprite);
    }
    if (obj[i]->perm->Text == 1) {
        for (; obj[i]->Text[j]; j++);
            sfText_destroy(obj[i]->Text[j]);
        for (j = 0; obj[i]->texts[j]; j++);
            free(obj[i]->texts[j]);
    }
    free(obj[i]->linked_id);
    free(obj[i]->linked_id_2);
    free(obj[i]->loot);
    free(obj[i]->perm);
}

void free_elem(obj_t **obj)
{
    for (int i = 0; obj[i]; i++) {
        if (obj[i]->is == 1) {
            need_free(obj, i);
        }
    }
}

void free_objects(scene_t *scene)
{
    free_elem(scene->elems->boss);
    free_elem(scene->elems->quest);
    free_elem(scene->elems->player);
    free_elem(scene->elems->portal);
    free_elem(scene->elems->pet);
    free_elem(scene->elems->enemy);
    free_elem(scene->elems->event);
    free_elem(scene->elems->collision);
    free_elem(scene->elems->cutscene);
    free_elem(scene->elems->movable);
}

void free_scene(scene_t *scene)
{
    free(scene->id);
    free(scene->texture);
    sfSprite_destroy(scene->sprite);

    for (int i = 0; scene->Collision_M[i]; i++)
        free(scene->Collision_M[i]);
    for (int i = 0; scene->Event_M[i]; i++)
        free(scene->Event_M[i]);
    free_objects(scene);
    free(scene->elems);
    sfMusic_destroy(scene->ambiance);
    free(scene);
}
