/*
** EPITECH PROJECT, 2022
** window2.c
** File description:
** window2
*/

#include "rpg.h"
#include <math.h>

void autosave(all_var *all)
{
    if (all->var->autosave == true && all->var->current_game != -1
    && (all->var->page == PAGE_INVENTORY && all->var->page == PAGE_PAUSE)) {
        save_all(all);
    }
    if (all->var->autosave == true && all->var->current_game != -1
    && (all->var->prev_id_map != NULL && my_strcmp(all->var->prev_id_map,
    all->game->scene->id) != 0)) {
        save_all(all);
        all->var->prev_id_map = my_strdup(all->game->scene->id);
    }

}

sfSprite *create_player(all_var *all, char *file_path)
{
    sfTexture *texture_bend = sfTexture_createFromFile(file_path, NULL);
    sfSprite *sprite_bend = sfSprite_create();
    sfSprite_setTexture(sprite_bend, texture_bend, 0);
    sfSprite_setPosition(sprite_bend, all->game->scene->elems->player[0]->pos);

    return (sprite_bend);
}

void chose_char_color(all_var *all)
{
    if (all->var->player != all->var->player_prev) {
        if (all->var->player == 1)
            all->game->scene->elems->player[0]->sprite =
            create_player(all, "./image/play.png");
        if (all->var->player == 1)
            all->game->scene->elems->player[0]->sprite =
            create_player(all, "./image/play_red.png");
        if (all->var->player == 2)
            all->game->scene->elems->player[0]->sprite =
            create_player(all, "./image/play_yellow.png");
        all->var->player_prev = all->var->player;
    }
}

void analyse_events(all_var *all, int page)
{
    while (sfRenderWindow_pollEvent(all->windows->window,
    all->windows->event)) {
        if (all->windows->event->type == sfEvtClosed)
            close_game(all);        
        get_key(all);
    }
}

void create_linked_inventory(all_var *all)
{
    int i = 0;

    while (i < 4) {
        all->inventory[i] = malloc(sizeof(t_info_inventory) * 1);
        create_list_inventory(all->inventory[i]);
        i++;
    }
}
