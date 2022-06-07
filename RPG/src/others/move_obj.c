/*
** EPITECH PROJECT, 2021
** move_obj.c
** File description:
** handle logic
*/

#include "rpg.h"

void gen_move_x(int id, Game_t *Game, obj_t *obj, int last_move)
{
    int p = 0;
    int pp = 0;
    int j = 0;
    int jj = 0;
    int k = ((Game->scene->map_size_x / Game->scene->tile_size_x) *
    (Game->scene->scale_1));

    if (last_move == id) {
        if (Game->scene->Collision_M[obj->y][obj->x + 1] == '0') {
            p = id * k;
            pp = 0;
            obj->x += 1 * id;
        } else {
            j = id * k;
            jj = 0;
            Game->scene->elems->player[0]->x += id * 1;
        }
    }
    sfSprite_move(obj->sprite, (sfVector2f){p, pp});
    sfSprite_move(Game->scene->elems->player[0]->sprite, (sfVector2f){j, jj});
}

void gen_move_y(int id, Game_t *Game, obj_t *obj, int last_move)
{
    int p = 0;
    int pp = 0;
    int j = 0;
    int jj = 0;
    int k = ((Game->scene->map_size_y / Game->scene->tile_size_y) *
    (Game->scene->scale_2));

    if (last_move == id) {
        if (Game->scene->Collision_M[obj->y][obj->x + 1] == '0') {
            p = id * k;
            pp = 0;
            obj->x += 1 * id;
        } else {
            j = id * k;
            jj = 0;
            Game->scene->elems->player[0]->x += id * 1;
        }
    }
    sfSprite_move(obj->sprite, (sfVector2f){pp, p});
    sfSprite_move(Game->scene->elems->player[0]->sprite, (sfVector2f){j, jj});
}

void move(Game_t *Game, obj_t *obj)
{
    int p = 0;
    int pp = 0;
    int j = 0;
    int jj = 0;
    Game->scene->Collision_M[obj->y][obj->x] = '0';

    gen_move_x(1, Game, obj, Game->last_x);
    gen_move_x(-1, Game, obj, Game->last_x);
    gen_move_y(1, Game, obj, Game->last_y);
    gen_move_y(-1, Game, obj, Game->last_y);
    change_perm(Game, obj);
    Game->scene->Collision_M[obj->y][obj->x] = '4';
    sfSprite_move(obj->sprite, (sfVector2f){p, pp});
    sfSprite_move(Game->scene->elems->player[0]->sprite, (sfVector2f){j, jj});
}

void check_move(all_var *all, obj_t **obj)
{
    for (int i = 0; obj[i]; i++) {
        if (obj[i]->is == 1 && obj[i]->perm->CanMove == 1 &&
        obj[i]->x == all->game->scene->elems->player[0]->x &&
        obj[i]->y == all->game->scene->elems->player[0]->y) {
            move(all->game, obj[i]);
        }
    }
}

void movable_check(all_var *all)
{
    check_move(all, all->game->scene->elems->collision);
    check_move(all, all->game->scene->elems->cutscene);
    check_move(all, all->game->scene->elems->pet);
    check_move(all, all->game->scene->elems->portal);
    check_move(all, all->game->scene->elems->enemy);
    check_move(all, all->game->scene->elems->event);
    check_move(all, all->game->scene->elems->movable);
    check_move(all, all->game->scene->elems->boss);
    check_move(all, all->game->scene->elems->quest);
}
