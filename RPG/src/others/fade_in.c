/*
** EPITECH PROJECT, 2022
** fade_in.h
** File description:
** fade_in
*/

#include "rpg.h"

void rectangle_create(rectangle_t *fade_in, int i)
{
    fade_in->rects = sfRectangleShape_create();
    sfVector2f pos = {fade_in->x_pos[i], fade_in->y_pos[i]};
    sfVector2f size = {3200, 300};
    sfRectangleShape_setPosition(fade_in->rects, pos);
    sfRectangleShape_setSize(fade_in->rects, size);
    sfRectangleShape_setFillColor(fade_in->rects, sfBlack);
}

void fade_in_innit(all_var *all)
{
    all->game->fade_in = malloc(sizeof(rectangle_t *) * 5);

    for (int i = 0; i < 4; i++) {
        all->game->fade_in[i] = malloc(sizeof(rectangle_t));
        all->game->fade_in[i]->offset.x = 200;
        all->game->fade_in[i]->offset.y = 0;
        all->game->fade_in[i]->x_pos = malloc(sizeof(int) * 4);
        all->game->fade_in[i]->y_pos = malloc(sizeof(int) * 4);
        all->game->fade_in[i]->x_pos[0] = -3000;
        all->game->fade_in[i]->x_pos[1] = -3100;
        all->game->fade_in[i]->x_pos[2] = -3200;
        all->game->fade_in[i]->x_pos[3] = -3300;
        all->game->fade_in[i]->y_pos[0] = 0;
        all->game->fade_in[i]->y_pos[1] = 300;
        all->game->fade_in[i]->y_pos[2] = 600;
        all->game->fade_in[i]->y_pos[3] = 900;
        rectangle_create(all->game->fade_in[i], i);
    }
    all->game->fade_in[4] = NULL;
}

int reset_fade_in(rectangle_t **fade_in)
{
    sfVector2f info_pos = sfRectangleShape_getPosition(fade_in[3]->rects);
    int i;

    if (info_pos.x > 500) {
        for (i = 0; i < 4; i++) {
            sfRectangleShape_destroy(fade_in[i]->rects);
        }
        return (1);
    }
    return (0);
}

void fade_in_display(rectangle_t **fade_in, sfRenderWindow *window)
{
    for (int i = 0; i < 4; i++)
        sfRectangleShape_move(fade_in[i]->rects, fade_in[i]->offset);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawRectangleShape(window, fade_in[i]->rects, NULL);
}

void fade_in(all_var *all)
{
    fade_in_innit(all);

    while (1) {
        fade_in_display(all->game->fade_in, all->windows->window);
        sfRenderWindow_display(all->windows->window);
        if (reset_fade_in(all->game->fade_in) == 1)
            break;
    }
}
