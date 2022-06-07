/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void free_arr_sprites(sfSprite **arr_sprite)
{
    int i = 0;

    while (arr_sprite[i] != NULL) {
        sfSprite_destroy(arr_sprite[i]);
        i++;
    }
    free(arr_sprite);
}

void destroy_all(all_var *all)
{
    sfText_destroy(all->texts->text);
    sfFont_destroy(all->texts->font);
    sfSprite_destroy(all->sprites->inventory);
    sfSprite_destroy(all->sprites->health_bar);
    sfSprite_destroy(all->sprites->armour_bar);
    sfSprite_destroy(all->sprites->improve_bar);
    sfSprite_destroy(all->sprites->page_portada);
    sfSprite_destroy(all->sprites->background_menu);
    sfSprite_destroy(all->sprites->page_mainmenu);
    sfSprite_destroy(all->sprites->page_settings);
    sfSprite_destroy(all->sprites->page_levels);
    sfSprite_destroy(all->sprites->page_selection_player);
    sfSprite_destroy(all->sprites->button_delete_equip);
    sfSprite_destroy(all->sprites->button_unequip);
    sfSprite_destroy(all->sprites->reaction_inventory);
    sfSprite_destroy(all->sprites->reaction_big_button);
    sfSprite_destroy(all->sprites->reaction_small_button);
    sfSprite_destroy(all->sprites->mouse);
    sfSprite_destroy(all->sprites->settings_check);
    sfClock_destroy(all->clocks->clock_loading);
}

void free_all(all_var *all)
{
    free_arr_arr_sprites(all->sprites->inventory_items);
    free_arr_sprites(all->sprites->inventory_page_selected);
    free_inventory(all);
    free(all->sounds);
    free(all->texts);
    free(all->sprites);
    free(all->vectors);
    free(all->clocks);
    free(all->windows->event);
    free(all->var);
    close_game(all);
    free(all);
}

void free_str_arr(char **arr)
{
    if (!arr)
        return;
    int i = 0;
    while (arr[i]) {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void free_str_arr_arr(char ***arr)
{
    if (!arr)
        return;
    int i = 0;
    int j = 0;
    while (arr[i]) {
        free_str_arr(arr[i]);
        i++;
    }
    free(arr);
}
