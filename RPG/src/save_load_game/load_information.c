/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void load_inventory(all_var *all, char *file_game)
{
    char *filepath = my_strcat(file_game, "/var_inventory");
    char ***arr_info = get_info(filepath, '\n', ' ');
    t_info_inventory *tmp;
    int i = 0;

    while (arr_info[i] != NULL) {
        print_array_strings(arr_info[i]);
        add_element_inventory(all, arr_info[i][0], 1);
        tmp = get_pointer_inventory(all, arr_info[i][0],
        my_getnbr(arr_info[i][2]));
        if (tmp != NULL) {
            tmp->in_use = atoi(arr_info[i][1]);
            tmp->quantity = atoi(arr_info[i][2]);
            tmp->type = atoi(arr_info[i][3]);
        }
        i++;
    }
}

void load_var_2(all_var *all, char ***arr_info)
{
    all->game->scene->elems->player[0]->x = my_getnbr(arr_info[8][1]);
    all->game->scene->elems->player[0]->y = my_getnbr(arr_info[9][1]);
    all->game->scene->elems->player[0]->pos.x =
    ((all->game->scene->elems->player[0]->x) * (all->game->scene->map_size_x /
    all->game->scene->tile_size_x) * all->game->scene->scale_1);
    all->game->scene->elems->player[0]->pos.y =
    ((all->game->scene->elems->player[0]->y) * (all->game->scene->map_size_y /
    all->game->scene->tile_size_y) * all->game->scene->scale_2);
    all->game->scene->elems->player[0]->pos_target =
    all->game->scene->elems->player[0]->pos;
    all->game->player->competencies->first->actual_attack =
    my_getnbr(arr_info[10][1]);
    all->game->player->competencies->second->actual_attack =
    my_getnbr(arr_info[11][1]);
    all->game->player->competencies->third->actual_attack =
    my_getnbr(arr_info[12][1]);
    all->game->player->competencies->fourth->actual_attack =
    my_getnbr(arr_info[13][1]);
    all->game->player->xp =
    my_getnbr(arr_info[14][1]);
    all->game->player->palier =
    my_getnbr(arr_info[15][1]);
     all->game->player->max_life =
    my_getnbr(arr_info[16][1]);
    sfSprite_setPosition(all->game->scene->elems->player[0]->sprite,
    all->game->scene->elems->player[0]->pos);
}

void load_var(all_var *all, char *file_game)
{
    char *filepath = my_strcat(file_game, "/var_info");
    char ***arr_info = get_info(filepath, '\n', ' ');
    free(filepath);

    if (arr_info[0] != NULL) {
        all->game->player->life = my_getnbr(arr_info[0][1]);
        all->game->player->defense = my_getnbr(arr_info[1][1]);
        all->game->player->attack = my_getnbr(arr_info[2][1]);
        all->var->shield = my_getnbr(arr_info[3][1]);
        all->var->weapon = my_getnbr(arr_info[4][1]);
        all->var->player = my_getnbr(arr_info[5][1]);
        all->game->player->level = my_getnbr(arr_info[6][1]);
        all->game->parse = my_str_to_array(open_read_file("config.txt"), '\n');
        all->game->scene = create_scene(all, arr_info[7][1], all->game->parse);
        all->game->clock = sfClock_create();
        all->var->prev_id_map = arr_info[7][1];
        load_var_2(all, arr_info);
    }
}

void load_quest_2(quest_t *quest, char ***arr_info, int j)
{
    int k = 0;
    int i = 0;
    quest->id = my_strdup(arr_info[j][0]);
    quest->str = my_strdup(arr_info[j][1]);
    quest->how_many = my_getnbr(arr_info[j][2]);
    quest->is_actual = my_getnbr(arr_info[j][3]);
    quest->state = my_getnbr(arr_info[j][4]);
    quest->elem_quest = malloc(sizeof(elem_quest_t *) * quest->how_many);
    i = 5;
    while (i < 6 && arr_info[j][i] != NULL) {
        quest->elem_quest[k] = malloc(sizeof(elem_quest_t));
        quest->elem_quest[k]->id = my_strdup(arr_info[j][i]);
        quest->elem_quest[k]->quest_id = my_strdup(arr_info[j][i + 1]);
        quest->elem_quest[k]->is_actual = my_getnbr(arr_info[j][i + 2]);
        k++;
        i += 2;
    }
    j++;
}

void load_quest(all_var *all, char *file_game)
{
    char *filepath = my_strcat(file_game, "/var_quest");
    char ***arr_info = get_info(filepath, '\n', ':');
    int j = 0;
    quest_t *quest = all->game->quest_list;
    while (arr_info[j] != NULL) {
        load_quest_2(quest, arr_info, j);
        quest->next = malloc(sizeof(quest_t));
        quest->next->prev = quest;
        quest = quest->next;
        quest->str = NULL;
        quest->next = NULL;
        j++;
    }
}
