/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "rpg.h"

t_info_inventory **init_struct_inventory(void)
{
    t_info_inventory **tmp = malloc(sizeof(t_info_inventory *) * 5);

    return (tmp);
}

t_info_inventory *init_linked_inventory(int i)
{
    t_info_inventory *tmp = malloc(sizeof(t_info_inventory) * 1);

    tmp->num_slot = i;
    tmp->quantity = 0;
    tmp->pos = get_inventory_pos(i);
    tmp->pos_quant = (sfVector2f){tmp->pos.x + 85, tmp->pos.y + 125};
    tmp->type = -1;
    tmp->in_use = 0;
    tmp->next = NULL;
    return (tmp);
}

all_var *init_struct_all(void)
{
    all_var *all = malloc(sizeof(all_var));

    all->inventory = init_struct_inventory();
    all->game = malloc(sizeof(Game_t));
    all->sounds = malloc(sizeof(sound_var));
    all->vectors = malloc(sizeof(vectors_var));
    all->clocks = malloc(sizeof(clocks_var));
    all->sprites = malloc(sizeof(sprites_var) * 2);
    all->windows = malloc(sizeof(window_var));
    all->windows->event = malloc(sizeof(sfEvent));
    all->windows->event->type = -1;
    all->texts = malloc(sizeof(texts_var));
    all->var = malloc(sizeof(t_var));
    return all;
}
