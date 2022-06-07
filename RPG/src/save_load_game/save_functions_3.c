/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void save_inventory_2(t_info_inventory *tmp, char *cat, int fd)
{
    while (tmp != NULL) {
        if (tmp->type != -1) {
            cat = "";
            cat = my_strdup(tmp->filepath);
            cat = my_strcat(cat, " ");
            cat = my_strcat(cat, my_itoa(tmp->in_use));
            cat = my_strcat(cat, " ");
            cat = my_strcat(cat, my_itoa(tmp->quantity));
            cat = my_strcat(cat, " ");
            cat = my_strcat(cat, my_itoa(tmp->type));
            cat = my_strcat(cat, "\n");
            write(fd, cat, my_strlen(cat));
        }
        tmp = tmp->next;
    }
}

void save_inventory(all_var *all, char *file_game)
{
    int i = 0;
    t_info_inventory *tmp;
    int fd = open (my_strcat(file_game, "/var_inventory"),
    O_WRONLY | O_CREAT | O_TRUNC, 0777);
    char *cat;
    while (i < 4 && fd != -1) {
        tmp = all->inventory[i]->next;
        save_inventory_2(tmp, cat, fd);
        i++;
    }
    close(fd);
}
