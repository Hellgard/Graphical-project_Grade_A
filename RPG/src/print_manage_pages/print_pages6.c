/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void display_game_quest(all_var *all)
{
    sfVector2f pos = {1525, 50};
    quest_t *tmp = NULL;

    while (all->game->quest_list->prev != NULL)
        all->game->quest_list = all->game->quest_list->prev;
    tmp = all->game->quest_list;
    while (tmp->str != NULL) {
        if (tmp->is_actual == 1) {
            csfml_print_num(all, 20, pos,  tmp->state);
            pos.x += 10;
            csfml_print_text(all, 20, pos, "/");
            pos.x += 10;
            csfml_print_num(all, 20, pos,  tmp->how_many);
            pos.x += 10;
            csfml_print_text(all, 20, pos,  tmp->str);
            pos.x -= 30;
            pos.y += 30;
        }
        tmp = tmp->next;
    }
}

void print_info_combat(all_var *all)
{
    int i = 0;
    char **text = my_str_to_array(all->game->Combat_ambiance->combat_infos,
    '\n');

    for (; text[i + 1] != NULL; i++);
    if (i >= 3) {
        csfml_print_text(all, 60, (sfVector2f){50, 740}, text[i - 3]);
        csfml_print_text(all, 60, (sfVector2f){50, 840}, text[i - 2]);
        csfml_print_text(all, 60, (sfVector2f){50, 940}, text[i - 1]);
    } else if (i >= 2) {
        csfml_print_text(all, 60, (sfVector2f){50, 740}, text[i - 2]);
        csfml_print_text(all, 60, (sfVector2f){50, 840}, text[i - 1]);
    } else
        csfml_print_text(all, 60, (sfVector2f){50, 740}, text[i]);
}

void print_battle(all_var *all)
{
    sfTime time;
    int i = 0;

    sfRenderWindow_drawSprite(all->windows->window,
    all->game->scene->Combat_ambiance, NULL);
    sfRenderWindow_drawSprite(all->windows->window,
    all->game->enemy[all->game->attack_id]->sprite, NULL);
    draw_attacks(all, all->windows->window);
    buttons_battle(all);
    print_bars_battle(all);
    print_info_combat(all);
    event_combat(all);
}

void enemy_text(all_var *all, int life_taken, char *str, int i)
{
    comb_amb->combat_infos = my_strcat(comb_amb->combat_infos,
    "Enemy attacked with ");
    comb_amb->combat_infos = my_strcat(comb_amb->combat_infos,
    all->game->enemy[all->game->attack_id]->competencies[i]);
    comb_amb->combat_infos = my_strcat(comb_amb->combat_infos, "\n");
    comb_amb->combat_infos = my_strcat(comb_amb->combat_infos, "You blocked ");
    comb_amb->combat_infos = my_strcat(comb_amb->combat_infos, str);
    comb_amb->combat_infos = my_strcat(comb_amb->combat_infos, " damages\n");
    comb_amb->combat_infos = my_strcat(comb_amb->combat_infos, "You lose ");
    intToStr(life_taken, str, 0);
    comb_amb->combat_infos = my_strcat(comb_amb->combat_infos, str);
    comb_amb->combat_infos = my_strcat(comb_amb->combat_infos, "hp\n");
}

void enemy_attack_text(all_var *all, int i, int life_taken)
{
    char *str = malloc(sizeof(char) * 4);

    if (all->game->player->defense / 10 > 0)
        intToStr(all->game->player->defense / 10, str, 0);
    else
        str = my_strdup("0");
    enemy_text(all, life_taken, str, i);
}
