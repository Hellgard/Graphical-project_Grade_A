/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "./../includes/my_library.h"

int my_matcmp(char **matrix_1, char **matrix_2)
{
    int i = 0;

    while (matrix_1[i] != NULL) {
        if (my_strcmp(matrix_1[i], matrix_2[i]) != 0)
            return (1);
        i++;
    }
    return (0);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    else
        return (1);
}
