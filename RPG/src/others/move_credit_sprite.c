/*
** EPITECH PROJECT, 2022
** move_credit_sprite.c
** File description:
** move_credit_sprite
*/

#include "rpg.h"

void move_credit_sprite(credit_t *ending)
{
    sfSprite_scale(ending->back, ending->scale_down);
    sfSprite_move(ending->back, ending->scale_up);
}
