/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void print_element_inventory_inuse(all_var *all, t_info_inventory *tmp)
{
    if (tmp->in_use == 1) {
        sfVector2f pos = (sfVector2f){get_inventory_pos(tmp->num_slot).x - 15,
        get_inventory_pos(tmp->num_slot).y + 45};
        sfSprite_setPosition(all->sprites->reaction_inventory, pos);
        sfRenderWindow_drawSprite(all->windows->window,
        all->sprites->reaction_inventory, NULL);
    }
}

void print_inventory_bars(all_var *all)
{
    change_health(all);
    change_strength(all);
    change_armour(all);
    csfml_print_sprites_area(all, all->sprites->health_bar,
    (sfVector2f){1275, 800}, all->vectors->select_health);
    csfml_print_sprites_area(all, all->sprites->shield_bar,
    (sfVector2f){1275, 880}, all->vectors->select_strength);
    csfml_print_sprites_area(all, all->sprites->armour_bar,
    (sfVector2f){1275, 960}, all->vectors->select_armour);
    csfml_print_num(all, 50, (sfVector2f){1205, 790}, all->var->health);
    csfml_print_num(all, 50, (sfVector2f){1205, 870}, all->var->strength);
    csfml_print_num(all, 50, (sfVector2f){1205, 950}, all->var->armour);
}

void display_game_information(all_var *all)
{
    csfml_print_sprites(all, all->sprites->pause_button, (sfVector2f){0, 0});
    change_health(all);
    change_strength(all);
    change_armour(all);
    csfml_print_sprites_area(all, all->sprites->game_health_bar,
    (sfVector2f){110, 56}, all->vectors->select_health);
    csfml_print_sprites_area(all, all->sprites->game_shield_bar,
    (sfVector2f){110, 108}, all->vectors->select_strength);
    csfml_print_sprites_area(all, all->sprites->game_armour_bar,
    (sfVector2f){110, 160}, all->vectors->select_armour);
    csfml_print_text(all, 30, (sfVector2f){60, 200}, "LVL");
    csfml_print_num(all, 30, (sfVector2f){110, 200}, all->game->player->level);
}

void print_bars_battle(all_var *all)
{
    change_rect_bar(all,  all->game->enemy[all->game->attack_id]->life);
    csfml_print_sprites_area(all, all->sprites->game_health_bar,
    (sfVector2f){170, 165}, all->vectors->select_armour);
    csfml_print_text(all, 30, (sfVector2f){170, 75}, "LVL");
    csfml_print_num(all, 30, (sfVector2f){220, 75},
    all->game->enemy[all->game->attack_id]->level);
    change_rect_bar(all, all->game->player->life);
    csfml_print_sprites_area(all, all->sprites->game_health_bar,
    (sfVector2f){1500, 570}, all->vectors->select_armour);
    csfml_print_text(all, 30, (sfVector2f){1500, 480}, "LVL");
    csfml_print_num(all, 30, (sfVector2f){1550, 480},
    all->game->player->level);
    all->var->prev_armour = -1;
}

void print_book(all_var *all)
{
    int i = all->var->book_page;
    csfml_print_sprites(all, all->sprites->background_menu,
    all->vectors->pos_origin);
    buttons_book(all);
    csfml_print_sprites(all, all->sprites->book, all->vectors->pos_origin);
    csfml_print_sprites(all, all->game->enemy[i]->sprite,
    (sfVector2f){400,200});
    csfml_print_text(all, 30, (sfVector2f){400, 500}, "LEVEL:");
    csfml_print_num(all, 30, (sfVector2f){520, 500},
    all->game->enemy[i]->level);
    csfml_print_text(all, 30, (sfVector2f){400, 600}, "SPEED:");
    csfml_print_num(all, 30, (sfVector2f){520, 600},
    all->game->enemy[i]->speed);  
    csfml_print_text(all, 30, (sfVector2f){400, 700}, "BOSS:");
    if (all->game->enemy[i]->life <= 0)
        csfml_print_sprites(all, all->sprites->book_killed,
        all->vectors->pos_origin);
    if (all->game->enemy[i]->isBoss)
        csfml_print_text(all, 30, (sfVector2f){520, 700}, "YES");
    else
        csfml_print_text(all, 30, (sfVector2f){520, 700}, "NO");
    if ((i + 1) < 13) {
        csfml_print_sprites(all, all->game->enemy[i + 1]->sprite,
        (sfVector2f){1000,200});
        if (all->game->enemy[i + 1]->life <= 0)
            csfml_print_sprites(all, all->sprites->book_killed,
            (sfVector2f){650,0});
        csfml_print_text(all, 30, (sfVector2f){1050, 500}, "LEVEL:");
        csfml_print_num(all, 30, (sfVector2f){1170, 500},
        all->game->enemy[i + 1]->level);
        csfml_print_text(all, 30, (sfVector2f){1050, 600}, "SPEED:");
        csfml_print_num(all, 30, (sfVector2f){1170, 600},
        all->game->enemy[i + 1]->speed);
        csfml_print_text(all, 30, (sfVector2f){1050, 700}, "BOSS:");
        if (all->game->enemy[i + 1]->isBoss)
            csfml_print_text(all, 30, (sfVector2f){1170, 700}, "YES");
        else
            csfml_print_text(all, 30, (sfVector2f){1170, 700}, "NO");
    }
}