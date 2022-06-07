/*
** EPITECH PROJECT, 2021
** draw.c
** File description:
** draw
*/

#include "rpg.h"

void draw_text(all_var *all)
{
    check_draw_text(all, all->game->scene->elems->collision);
    check_draw_text(all, all->game->scene->elems->cutscene);
    check_draw_text(all, all->game->scene->elems->pet);
    check_draw_text(all, all->game->scene->elems->player);
    check_draw_text(all, all->game->scene->elems->portal);
    check_draw_text(all, all->game->scene->elems->enemy);
    check_draw_text(all, all->game->scene->elems->event);
    check_draw_text(all, all->game->scene->elems->movable);
    check_draw_text(all, all->game->scene->elems->boss);
    check_draw_text(all, all->game->scene->elems->quest);
}

void draw_elem(all_var *all)
{
    check_draw(all, all->game->scene->elems->pet);
    check_draw(all, all->game->scene->elems->event);
    check_draw(all, all->game->scene->elems->collision);
    check_draw(all, all->game->scene->elems->enemy);
    check_draw(all, all->game->scene->elems->movable);
    check_draw(all, all->game->scene->elems->portal);
    check_draw(all, all->game->scene->elems->cutscene);
    print_soldier(all, all->game->scene->elems->player[0], 0, 0);
    check_draw(all, all->game->scene->elems->boss);
    check_draw(all, all->game->scene->elems->quest);
}
