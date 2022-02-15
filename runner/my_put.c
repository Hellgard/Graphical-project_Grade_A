/*
** EPITECH PROJECT, 2021
** my_put.c
** File description:
** put fct
*/
#include <unistd.h>
#include "game.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    my_putchar('\n');
    return (0);
}

int my_put_nbr(int nb)
{
    int mod;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    } else if (nb > 9) {
        mod = nb % 10;
        nb = (nb - mod) / 10;
        my_put_nbr(nb);
        my_put_nbr(mod);
    } else {
        int num = nb % 10 + 48;
        my_putchar(num);
    }
    return (0);
}

void main_event(FILE *fd, sfRenderWindow *window, player_s *player)
{
    sfEvent event;
    sfVector2i mouse_pos;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            do_event(fd, window, player, event);
        }
    }
}

void main_menu(FILE *fd, sfRenderWindow *window, player_s *player)
{
    sfTexture *Back_texture;
    Back_texture = sfTexture_createFromFile("image/main_back.jpg", NULL);
    sfSprite *Back_Sprite = sfSprite_create();
    sfSprite_setTexture(Back_Sprite, Back_texture, sfFalse);

    if (window != NULL) {
        while (sfRenderWindow_isOpen(window)) {
            sfRenderWindow_display(window);
            main_event(fd, window, player);
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, Back_Sprite, NULL);
            sfRenderWindow_setFramerateLimit(window, 60);
        }
        sfRenderWindow_destroy(window);
    }
}
