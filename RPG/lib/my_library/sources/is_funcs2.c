/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "./../includes/my_library.h"

int is_str_in_array(char **array, char *to_find)
{
    int i = 0;
    int instr = 0;

    while (array[i] != NULL) {
        if (is_str_in_str(array[i], to_find) == 0)
            return (i);
        i++;
    }
    return (-1);
}
