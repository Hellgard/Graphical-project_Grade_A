/*
** EPITECH PROJECT, 2022
** key_check.c
** File description:
** Function that manage keys input
*/

#include "rpg.h"

int left(scene_t *Scene, obj_t **obj, Game_t *Game)
{
    int p = 0;
    char ind;
    int j = 0;
    int k = 1;

    for (int i = 0; obj[i]; i++) {
        ind = Scene->Collision_M[obj[i]->y][obj[i]->x - 1];
        k = compare_ind(ind, Scene->elems, Scene);
        if (k == 0) {
            p = -((Scene->map_size_x / Scene->tile_size_x) * (Scene->scale_1));
            obj[i]->x -= 1;
            Game->last_x = -1;
            Game->last_y = 0;
            Scene->select_character.top = 800;
            obj[i]->pos_target.x = ((obj[i]->x) * (Scene->map_size_x /
            Scene->tile_size_x) * Scene->scale_1);
        } else
            sfMusic_play(Game->collision);
    }
    return p;
}

int up(scene_t *Scene, obj_t **obj, Game_t *Game)
{
    int p = 0;
    char ind;
    int j = 0;
    int k = 1;

    for (int i = 0; obj[i]; i++) {
        ind = Scene->Collision_M[obj[i]->y - 1][obj[i]->x];
        k = compare_ind(ind, Scene->elems, Scene);
        if (k == 0) {
            p = -((Scene->map_size_y / Scene->tile_size_y) * (Scene->scale_2));
            obj[i]->y -= 1;
            Game->last_x = 0;
            Game->last_y = -1;
            Scene->select_character.top = 1600;
            obj[i]->pos_target.y = ((obj[i]->y - 1) * (Scene->map_size_y /
            Scene->tile_size_y) * Scene->scale_2);
        } else
            sfMusic_play(Game->collision);
    }
    return p;
}

int down(scene_t *Scene, obj_t **obj, Game_t *Game)
{
    int p = 0;
    char ind;
    int j = 0;
    int k = 1;

    for (int i = 0; obj[i]; i++) {
        ind = Scene->Collision_M[obj[i]->y + 1][obj[i]->x];
        k = compare_ind(ind, Scene->elems, Scene);
        if (k == 0) {
            p = ((Scene->map_size_y / Scene->tile_size_y) * (Scene->scale_2));
            obj[i]->y += 1;
            Game->last_x = 0;
            Game->last_y = 1;
            Scene->select_character.top = 400;
            obj[i]->pos_target.y = ((obj[i]->y - 1) * (Scene->map_size_y /
            Scene->tile_size_y) * Scene->scale_2);
        } else
            sfMusic_play(Game->collision);
    }
    return p;
}

int right(scene_t *Scene, obj_t **obj, Game_t *Game)
{
    int p = 0;
    char ind;
    int j = 0;
    int k = 1;

    for (int i = 0; obj[i]; i++) {
        ind = Scene->Collision_M[obj[i]->y][obj[i]->x + 1];
        k = compare_ind(ind, Scene->elems, Scene);
        if (k == 0) {
            p = (Scene->map_size_x / Scene->tile_size_x) * (Scene->scale_1);
            obj[i]->x += 1;
            Game->last_x = 1;
            Game->last_y = 0;
            Scene->select_character.top = 1200;
            obj[i]->pos_target.x = ((obj[i]->x) * (Scene->map_size_x /
            Scene->tile_size_x) * Scene->scale_1);
        } else
            sfMusic_play(Game->collision);
    }
    return p;
}

void key_check(all_var *all)
{
    int x = 0;
    int y = 0;

    all->clocks->time_event = sfClock_getElapsedTime(all->clocks->clock_event);
    if (sfTime_asSeconds(all->clocks->time_event) > 0.08) {
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
            x = right(all->game->scene,
            all->game->scene->elems->player, all->game);
        if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
            x = left(all->game->scene,
            all->game->scene->elems->player, all->game);
        if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
            y = up(all->game->scene,
            all->game->scene->elems->player, all->game);
        if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
            y = down(all->game->scene,
            all->game->scene->elems->player, all->game);
        sfClock_restart(all->clocks->clock_event);
    }
    check_idel(all->game->scene, all->game->scene->elems->player);
}
