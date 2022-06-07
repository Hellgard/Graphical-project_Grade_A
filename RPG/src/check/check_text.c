/*
** EPITECH PROJECT, 2022
** check_text.c
** File description:
** check_text
*/

#include "rpg.h"

void check_text_4(obj_t *obj, all_var *all)
{
    if (obj->perm->isQuest != 1 &&
    my_strcmp(obj->linked_id_2, "none") == 0) {
        sfVector2f pos = {100, 930};
        sfText_setPosition(obj->Text[obj->i], pos);
        sfRenderWindow_drawSprite(all->windows->window,
        all->game->text, NULL);
        sfRenderWindow_drawText(all->windows->window,
        obj->Text[obj->i], NULL);
        return;
    }
    if (obj->perm->isQuest == 1 ||
    (obj->perm->isQuest != 1 &&
    check_id(all->game->quest_list, obj->linked_id) == 1)) {
        sfVector2f pos = {100, 930};
        sfText_setPosition(obj->Text[obj->i], pos);
        sfRenderWindow_drawSprite(all->windows->window, all->game->text, NULL);
        sfRenderWindow_drawText(all->windows->window,
        obj->Text[obj->i], NULL);
        check_quest(all, obj);
    }
    return;
}

void check_text_3(obj_t *obj, all_var *all)
{
    if (obj->perm->isQuest == 1 || (obj->perm->isQuest != 1 &&
    check_id(all->game->quest_list, obj->linked_id) == 1)) {
        check_quest_loot(all, obj);
        int pos_x = obj->x * (all->game->scene->map_size_x /
        all->game->scene->tile_size_x) * all->game->scene->scale_1;
        int pos_y = obj->y * (all->game->scene->map_size_y /
        all->game->scene->tile_size_y) * all->game->scene->scale_2;
        pos_y -= (all->game->scene->map_size_y /
        all->game->scene->tile_size_y) * (all->game->scene->scale_2);
        pos_x -= (all->game->scene->map_size_x /
        all->game->scene->tile_size_x) + 10;
        sfVector2f pos = {pos_x, pos_y};
        sfSprite_setPosition(all->game->bul_text, pos);
        sfRenderWindow_drawSprite(all->windows->window,
        all->game->bul_text, NULL);
        sfRenderWindow_drawText(all->windows->window, obj->Text[obj->i], NULL);
        return;
    }
}

void check_text_2(all_var *all, obj_t **obj, int i)
{
    if (obj[i]->i > 0)
        check_text_4(obj[i], all);
    if (obj[i]->i <= 0) {
        if (obj[i]->perm->isQuest != 1 &&
        my_strcmp(obj[i]->linked_id_2, "none") == 0) {
            int pos_x = obj[i]->x * (map_x / tile_x) * scl_1;
            int pos_y = obj[i]->y * (map_y / tile_y) * scl_2;
            pos_y -= (map_y / tile_y) * (scl_2);
            pos_x -= (map_x / tile_x) + 10;
            sfVector2f pos = {pos_x, pos_y};
            sfSprite_setPosition(all->game->bul_text, pos);
            sfRenderWindow_drawSprite(all->windows->window,
            all->game->bul_text, NULL);
            sfRenderWindow_drawText(all->windows->window,
            obj[i]->Text[obj[i]->i], NULL);
            return;
        }
        check_text_3(obj[i], all);
    }
}

void check_draw_text(all_var *all, obj_t **obj)
{
    for (int i = 0; obj[i]; i++) {
        if (obj[i]->is == 1 && obj[i]->perm->Text == 1 &&
        is_in_zone(obj[i], all->game->scene) == 1) {
            check_text_2(all, obj, i);
        } else if (obj[i]->is == 1 && obj[i]->perm->Text == 1 &&
        is_in_zone(obj[i], all->game->scene) == 0)
            obj[i]->i = 0;
    }
}
