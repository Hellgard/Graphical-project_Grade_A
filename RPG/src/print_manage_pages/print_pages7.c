/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void print_character_inventory(all_var *all)
{
    csfml_print_sprites_area(all,
    all->sprites->character_rotation[all->var->player],
    (sfVector2f){1330, 100}, all->vectors->select_char_rotation);
}

void print_animation_equiped(all_var *all)
{
    if (all->var->animation_equiped < 8 &&
    sfTime_asSeconds(all->clocks->time_animation) > 0.06) {
        change_rotation_character(&all->vectors->select_char_rotation, -1);
        all->var->animation_equiped++;
        sfClock_restart(all->clocks->clock_animation_equiped);
    }
}

void print_inventory_ext2(all_var *all, int inv_page, sfVector2f pos2)
{
    for (t_info_inventory *tmp = all->inventory[inv_page]->next; tmp != NULL;
    tmp = tmp->next) {
        if (tmp->num_slot == all->var->item_selected && tmp->type != -1)
            print_inventory_buttons(all, tmp);
        if (tmp->type != -1) {
            pos2 = tmp->pos;
            pos2.y += 75;
            pos2.x += 20;
            print_element_inventory_inuse(all, tmp);
            sfSprite_setPosition(all->sprites->inventory_items[inv_page]
            [tmp->type], pos2);
            sfRenderWindow_drawSprite(all->windows->window,
            all->sprites->inventory_items[inv_page][tmp->type], NULL);
            csfml_print_num(all, 50, tmp->pos_quant, tmp->quantity);
        }
    }
}

void print_inventory_ext(all_var *all, int inv_page, sfVector2f pos2)
{
    if (all->var->inventory_page != 3) {
        get_item_selected(all);
        csfml_print_sprites(all, all->sprites->slots,
        all->vectors->pos_origin);
    } else {
        get_skill_selected(all);
        csfml_print_sprites(all, all->sprites->slots_skills,
        all->vectors->pos_origin);
    }
    if (all->var->item_selected != -1)
        show_item_properties(all);
    print_inventory_bars(all);
    print_character_inventory(all);
    print_animation_equiped(all);
    print_inventory_ext2(all, inv_page, pos2);
}

void print_inventory(all_var *all)
{
    int inv_page = all->var->inventory_page;
    sfVector2f pos2;

    all->clocks->time_animation =
    sfClock_getElapsedTime(all->clocks->clock_animation_equiped);
    csfml_print_sprites(all, all->sprites->background_menu,
    all->vectors->pos_origin);
    csfml_print_sprites(all, all->sprites->inventory,
    all->vectors->pos_origin);
    csfml_print_sprites(all, all->sprites->inventory_page_selected[inv_page],
    (sfVector2f){120, 365});
    buttons_inventory(all);
    buttons_inventory2(all);
    print_inventory_ext(all, inv_page, pos2);
}
