/*
** EPITECH PROJECT, 2022
** key.c
** File description:
** key
*/

#include "rpg.h"

char get_key_code(all_var *all)
{
    char key = '\0';
    char keycode = '\0';
    for (int i = 0; i < 26; i++) {
        key = i;
        if (key == all->windows->event->key.code)
            return (char)(i + 97);
    }
    return '\0';
}

void get_switch(all_var *all, char keycode)
{
    if (sfTime_asSeconds(all->clocks->time_key) > 0.3) {
        switch (keycode) {
            case KEY_INVENTORY:
                if (all->var->page == PAGE_GAME && all->game->on_attack == 0)
                    all->var->page = PAGE_INVENTORY;
                else if (all->var->page == PAGE_INVENTORY)
                    all->var->page = PAGE_GAME;
                break;
            case KEY_PAUSE:
                if (all->var->page == PAGE_GAME)
                    all->var->page = PAGE_PAUSE;
                else if (all->var->page == PAGE_PAUSE)
                    all->var->page = PAGE_GAME;
                break;
            case KEY_MSG:
                secret_event(all, all->game->scene->elems->player[0], KEY_MSG);
                event_text(all->game->scene, KEY_MSG);
                break;
            case KEY_BOOK:
                if (all->var->page == PAGE_GAME && all->game->on_attack == 0) {
                    scale_enemies_book(all);
                    all->var->page = PAGE_BOOK;

                }
                else if (all->var->page == PAGE_BOOK) {
                    scale_reset_enemies_book(all);
                    all->var->page = PAGE_GAME;
                }
                break;
        }
        sfClock_restart(all->clocks->clock_key);
    }
}

void get_key(all_var *all)
{
    char keycode = get_key_code(all);
    all->clocks->time_key = sfClock_getElapsedTime(
    all->clocks->clock_key);
    get_switch(all, keycode);
}
