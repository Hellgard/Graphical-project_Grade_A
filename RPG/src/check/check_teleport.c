/*
** EPITECH PROJECT, 2022
** check_teleport.c
** File description:
** check_teleport
*/

#include "rpg.h"

sfVector2i *maps_pos(void)
{
    sfVector2i *pos = malloc(sizeof(sfVector2i) * 11);

    pos[0] = (sfVector2i){3, 42};
    pos[1] = (sfVector2i){2, 2};
    pos[2] = (sfVector2i){43, 34};
    pos[3] = (sfVector2i){41, 6};
    pos[4] = (sfVector2i){2, 20};
    pos[5] = (sfVector2i){21, 1};
    pos[6] = (sfVector2i){33, 9};
    pos[7] = (sfVector2i){29, 25};
    pos[8] = (sfVector2i){12, 1};
    pos[9] = (sfVector2i){20, 1};
    return (pos);
}

int change_map(char *actual_id, char *next_id)
{
    if (my_strcmp(actual_id, "7") == 0 && my_strcmp(next_id, "2") == 0)
        return (0);
    if (my_strcmp(actual_id, "5") == 0 && my_strcmp(next_id, "2") == 0)
        return (1);
    if (my_strcmp(actual_id, "3") == 0 && my_strcmp(next_id, "2") == 0)
        return (2);
    if (my_strcmp(actual_id, "9") == 0 && my_strcmp(next_id, "2") == 0)
        return (3);
    if (my_strcmp(actual_id, "8") == 0 && my_strcmp(next_id, "7") == 0)
        return (4);
    if (my_strcmp(actual_id, "6") == 0 && my_strcmp(next_id, "5") == 0)
        return (5);
    if (my_strcmp(actual_id, "4") == 0 && my_strcmp(next_id, "3") == 0)
        return (6);
    if (my_strcmp(actual_id, "10") == 0 && my_strcmp(next_id, "9") == 0)
        return (7);
    if (my_strcmp(actual_id, "2") == 0 && my_strcmp(next_id, "1") == 0)
        return (8);
    if (my_strcmp(actual_id, "u") == 0 && my_strcmp(next_id, "2") == 0)
        return (9);
    return (-1);
}

void init_teleport(all_var *all, char *next_id)
{
    sfVector2i *pos = maps_pos();
    int i = change_map(all->var->actual_id, next_id);
    int x;
    int y;
    sfVector2f posi;

    if (i != -1) {
        all->game->scene->elems->player[0]->x = pos[i].x;
        all->game->scene->elems->player[0]->y = pos[i].y;
    }
    x = ((all->game->scene->elems->player[0]->x) *
    (all->game->scene->map_size_x / all->game->scene->tile_size_x) *
    all->game->scene->scale_1);
    y = ((all->game->scene->elems->player[0]->y) *
    (all->game->scene->map_size_y / all->game->scene->tile_size_y) *
    all->game->scene->scale_2);
    all->game->scene->elems->player[0]->pos.x = x;
    all->game->scene->elems->player[0]->pos.y = y;
    posi = all->game->scene->elems->player[0]->pos;
    all->game->scene->elems->player[0]->pos_target = posi;
}

int is_on_teleport(obj_t *obj, all_var *all, int x, int y)
{
    char *id;

    if (obj->is == 1 && obj->perm->Teleport == 1) {
        if (obj->x == x && obj->y == y) {
            sfMusic_setVolume(all->game->trans_scene, 100);
            sfMusic_play(all->game->trans_scene);
            id = my_strdup(obj->linked_id);
            fade_in(all);
            free_scene(all->game->scene);
            all->game->scene = create_scene(all, id, all->game->parse);
            init_teleport(all, id);
            sfSprite_setPosition(all->game->scene->elems->player[0]->sprite,
            all->game->scene->elems->player[0]->pos);
            all->var->actual_id = my_strdup(id);
            check_quest_valid(all->game->quest_list,
            all->game->scene->elems->event, all->game->scene->elems->quest,
            all->game->scene->elems->boss);
            return 1;
        }
    }
    return 0;
}

void check_teleport(all_var *all, obj_t **obj, int x, int y)
{
    for (int i = 0; obj[i]; i++)
        if (is_on_teleport(obj[i], all, x, y) == 1)
            break;
}
