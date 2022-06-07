/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "./../includes/my_library.h"

char **delete_first_line(char **array)
{
    int i = 1;
    int j = 0;
    char **temp = malloc(sizeof(char *) * my_arraylen(array));

    while (array[i] != NULL) {
        temp[j] = my_strdup(array[i]);
        i++;
        j++;
    }
    temp[j] = NULL;
    return (temp);
}

void print_array_strings(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        write(1, array[i], my_strlen(array[i]));
        i++;
    }
}

char **save_matrix(char **matrix)
{
    int i = 0;
    char **temp = my_calloc(my_arraylen(matrix) + 2, sizeof(char *));

    while (matrix[i] != NULL) {
        temp[i] = my_strdup(matrix[i]);
        i++;
    }
    temp[i] = NULL;
    return (temp);
}

int check_size_ext(char **matrix, int i, int j, int n)
{
    if (matrix[i][j] == '*') {
        n++;
    }
    return (n);
}

int check_size(char **matrix, int width, int height)
{
    int i = 0;
    int j = 0;
    int max_width = -1;
    int n = 0;

    for (j = 0; matrix[i] != NULL; i++) {
        while (matrix[i][j] != '\0') {
            n = check_size_ext(matrix, i, j, n);
            j++;
        }
        if (j > max_width)
            max_width = j;
        n = 0;
    }
    if (i != height)
        return (1);
    if (max_width != width)
        return (1);
    return (0);
}
