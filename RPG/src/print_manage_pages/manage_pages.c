/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "rpg.h"

void fill_flags2(struct_pages *flags)
{
    flags[9].op = PAGE_CONFIRMATION;
    flags[9].ptr = &print_confirmation;
    flags[10].op = PAGE_PREV_BATTLE;
    flags[10].ptr = &print_prev_battle;
    flags[11].op = PAGE_BATTLE;
    flags[11].ptr = &print_battle;
    flags[12].op = PAGE_BOOK;
    flags[12].ptr = &print_book;
}

void fill_flags(struct_pages *flags)
{
    flags[0].op = PAGE_PORTADA;
    flags[0].ptr = &print_page_portada;
    flags[1].op = PAGE_MAINMENU;
    flags[1].ptr = &print_page_mainmenu;
    flags[2].op = PAGE_SETTINGS;
    flags[2].ptr = &print_page_settings;
    flags[3].op = PAGE_LEVELS;
    flags[3].ptr = &print_page_levels;
    flags[4].op = PAGE_SELECTION_PLAYER;
    flags[4].ptr = &print_page_selection_player;
    flags[5].op = PAGE_GAME;
    flags[5].ptr = &print_game;
    flags[6].op = PAGE_SAVE;
    flags[6].ptr = &print_page_save;
    flags[7].op = PAGE_INVENTORY;
    flags[7].ptr = &print_inventory;
    flags[8].op = PAGE_PAUSE;
    flags[8].ptr = &print_pause;
    fill_flags2(flags);
}

void manage_pages(all_var *all)
{
    int i = 0;
    int num_pages = 13;
    struct_pages flags[num_pages];

    fill_flags(flags);
    while (i < num_pages) {
        if (all->var->page == flags[i].op) {
            (*(flags[i].ptr))(all);
        }
        i++;
    }
}
