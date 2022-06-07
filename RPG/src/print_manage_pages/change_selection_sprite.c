/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void change_health(all_var *all)
{
    int i = 100;
    if (all->var->prev_health != all->var->health) {
        all->vectors->select_health = (sfIntRect) {0, 0, 500, 27};
        while (i != all->var->health && i >= 0 && all->var->health <= 100) {
            all->vectors->select_health.top += 27;
            i--;
        }
        all->var->prev_health = all->var->health;
    }
}

void change_strength(all_var *all)
{
    int i = 100;
    if (all->var->prev_strength != all->var->strength) {
        all->vectors->select_strength = (sfIntRect) {0, 0, 500, 27};
        while (i != all->var->strength && i >= 0 && all->var->strength <= 100) {
            all->vectors->select_strength.top += 27;
            i--;
        }
        all->var->prev_strength = all->var->strength;
    }
}

void change_armour(all_var *all)
{
    int i = 100;
    if (all->var->prev_armour != all->var->armour) {
        all->vectors->select_armour = (sfIntRect) {0, 0, 500, 27};
        while (i != all->var->armour && i >= 0 && all->var->armour <= 100) {
            all->vectors->select_armour.top += 27;
            i--;
        }
        all->var->prev_armour = all->var->armour;
    }
}

void change_rect_bar(all_var *all, int value)
{
    int i = 100;
    all->vectors->select_armour = (sfIntRect) {0, 0, 500, 27};
    while (i != value && i >= 0 && value <= 100) {
        all->vectors->select_armour.top += 27;
        i--;
    }
}

void change_rotation_character(sfIntRect *rect, int direction)
{
    if (direction == -1)
        rect->left -= 363;
    else
        rect->left += 363;
    if (rect->left > 1089)
        rect->left = 0;
    else if (rect->left < 0)
        rect->left = 1089;
}
