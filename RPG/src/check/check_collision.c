/*
** EPITECH PROJECT, 2022
** check_collision.c
** File description:
** Function that manage collision
*/

#include "rpg.h"

int check_collision(char ind, obj_t *obj)
{
    if (compare_char(ind, obj->id) == 0)
        return (0);
    return (1);
}

int compare(char ind, obj_t  *obj)
{
    if (check_collision(ind, obj) == 0) {
        if (obj->perm->CanGoOver == 1)
            return (0);
        else
            return (1);
    }
    return (3);
}

int compare_ind(char ind, elem_t *elems, scene_t *Scene)
{
    if (ind == '0')
        return 0;
    if (compare(ind, elems->boss[0]) != 3)
        return (compare(ind, elems->boss[0]));
    if (compare(ind, elems->quest[0]) != 3)
        return (compare(ind, elems->quest[0]));
    if (compare(ind, elems->collision[0]) != 3)
        return (compare(ind, elems->collision[0]));
    if (compare(ind, elems->cutscene[0]) != 3)
        return (compare(ind, elems->cutscene[0]));
    if (compare(ind, elems->enemy[0]) != 3)
        return (compare(ind, elems->enemy[0]));
    if (compare(ind, elems->event[0]) != 3)
        return (compare(ind, elems->event[0]));
    if (compare(ind, elems->movable[0]) != 3)
        return (compare(ind, elems->movable[0]));
    if (compare(ind, elems->pet[0]) != 3)
        return (compare(ind, elems->pet[0]));
    if (compare(ind, elems->portal[0]) != 3)
        return (compare(ind, elems->portal[0]));
}
