/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "./../includes/my_library.h"

char **add_in_array(char **array, char *str)
{
    int i = 0;
    char **temp = malloc(sizeof(char *) * (my_arraylen(array) + 20));
    i = 0;
    while (array[i] != NULL) {
        temp[i] = array[i];
        i++;
    }
    temp[i] = str;
    temp[i + 1] = NULL;
    array = temp;
    return (temp);
}

void my_putstr(char *str)
{
    int len = 0;

    if (str) {
        len = my_strlen(str);
        if (len > 0)
            write(1, str, len);
    }
}

int matrix_len(char **matrix)
{
    int len = 0;

    while (matrix[len] != NULL)
        len++;
    return (len - 1);
}