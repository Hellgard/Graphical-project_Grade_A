/*
** EPITECH PROJECT, 2022
** soldier.c
** File description:
** soldier
*/

#include "rpg.h"

void change_char(sfIntRect *select_char)
{
    select_char->left += 300;
    if (select_char->left >= 2400)
        select_char->left = 0;
}

void soldier_steps(scene_t *all)
{
    all->movemnt_time = sfClock_getElapsedTime(all->movemnt_clock);
    if (sfTime_asSeconds(all->movemnt_time) > 0.05) {
        change_char(&all->select_character);
        sfClock_restart(all->movemnt_clock);
    }
}

void print_soldier_2(obj_t *obj)
{
    if (obj->pos.y > obj->pos_target.y) {
        sfSprite_move(obj->sprite, (sfVector2f){0, -12});
        obj->pos.y = sfSprite_getPosition((obj->sprite)).y;
        if (obj->pos.y <= obj->pos_target.y)
            obj->pos.y = obj->pos_target.y;
    }
    if (obj->pos.y < obj->pos_target.y) {
        sfSprite_move(obj->sprite, (sfVector2f){0, 12});
        obj->pos.y = sfSprite_getPosition((obj->sprite)).y;
        if (obj->pos.y >= obj->pos_target.y)
            obj->pos.y = obj->pos_target.y;
    }
}

void print_soldier(all_var *all, obj_t *obj, int z, int y)
{
    soldier_steps(all->game->scene);
    if (obj->pos.x < obj->pos_target.x) {
        sfSprite_move(obj->sprite, (sfVector2f){12, 0});
        obj->pos.x = sfSprite_getPosition((obj->sprite)).x;
        if (obj->pos.x >= obj->pos_target.x)
            obj->pos.x = obj->pos_target.x;
    }
    if (obj->pos.x > obj->pos_target.x) {
        sfSprite_move(obj->sprite, (sfVector2f){-12, 0});
        obj->pos.x = sfSprite_getPosition((obj->sprite)).x;
        if (obj->pos.x <= obj->pos_target.x)
            obj->pos.x = obj->pos_target.x;
    }
    print_soldier_2(obj);
    sfSprite_setTextureRect(obj->sprite, all->game->scene->select_character);
    sfRenderWindow_drawSprite(all->windows->window, obj->sprite, NULL);
}
