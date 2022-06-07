/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void print_page_selection_player(all_var *all)
{
    csfml_print_sprites(all, all->sprites->background_menu,
    all->vectors->pos_origin);
    buttons_selection_player(all);
    csfml_print_sprites(all, all->sprites->page_selection_player,
    all->vectors->pos_origin);
}

void print_game_selected(all_var *all)
{
    int i = 0;
    sfVector2f pos = {240, 405};

    while (i < 3) {
        if (all->var->current_game == i)
            csfml_print_sprites(all,
            all->sprites->reaction_game_selected, pos);
        pos.x += 516;
        i++;
    }
}

void disp_text(all_var *all, int i, sfVector2f pos2, sfVector2f pos3)
{
    csfml_print_sprites(all, all->sprites->trash,
    pos2);
    sfText_setFont(all->texts->text, all->texts->font2);
    csfml_print_text(all, 70, pos3, all->var->list_name_saved[i]);
    sfText_setFont(all->texts->text, all->texts->font);
}

void print_save_info(all_var *all)
{
    int i = 0;
    sfVector2f pos = {240, 390};
    sfVector2f pos2 = {290, 350};
    sfVector2f pos3 = {330, 510};
    while (i < 3) {
        if (all->var->list_saved[i] == 0)
            csfml_print_sprites(all, all->sprites->msg_save_game,
            pos);
        else {
            disp_text(all, i, pos2, pos3);
        }
        pos.x += 516;
        pos2.x += 516;
        pos3.x += 516;
        i++;
    }
}

void print_page_save(all_var *all)
{
    csfml_print_sprites(all, all->sprites->background_menu,
    all->vectors->pos_origin);
    buttons_save(all);
    if (all->var->autosave == true)
        csfml_print_sprites(all, all->sprites->reaction_small_button_2,
        (sfVector2f){1573, 105});
    print_game_selected(all);
    csfml_print_sprites(all, all->sprites->page_save,
    all->vectors->pos_origin);
    print_save_info(all);
}
