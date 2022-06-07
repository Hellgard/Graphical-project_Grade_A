/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"
#include <math.h>

int *get_element_file(char *filepath)
{
    int fd = open (filepath, O_RDONLY);
    char *text = save_text(fd, filepath);
    char **sentences = save_word(text, '\n', filepath);
    int *info = malloc(sizeof(int) * 2);
    info[0] = my_getnbr(sentences[4]);
    info[1] = my_getnbr(sentences[5]);
    free(text);
    free_str_arr(sentences);
    close(fd);
    return (info);
}

void link_var(all_var *all)
{
    all->var->health = all->game->player->life;
    all->var->strength = all->game->player->defense;
    all->var->armour = all->game->player->attack;
}

void change_pos(all_var *all)
{
    player_struct->pos.x = ((player_struct->x) *
    (map_x / all->game->scene->tile_size_x) * scl_1);
    player_struct->pos.y = ((player_struct->y) *
    (map_y / all->game->scene->tile_size_y) * scl_2);
    player_struct->pos_target = player_struct->pos;
}

void my_window2(all_var *all, particle_t **particle)
{
    sfRenderWindow_clear(all->windows->window, sfBlack);
    manage_pages(all);
    link_var(all);
    autosave(all);
    save_general(all);
    if (my_strcmp(all->var->actual_id, "7") == 0 ||
    my_strcmp(all->var->actual_id, "8") == 0)
        particle_system(all, particle);
    change_sound(all);
    sfRenderWindow_display(all->windows->window);
}

sfRenderWindow *my_window(all_var *all)
{
    int ini = 0;
    particle_t **particle = init_particles(all, 200);
    sfRenderWindow_setKeyRepeatEnabled(all->windows->window, sfTrue);
    all->clocks->clock_loading = sfClock_create();
    change_pos(all);
    while (sfRenderWindow_isOpen(all->windows->window)) {
        all->clocks->time_loading =
        sfClock_getElapsedTime(all->clocks->clock_loading);
        if (sfTime_asSeconds(all->clocks->time_loading) < 1) {
            print_page_charge(all);
            ini_all_start(all, ini);
            sfMusic_play(all->game->scene->ambiance);
            ini++;
        } else
            my_window2(all, particle);
        sfRenderWindow_setFramerateLimit(all->windows->window, 30);
        chose_char_color(all);
        sfSprite_setScale(player_struct->sprite, (sfVector2f) {(640 * 0.3 /
        map_x), (480 * 0.225 / map_y)});
        analyse_events(all, 0);
        if (all->windows->event->type == sfEvtMouseButtonPressed) {
            sfVector2i mouse = sfMouse_getPositionRenderWindow(all->windows->window);
            printf("x: %d y: %d\n", mouse.x, mouse.y);
        }
    }
}
