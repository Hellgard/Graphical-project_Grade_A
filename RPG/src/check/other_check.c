/*
** EPITECH PROJECT, 2021
** other_check.c
** File description:
** check
*/

#include "rpg.h"

void teleport_check(all_var *all)
{
    int x = all->game->scene->elems->player[0]->x;
    int y = all->game->scene->elems->player[0]->y;

    check_teleport(all, all->game->scene->elems->collision, x, y);
    check_teleport(all, all->game->scene->elems->pet, x, y);
    check_teleport(all, all->game->scene->elems->portal, x, y);
    check_teleport(all, all->game->scene->elems->enemy, x, y);
    check_teleport(all, all->game->scene->elems->event, x, y);
    check_teleport(all, all->game->scene->elems->cutscene, x, y);
    check_teleport(all, all->game->scene->elems->movable, x, y);
}

void check_random(Game_t *Game, obj_t *obj)
{
    int j;

    if (sfTime_asSeconds(Game->Time) > 3 && Game->on_attack == 0) {
        j = rand() % 10;
        if (j <= 5) {
            Game->on_attack = 1;
            sfMusic_play(Game->battle);
            Game->attack_id = my_getnbr(obj->linked_id);
        }
    }
}

void check_attack(all_var *all, obj_t **obj)
{
    all->game->Time = sfClock_getElapsedTime(all->game->clock);
    int j;

    for (int i = 0; obj[i]; i++) {
        if (obj[i]->is == 1 && obj[i]->perm->CanAttack == 1 &&
        is_in_zone(obj[i], all->game->scene) == 1) {
            check_random(all->game, obj[i]);
        }
    }
}

void attack_check(all_var *all)
{
    check_attack(all, all->game->scene->elems->collision);
    check_attack(all, all->game->scene->elems->cutscene);
    check_attack(all, all->game->scene->elems->pet);
    check_attack(all, all->game->scene->elems->player);
    check_attack(all, all->game->scene->elems->portal);
    check_attack(all, all->game->scene->elems->enemy);
    check_attack(all, all->game->scene->elems->event);
    check_attack(all, all->game->scene->elems->movable);
}

void change_perm(Game_t *Game, obj_t *obj)
{
    if (Game->scene->Collision_M[obj->y + 1][obj->x] == '1' &&
    (Game->scene->Collision_M[obj->y][obj->x + 1] == '1' ||
    Game->scene->Collision_M[obj->y][obj->x - 1] == '1'))
        obj->perm->CanGoOver = 0;
    else if (Game->scene->Collision_M[obj->y - 1][obj->x] == '1' &&
    (Game->scene->Collision_M[obj->y][obj->x + 1] == '1' ||
    Game->scene->Collision_M[obj->y][obj->x - 1] == '1'))
        obj->perm->CanGoOver = 0;
}
