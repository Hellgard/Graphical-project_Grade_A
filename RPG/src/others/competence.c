/*
** EPITECH PROJECT, 2022
** competence.c
** File description:
** competence
*/

#include "rpg.h"

void modify_competemces(all_var *all, int competence, int increment, int point)
{
    if (competence == 0 && first_comp->how_many > first_comp->actual_attack +
    increment && first_comp->actual_attack + increment >= 0 && point > 0) {
        all->game->player->competencies->first->actual_attack += increment;
        all->game->player->point -= 1;
    }
    if (competence == 1 && second_comp->how_many > second_comp->actual_attack
    + increment && second_comp->actual_attack + increment >= 0 && point > 0) {
        all->game->player->competencies->second->actual_attack += increment;
        all->game->player->point -= 1;
    }
    if (competence == 2 && third_comp->how_many > third_comp->actual_attack +
    increment && third_comp->actual_attack + increment >= 0 && point > 0) {
        all->game->player->competencies->third->actual_attack += increment;
        all->game->player->point -= 1;
    }
    if (competence == 3 && fourth_comp->how_many > fourth_comp->actual_attack
    + increment && fourth_comp->actual_attack + increment >= 0 && point > 0) {
        all->game->player->competencies->fourth->actual_attack += increment;
        all->game->player->point -= 1;
    }
}

void print_competence_selected2(all_var *all, int competence, float pos_y)
{
    sfVector2f pos = {273, 0};
    float inc_pos = 107;
    pos.y = pos_y + 20;

    if (competence == 2 && third_comp->actual_attack != 0) {
        inc_pos *= (third_comp->actual_attack);
        pos.x += inc_pos;
        csfml_print_sprites(all, all->sprites->reaction_skills, pos);
    }
    if (competence == 3 && fourth_comp->actual_attack != 0) {
        inc_pos *= (fourth_comp->actual_attack);
        pos.x += inc_pos;
        csfml_print_sprites(all, all->sprites->reaction_skills, pos);
    }
}

void print_competence_selected(all_var *all, int competence, float pos_y)
{
    sfVector2f pos = {273, 0};
    float inc_pos = 107;
    pos.y = pos_y + 20;

    if (competence == 0 && first_comp->actual_attack != 0) {
        inc_pos *= (first_comp->actual_attack);
        pos.x += inc_pos;
        csfml_print_sprites(all, all->sprites->reaction_skills, pos);
    }
    if (competence == 1 && second_comp->actual_attack != 0) {
        inc_pos *= (second_comp->actual_attack);
        pos.x += inc_pos;
        csfml_print_sprites(all, all->sprites->reaction_skills, pos);
    }
    print_competence_selected2(all, competence, pos_y);
}

void move_comp(int res, int i, int j, all_var *all)
{
    if (res == 2 && i == 0)
        modify_competemces(all, j, -1, all->game->player->point);
    if (res == 2 && i == 1)
        modify_competemces(all, j, 1, all->game->player->point);
}

void get_skill_selected(all_var *all)
{
    int i = 0;
    int j = 0;
    int res;
    sfVector2f pos_button = {315, 260};

    while (i < 2) {
        pos_button.y = 327;
        j = 0;
        while (j < 4) {
            res = is_button_pressed3(create_button(pos_button.x, pos_button.y
            , 50, 50), all, NULL, (sfVector2f){0, 0});
            move_comp(res, i, j, all);
            print_competence_selected(all, j, pos_button.y);
            pos_button.y += 146;
            j++;
        }
        pos_button.x += 635;
        i++;
    }
}
