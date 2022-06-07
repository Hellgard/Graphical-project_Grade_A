/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "rpg.h"

void create_positions(all_var *all)
{
    all->vectors->pos_origin = (sfVector2f){0, 0};
    all->vectors->select_health = (sfIntRect){0, 0, 500, 27};
    all->vectors->select_strength = (sfIntRect){0, 0, 500, 27};
    all->vectors->select_armour = (sfIntRect){0, 0, 500, 27};
    all->vectors->select_char_rotation = (sfIntRect){0, 0, 363, 612};
}
