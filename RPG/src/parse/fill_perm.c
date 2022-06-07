/*
** EPITECH PROJECT, 2021
** fill_perm.c
** File description:
** fill
*/

#include "rpg.h"

obj_t **malloc_elem(char *ind, char **how_many)
{
    obj_t **elem;
    int i = 0;
    int number;

    for (; (my_strcmp(how_many[i], ind) != 0); i += 2);
    number = my_getnbr(how_many[i + 1]);
    elem = malloc(sizeof(obj_t *) * (number + 1));
    for (i = 0; i < (number + 1); i++)
        (elem)[i] = malloc(sizeof(obj_t));
    elem[number] = NULL;
    (elem)[0]->i = 0;
    return elem;
}

obj_t **fill_perm_gen(obj_t **obj, char **parse, int i, char ind)
{
    char **param = parse_elem(parse, ind, i);

    for (int j = 0; obj[j]; j++) {
        obj[j]->perm->Text = my_getnbr(param[2]);
        obj[j]->perm->Texture = my_getnbr(param[3]);
        obj[j]->perm->Animation = my_getnbr(param[4]);
        obj[j]->perm->CanMove = my_getnbr(param[5]);
        obj[j]->perm->CanGoOver = my_getnbr(param[6]);
        obj[j]->perm->CanInteractWith = my_getnbr(param[7]);
        obj[j]->perm->linked_id = my_getnbr(param[8]);
        obj[j]->perm->CanAttack = my_getnbr(param[9]);
        obj[j]->perm->Teleport = my_getnbr(param[10]);
        obj[j]->perm->isBoss = my_getnbr(param[11]);
        obj[j]->perm->isQuest = my_getnbr(param[12]);
        obj[j]->perm->linked_id_2 = my_getnbr(param[13]);
        obj[j]->name = my_strdup(param[1]);
    }
    return obj;
}

obj_t **malloc_perm(obj_t **obj)
{
    for (int i = 0; obj[i]; i++) {
        obj[i]->perm = malloc(sizeof(perm_t));
    }
    return obj;
}

void fill_perms(char **pars, int i, scene_t *s)
{
    s->elems->player = malloc_perm(s->elems->player);
    s->elems->pet = malloc_perm(s->elems->pet);
    s->elems->event = malloc_perm(s->elems->event);
    s->elems->collision = malloc_perm(s->elems->collision);
    s->elems->movable = malloc_perm(s->elems->movable);
    s->elems->portal = malloc_perm(s->elems->portal);
    s->elems->cutscene = malloc_perm(s->elems->cutscene);
    s->elems->enemy = malloc_perm(s->elems->enemy);
    s->elems->boss = malloc_perm(s->elems->boss);
    s->elems->quest = malloc_perm(s->elems->quest);
    s->elems->player = fill_perm_gen(s->elems->player, pars, i, 'P');
    s->elems->pet = fill_perm_gen(s->elems->pet, pars, i, 'S');
    s->elems->event = fill_perm_gen(s->elems->event, pars, i, '2');
    s->elems->collision = fill_perm_gen(s->elems->collision, pars, i, '1');
    s->elems->movable = fill_perm_gen(s->elems->movable, pars, i, '4');
    s->elems->portal = fill_perm_gen(s->elems->portal, pars, i, '#');
    s->elems->cutscene = fill_perm_gen(s->elems->cutscene, pars, i, 'C');
    s->elems->enemy = fill_perm_gen(s->elems->enemy, pars, i, '3');
    s->elems->boss = fill_perm_gen(s->elems->boss, pars, i, 'B');
    s->elems->quest = fill_perm_gen(s->elems->quest, pars, i, 'Q');
}
