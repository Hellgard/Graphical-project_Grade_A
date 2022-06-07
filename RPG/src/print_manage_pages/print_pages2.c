/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "rpg.h"

void print_page_settings_2(all_var *all)
{
    sfVector2f pos;
    switch(all->var->prev_fps) {
        case 0:
            all->var->fps = 30;
            pos = (sfVector2f){1086, 450};
            break;
        case 1:
            all->var->fps = 60;
            pos = (sfVector2f){1330, 450};
            break;
        case 2:
            all->var->fps = 120;
            pos = (sfVector2f){1575, 450};
            break;
    }
    csfml_print_sprites(all, all->sprites->settings_check, pos);
}

void print_page_settings(all_var *all)
{
    csfml_print_sprites(all, all->sprites->background_menu,
    all->vectors->pos_origin);
    buttons_settings(all);
    csfml_print_sprites(all, all->sprites->page_settings,
    all->vectors->pos_origin);
    print_page_settings_2(all);
}
