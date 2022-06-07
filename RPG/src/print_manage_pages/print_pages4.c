/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void check_boss_valid(all_var *all, obj_t **boss)
{
    int i;

    for (i = 0; boss[i]; i++) {
        for (; all->game->quest_list->str != NULL; all->game->quest_list
        = all->game->quest_list->next)
            valid_boss(all, boss[i]);
    }
}

void print_game_ext(all_var *all)
{
    all->game->Combat_ambiance->combat_infos = malloc(sizeof(char) * 2);
    all->game->Combat_ambiance->combat_infos = "\n\0";
    all->game->turn_combat = 0;
    all->game->clock_combat = sfClock_create();
    all->var->page = PAGE_PREV_BATTLE;
}

void print_game(all_var *all)
{
    if (all->game->on_attack == 0) {
        all->var->prevpage = PAGE_GAME;
        sfRenderWindow_drawSprite(all->windows->window,
        all->game->scene->sprite, NULL);
        draw_elem(all);
        key_check(all);
        display_game_information(all);
        draw_text(all);
        buttons_game(all);
        check_boss_valid(all, all->game->scene->elems->boss);
        teleport_check(all);
        movable_check(all);
        attack_check(all);
        display_game_quest(all);
        if (check_main_quest(all) == 1)
            close_game(all);
    } else  if (all->game->on_attack == 1)
        print_game_ext(all);
}

void print_pause(all_var *all)
{
    csfml_print_sprites(all, all->sprites->background_menu,
    all->vectors->pos_origin);
    buttons_pause(all);
    csfml_print_sprites(all, all->sprites->pause_page,
    all->vectors->pos_origin);
}

void print_confirmation(all_var *all)
{
    csfml_print_sprites(all, all->sprites->background_menu,
    all->vectors->pos_origin);
    buttons_confirmation(all);
    csfml_print_sprites(all, all->sprites->delete_confirmation,
    all->vectors->pos_origin);
}
