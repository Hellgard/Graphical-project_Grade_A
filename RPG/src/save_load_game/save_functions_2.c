/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void save_all(all_var *all)
{
    char *file_game = my_strcat("./saved_games/save_game_",
    my_itoa(all->var->current_game));
    save_quests(all, file_game);
    save_inventory(all, file_game);
    save_var(all, file_game);
}

void save_general(all_var *all)
{
    int fd = open ("./saved_games/save_general",
    O_WRONLY | O_CREAT | O_TRUNC, 0777);
    char *cat = my_strcat("Name_game1_save: ", all->var->list_name_saved[0]);
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("List_game1_save: ", my_itoa(all->var->list_saved[0]));
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("Name_game2_save: ", all->var->list_name_saved[1]);
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("List_game2_save: ", my_itoa(all->var->list_saved[1]));
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("Name_game3_save: ", all->var->list_name_saved[2]);
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("List_game3_save: ", my_itoa(all->var->list_saved[2]));
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    close(fd);
}

void delete_var(all_var *all, char *file_game)
{
    int fd = open (my_strcat(file_game, "/var_info"),
    O_WRONLY | O_CREAT | O_TRUNC, 0777);
    write(fd, " ", 1);
    close(fd);
}

void delete_inventory(all_var *all, char *file_game)
{
    int fd = open (my_strcat(file_game, "/var_inventory"),
    O_WRONLY | O_CREAT | O_TRUNC, 0777);
    write(fd, " ", 1);
    close(fd);
}

void delete_quest(all_var *all, char *file_game)
{
    int fd = open (my_strcat(file_game, "/var_quest"),
    O_WRONLY | O_CREAT | O_TRUNC, 0777);
    write(fd, " ", 1);
    close(fd);
}

void delete_all(all_var *all)
{
    char *file_game = my_strcat("./saved_games/save_game_",
    my_itoa(all->var->item_to_delete));
    all->var->list_name_saved[all->var->item_to_delete] = "";
    delete_inventory(all, file_game);
    delete_var(all, file_game);
    delete_quest(all, file_game);
}
