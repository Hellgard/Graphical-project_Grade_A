/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

char ***get_info_2(char **info, char sep_1, char sep_2, char *filepath)
{
    char ***arr_info;
    int i = 0;

    arr_info = my_calloc(matrix_len(info) + 100, (sizeof(char **)));
    while (info [i] != NULL) {
        arr_info[i] = save_word(info[i], sep_2, filepath);
        i++;
    }
    arr_info[i] = NULL;
    free_str_arr(info);
    return (arr_info);
}

char ***get_info(char *filepath, char sep_1, char sep_2)
{
    int fd = open(filepath, O_RDONLY);
    char *text = save_text(fd, filepath);
    char **info;
    char ***arr_info;
    if (my_strlen(text) > 1) {
        info = save_word(text, sep_1, filepath);
        close(fd);
        return (get_info_2(info, sep_1, sep_2, filepath));
    }
    else {
        arr_info = malloc(sizeof(char **) * 2);
        arr_info[0] = NULL;
        close(fd);
    }
    return (arr_info);
}

void errase_prev_quest(all_var *all)
{
    quest_t *tmp = all->game->quest_list;
    quest_t *head;

    if (tmp->str != NULL) {
        while (tmp->str != NULL) {
            head = tmp;
            tmp = tmp->next;
            free(head);
        }
        all->game->quest_list = malloc(sizeof(quest_t));
    }
}

void errase_prev_inventory(all_var *all)
{
    t_info_inventory *tmp;
    int i = 0;

    while (i < 4) {
        tmp = all->inventory[i]->next;
        while (tmp != NULL) {
            if (tmp->type != -1) {
                tmp->in_use = 0;
                tmp->type = -1;
                tmp->quantity = 0;
            }
            tmp = tmp->next;
        }
        i++;
    }
}

void load_all(all_var *all)
{
    char *file_game = my_strcat("./saved_games/save_game_",
    my_return_char(all->var->current_game));
    errase_prev_quest(all);
    reset_game(all);
    errase_prev_inventory(all);
    load_var(all, file_game);
    load_quest(all, file_game);
    load_inventory(all, file_game);
    check_boss_load(all, all->game->enemy);
}

void load_general(all_var *all)
{
    char *filepath = "./saved_games/save_general";
    char ***arr_info = get_info(filepath, '\n', ' ');
    int i = 0;
    int j = 0;

    while (i < 3) {
        if (arr_info[j][1] != NULL) {
            all->var->list_name_saved[i] = arr_info[j][1];
            all->var->list_saved[i] = my_getnbr(arr_info[j + 1][1]);
        }
        else {
            all->var->list_name_saved[i] = "";
            all->var->list_saved[i] = 0;
        }
        i++;
        j += 2;
    }
}
