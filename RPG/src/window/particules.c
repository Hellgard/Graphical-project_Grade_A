/*
** EPITECH PROJECT, 2022
** particules.c
** File description:
** particules
*/

#include "rpg.h"

sfSprite *create_particle(sfVector2f size, sfVector2f pos, sfColor color)
{
    sfTexture *texture = sfTexture_createFromFile("./image/snow.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, 0);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, size);
    return (sprite);
}

particle_t **init_particles(all_var *all, int nb_particles)
{
    particle_t **particle = malloc(sizeof(particle_t *) * (nb_particles + 1));
    int i = 0;
    for (i = 0; i < nb_particles; i++) {
        particle[i] = malloc(sizeof(particle_t));
        particle[i]->size = (sfVector2f){0.1, 0.1};
        particle[i]->pos = (sfVector2f){rand() %
        sfRenderWindow_getSize(all->windows->window).x, 0};
        particle[i]->color = (sfColor){229, 229, 229, 255};
        particle[i]->speed = (sfVector2f){0, 4 + (rand() % 16)};
        particle[i]->sprite = create_particle(particle[i]->size,
        particle[i]->pos, particle[i]->color);
    }
    particle[i] = NULL;
    return (particle);
}

void particle_system(all_var *all, particle_t **particle)
{
    for (int i = 0; particle[i] != NULL; i++) {
        if (particle[i]->pos.y >=
        sfRenderWindow_getSize(all->windows->window).y)
            sfSprite_setPosition(particle[i]->sprite, (sfVector2f){rand() %
            sfRenderWindow_getSize(all->windows->window).x, 0});
        else
            sfSprite_move(particle[i]->sprite, (sfVector2f){2 * sin(2.0 *
            particle[i]->speed.y), particle[i]->speed.y / 2});
        particle[i]->pos.y = sfSprite_getPosition(particle[i]->sprite).y;
        sfRenderWindow_drawSprite(all->windows->window, particle[i]->sprite
        , NULL);
    }
}
