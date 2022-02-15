
#include "hunter.h"
#include <unistd.h>

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
    }
    if (nb > 9) {
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

void mainwindow_view(sfRenderWindow *mainWindow, sfSprite *back_sprite, sfSprite *dog)
{
    sfRenderWindow_clear(mainWindow, sfBlack);
    draw_sprite_main(mainWindow, dog, back_sprite);
    sfRenderWindow_setFramerateLimit(mainWindow, 60);
}
