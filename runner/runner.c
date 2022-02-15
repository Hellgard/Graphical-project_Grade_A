/*
** EPITECH PROJECT, 2021
** runner.c
** File description:
** game launching
*/

#include "game.h"

void ending_game(player_s *player, sfMusic *musique, \
backs_s *back, sfRenderWindow *window)
{
    sfSprite_destroy(player->sprite);
    sfSprite_destroy(back->sprite);
    sfSprite_destroy(back->sprite2);
    sfTexture_destroy(back->texture);
    sfTexture_destroy(player->texture);
    sfRenderWindow_destroy(window);
    sfMusic_destroy(musique);
}

void player_jump_glitch(player_s *player)
{
    if (player->pos.y <= 690)
        player->pos.y = 690;
    if (player->rect.left >= 860) {
        player->jump = 0;
        player->clock = 100000;
        player->pos.y = 840;
    }
    if (player->rect.left <= 80 && player->rect.left >= 690)
        player->pos.y += 2;
    else if (player->rect.left <= 533) {
        player->pos.y -= 2;
    }
}

void events(sfRenderWindow *window, sfEvent event, player_s *player)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeySpace) {
            player->i += 1;
            player->jump = 1;
            sfSound_play(player->jump_sound.sound);
            player->rect.left = 200;
            player->clock = 200000;
        }
    }
}

void start_game(FILE *fd, sfEvent event, sfRenderWindow *window, \
player_s *player)
{
    enemy_s *enemy = manage_enemy(fd);
    sfClock *clock = sfClock_create();
    backs_s *back = manage_back_info();
    sfRenderWindow_setFramerateLimit(window, 130);
    sfMusic *music = sfMusic_createFromFile("image/musique.ogg");
    player->jump_sound = manage_sound();

    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        if (player_hit(enemy, player) == 1)
            break;
        move_backgrounds(window, back);
        move_enemy(clock, window, enemy, player->i);
        player = move_player(player, window, clock);
        events(window, event, player);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
    }
    ending_game(player, music, back, window);
}

int main(int ac, char **av)
{
    FILE *fd;
    player_s *player = malloc(sizeof(player_s));
    sfVideoMode pixel = {1920, 1080, 32};
    sfRenderWindow *window;
    fd = fopen(av[1], "r");

    if (ac != 2)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        print_h();
        return 0;
    } if (fd == NULL)
        return 84;
    window = sfRenderWindow_create(pixel, "psychedelic runner", \
    sfResize | sfClose, NULL);
    main_menu(fd, window, player);
    fclose(fd);
    return (0);
}
