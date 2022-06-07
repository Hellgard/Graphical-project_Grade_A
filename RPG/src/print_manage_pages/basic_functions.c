/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

char *ext_my_return_char(int nb, char *str, int neg)
{
    int i = 0;

    while (nb > 0) {
        str[i] = nb % 10 + 48;
        nb /= 10;
        i++;
    }
    if (neg == 1) {
        str[i] = '-';
        i++;

    }
    str[i] = '\0';
    return (str);
}

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    i--;
    return (i);
}

char *my_return_char(int nb)
{
    char *str = malloc(sizeof(char) * my_nbrlen(nb) + 1);
    int neg = 0;

    if (nb < 0) {
        neg = 1;
        nb = -nb;
    }
    if (nb == 0) {
        return ("0");
        free(str);
    }
    return (my_revstr(ext_my_return_char(nb, str, neg)));
}
