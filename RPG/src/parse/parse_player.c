/*
** EPITECH PROJECT, 2021
** parse.c
** File description:
** parse
*/

#include "rpg.h"

void parse_competencies(comp_t *comp, char *parse, int x, int y)
{
    char **info = my_str_to_array(parse, ':');
    comp->attacks = my_str_to_array(info[2], ',');
    comp->how_many = my_getnbr(info[0]);
    comp->actual_attack = my_getnbr(info[1]);
    comp->attacks_name = my_str_to_array(info[4], ',');
    char **arr_attacks = my_str_to_array(info[3], ',');
    comp->attacks_damages = malloc(sizeof(int) * (comp->how_many));
    comp->attack_sprite = malloc(sizeof(sfSprite *) * (comp->how_many + 1));
    int i;

    for (i = 0; i < comp->how_many; i++) {
        comp->attack_sprite[i] = malloc(sizeof(sfSprite *));
        comp->attack_sprite[i] = obj_create(x, y, comp->attacks[i]);
        comp->attacks_damages[i] = my_getnbr(arr_attacks[i]);
    }
    comp->attack_sprite[i] = NULL;
}

void parse_info_player(player_t *player, char **player_info)
{
    player->level = my_getnbr(player_info[0]);
    player->xp = my_getnbr(player_info[1]);
    player->palier = my_getnbr(player_info[2]);
    player->point = 0;
    player->attack = my_getnbr(player_info[4]);
    player->defense = my_getnbr(player_info[5]);
    player->speed = my_getnbr(player_info[6]);
    player->life = my_getnbr(player_info[3]);
    player->max_life = my_getnbr(player_info[3]);
}

player_t *parse_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    char **parse = my_str_to_array(open_read_file("player_config.txt"), '\n');
    char **player_info = my_str_to_array(parse[0], ':');
    parse_info_player(player, player_info);
    player->competencies = malloc(sizeof(competencies_t));
    player->competencies->first = malloc(sizeof(comp_t));
    player->competencies->second = malloc(sizeof(comp_t));
    player->competencies->third = malloc(sizeof(comp_t));
    player->competencies->fourth = malloc(sizeof(comp_t));
    parse_competencies(player->competencies->first, parse[1], 1200, 715);
    parse_competencies(player->competencies->second, parse[2], 1522, 715);
    parse_competencies(player->competencies->third, parse[3], 1200, 880);
    parse_competencies(player->competencies->fourth, parse[4], 1522, 880);
    return player;
}

Combat_ambiance_t *parse_ambiance(void)
{
    Combat_ambiance_t *sprites_amb = malloc(sizeof(Combat_ambiance_t));
    sprites_amb->fight = obj_create(1200, 715, "image/Fight_Button.png");
    sprites_amb->inventory = obj_create(1542, 715
    , "image/Inventory_Button.png");
    sprites_amb->escape = obj_create(1200, 880, "image/Escape_Button.png");
    sprites_amb->fight_first = obj_create(1200, 715, "image/Red_button.png");
    sprites_amb->fight_second = obj_create(1542, 715
    , "image/Green_button.png");
    sprites_amb->fight_third = obj_create(1200, 880
    , "image/Yellow_button.png");
    sprites_amb->fight_fourth = obj_create(1542, 880, "image/Blue_Button.png");
    return sprites_amb;
}
