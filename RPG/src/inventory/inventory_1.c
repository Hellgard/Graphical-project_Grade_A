/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

char **get_item_properties(all_var *all)
{
    char *filepath = my_strcat("./itemprop/item",
    my_return_char(get_slot_inventory(all)->type));
    int fd = open(filepath, O_RDONLY);
    char **info = save_word(save_text(fd, filepath), '\n', filepath);
    free(filepath);
    close(fd);
    return (info);
}

void create_list_inventory(t_info_inventory *file)
{
    t_info_inventory *tmp = file;
    int i = -1;
    while (i < 15) {
        i++;
        tmp->type = -1;
        tmp->quantity = 0;
        tmp->next = init_linked_inventory(i);
        tmp = tmp->next;
    }
    tmp->next = NULL;
}

void add_element_inventory(all_var *all, char *filepath, int quantity)
{
    int *info = get_element_file(filepath);
    int element_type = info[0];
    int element = info[1];
    t_info_inventory *tmp = all->inventory[element_type]->next;

    while (tmp != NULL && tmp->type != -1 && (tmp->type != element
    || tmp->quantity >= 10))
        tmp = tmp->next;
    if (tmp != NULL) {
        tmp->filepath = my_strdup(filepath);
        tmp->type = element;
        tmp->quantity += quantity;
    }
    else {
        csfml_print_text(all, 80, (sfVector2f) {1010, 500},
        "Not enough space, delete some elements");
    }
    free(info);
}

t_info_inventory *get_pointer_inventory(all_var *all,
char *filename, int quantity)
{
    t_info_inventory *tmp;
    int i = 0;
    int result = 0;
    while (i < 4) {
        tmp = all->inventory[i]->next;
        while (tmp != NULL) {
            result = tmp->quantity + quantity;
            if (tmp->type != -1 && result < 11 &&
            strcmp(tmp->filepath, filename) == 0)
                return (tmp);
            tmp = tmp->next;
        }
        i++;
    }
    return (NULL);
}

t_info_inventory *get_slot_inventory(all_var *all)
{
    int inv_page = all->var->inventory_page;
    t_info_inventory *tmp = all->inventory[inv_page]->next;
    int i = 0;

    while (tmp != NULL && i != all->var->item_selected){
        i++;
        tmp = tmp->next;
    }
    return (tmp);
}
