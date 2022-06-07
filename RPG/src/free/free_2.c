/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void free_inventory(all_var *all)
{
    int i = 0;
    t_info_inventory *tmp;
    t_info_inventory *head;
    while (i < 4) {
        head = all->inventory[i]->next;
        while (head != NULL) {
            tmp = head;
            head = head->next;
            free(tmp);
        }
        free(head);
        i++;
    }
}

void free_arr_arr_sprites(sfSprite ***arr_sprite)
{
    int i = 0;
    int j = 0;

    while (arr_sprite[i] != NULL) {
        j = 0;
        while (arr_sprite[i][j] != NULL) {
            sfSprite_destroy(arr_sprite[i][j]);
            j++;
        }
        free(arr_sprite[i]);
        i++;
    }
    free(arr_sprite);
}
