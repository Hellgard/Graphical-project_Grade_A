/*
** EPITECH PROJECT, 2021
** parse.c
** File description:
** parse
*/

#include "rpg.h"

char **parse_info(char *to_get, char sep, char **config)
{
    char **arr;
    int i = 0;
    int j = 0;

    for (; my_strcmp(config[i], to_get) != 0; i++);
    i += 1;
    arr = malloc(sizeof(char *) * (arr_lenght_sep(config, '-', i) + 1));
    for (; config[i][0] != '-'; i++) {
        arr[j] = my_strdup(config[i]);
        j++;
    }
    arr[j] = NULL;
    return arr;
}

char **parse_elem(char **Elements, char ind, int i)
{
    char **player;

    while (compare_char(Elements[i][0], ind) != 0 && Elements[i + 1])
        i++;
    player = my_str_to_array(Elements[i], ':');
    return player;
}

void get_text(obj_t *elem, char **player)
{
    char **text;
    int len;
    int i;

    if (my_strcmp(player[3], "none") == 0) {
        elem->texts = malloc(sizeof(char *) * 1);
        elem->texts[0] = NULL;
    }
    if (my_strcmp(player[3], "none") != 0) {
        text = my_str_to_array(player[3], ',');
        for (len = 0; text[len]; len++);
        elem->texts = malloc(sizeof(char *) * (len + 1));
        for (i = 0; text[i]; i++)
            elem->texts[i] = my_strdup(text[i]);
        elem->texts[i] = NULL;
    }
}

void loop_parse(combat_t **enemy, char **arr, int i, char **parse)
{
    for (i = 0; arr[i]; i++) {
        enemy[i] = malloc(sizeof(combat_t));
        parse = my_str_to_array(arr[i], ':');
        enemy[i]->id = my_strdup(parse[0]);
        enemy[i]->sprite = obj_create(1100, 50, my_strdup(parse[1]));
        enemy[i]->level = my_getnbr(parse[2]);
        enemy[i]->life = my_getnbr(parse[3]);
        enemy[i]->li = my_getnbr(parse[3]);
        enemy[i]->speed = my_getnbr(parse[4]);
        enemy[i]->how_many_comp = my_getnbr(parse[5]);
        enemy[i]->competencies = my_str_to_array(parse[6], ',');
        enemy[i]->loots = my_str_to_array(parse[7], ',');
        enemy[i]->gaved_xp = my_getnbr(parse[8]);
        enemy[i]->isBoss = my_getnbr(parse[9]);
        enemy[i]->attacks_damages = my_str_to_array(parse[10], ',');
        free(parse);
    }
    enemy[i] = NULL;
}

combat_t **parse_enemy(void)
{
    int i;
    combat_t **enemy;
    char **parse;
    char **arr = my_str_to_array(open_read_file("Combat_config.txt"), '\n');

    for (i = 0; arr[i]; i++);
    enemy = malloc(sizeof(combat_t *) * (i + 1));
    loop_parse(enemy, arr, 0, parse);
    return enemy;
}
