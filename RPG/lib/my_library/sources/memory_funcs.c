/*
** EPITECH PROJECT, 2021
** B-PSU-200-BAR-2-1-mysokoban-sebastia.gomez-dolc
** File description:
** main.c
*/

#include "./../includes/my_library.h"

void *my_memset(void *s, int c, int n)
{
    char *tmp = NULL;
    int	i = 0;

    tmp = s;
    i = 0;
    while (i < n)
        tmp[i++] = c;
    return (tmp);
}

void *my_calloc(int nmemb, int size)
{
    void *ptr = NULL;

    if (!(ptr = malloc(nmemb * size)))
        return (NULL);
    ptr = my_memset(ptr, 0, nmemb * size);
    return (ptr);
}
