/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void print_inventory_buttons(all_var *all, t_info_inventory *tmp)
{
    csfml_print_sprites(all, all->sprites->button_delete_equip,
    (sfVector2f){1050, 165});
    if (tmp->in_use == 1)
        csfml_print_sprites(all, all->sprites->button_unequip,
        (sfVector2f){1218, 165});
}

void unequip_element_inventory(all_var *all)
{
    t_info_inventory *tmp = get_slot_inventory(all);

    if (tmp->in_use == 1 && tmp->type != -1) {
        all->game->player->life -= my_getnbr(all->var->item_propeties[1]);
        all->game->player->defense -= my_getnbr(all->var->item_propeties[2]);
        all->game->player->attack -= my_getnbr(all->var->item_propeties[3]);
        tmp->in_use = 0;
        if (my_strcmp(all->var->item_propeties[4], "0") == 0)
            all->var->weapon = 0;
        else if (my_strcmp(all->var->item_propeties[4], "1") == 0)
            all->var->shield = 0;
    }
}

void change_improve(all_var *all)
{
    int i = 100;

    if (all->var->prev_improve != all->var->improve) {
        all->vectors->select_improve = (sfIntRect) {0, 0, 500, 27};
        while (i != all->var->improve && i > 0) {
            all->vectors->select_improve.top += 27;
            i--;
        }
    }
}

void print_improve(all_var *all)
{
    all->var->improve = atoi(all->var->item_propeties[1]) +
    all->var->health;
    if (all->var->improve > all->game->player->max_life)
        all->var->improve = all->game->player->max_life;
    change_improve(all);
    csfml_print_sprites_area(all, all->sprites->improve_bar,
    (sfVector2f){1275, 800}, all->vectors->select_improve);
    all->var->improve = atoi(all->var->item_propeties[2])
    + all->var->strength;
    all->var->prev_improve = -1;
    change_improve(all);
    csfml_print_sprites_area(all, all->sprites->improve_bar,
    (sfVector2f){1275, 880}, all->vectors->select_improve);
    all->var->improve = atoi(all->var->item_propeties[3])
    + all->var->armour;
    all->var->prev_improve = -1;
    change_improve(all);
    csfml_print_sprites_area(all, all->sprites->improve_bar,
    (sfVector2f){1275, 960}, all->vectors->select_improve);
    all->var->prev_improve = -1;
}

void show_item_properties(all_var *all)
{
    int fd;
    int item = all->var->item_selected;
    int inv_page = all->var->inventory_page;
    t_info_inventory *tmp = all->inventory[inv_page]->next;

    while (tmp != NULL && tmp->num_slot != item)
        tmp = tmp->next;
    if (tmp->type != -1) {
        fd = open (tmp->filepath, O_RDONLY);
        char *text = save_text(fd, tmp->filepath);
        free_str_arr(all->var->item_propeties);
        all->var->item_propeties = save_word(text, '\n', tmp->filepath);
        if (!tmp->in_use)
            print_improve(all);
        free(text);
        close(fd);
        equip_delete_selected(all);
    }
}
