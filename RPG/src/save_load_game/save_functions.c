/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"
#define first_attack all->game->player->competencies->first->actual_attack)
#define second_attack all->game->player->competencies->second->actual_attack)
#define third_attack all->game->player->competencies->third->actual_attack)
#define fourt_attack all->game->player->competencies->fourth->actual_attack)

void save_var_2(all_var *all, char *cat, int fd)
{
    cat = my_strcat("8.Map_ID: ", all->game->scene->id);
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("9.PosX: ",
    my_itoa(all->game->scene->elems->player[0]->x));
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("10.PosY: ",
    my_itoa(all->game->scene->elems->player[0]->y));
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("11.Skill_1: ", my_itoa(first_attack);
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("12.Skill_2: ", my_itoa(second_attack);
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("13.Skill_3: ", my_itoa(third_attack);
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("14.Skill_4: ", my_itoa(fourt_attack);
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("15.XP: ", my_itoa(all->game->player->xp));
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("16.Palier: ", my_itoa(all->game->player->palier));
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
    cat = my_strcat("17.Max_Life: ", my_itoa(all->game->player->max_life));
    write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
}

void save_var(all_var *all, char *file_game)
{
    int fd = open (my_strcat(file_game, "/var_info"),
    O_WRONLY | O_CREAT | O_TRUNC, 0777);
    char *cat;
    if (fd != -1) {
        cat = my_strcat("1.Health: ", my_itoa(all->game->player->life));
        write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
        cat = my_strcat("2.Strength: ", my_itoa(all->game->player->defense));
        write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
        cat = my_strcat("3.Armour: ", my_itoa(all->game->player->attack));
        write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
        cat = my_strcat("4.Shield: ", my_itoa(all->var->shield));
        write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
        cat = my_strcat("5.Weapon: ", my_itoa(all->var->weapon));
        write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
        cat = my_strcat("6.Player: ", my_itoa(all->var->player));
        write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
        cat = my_strcat("7.Level: ", my_itoa(all->game->player->level));
        write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
        save_var_2(all, cat, fd);
    }
    close(fd);
}

char *save_quests_2(quest_t *quest, char *cat)
{
    int i = 0;
    cat = my_strcat(cat, quest->id);
    cat = my_strcat(cat, ":");
    cat = my_strcat(cat, quest->str);
    cat = my_strcat(cat, ":");
    cat = my_strcat(cat, my_itoa(quest->how_many));
    cat = my_strcat(cat, ":");
    cat = my_strcat(cat, my_itoa(quest->is_actual));
    cat = my_strcat(cat, ":");
    cat = my_strcat(cat, my_itoa(quest->state));
    while (quest->elem_quest[i] != NULL) {
        cat = my_strcat(cat, ":");
        cat = my_strcat(cat, quest->elem_quest[i]->id);
        cat = my_strcat(cat, ":");
        cat = my_strcat(cat, quest->elem_quest[i]->quest_id);
        cat = my_strcat(cat, ":");
        cat = my_strcat(cat, my_itoa(quest->elem_quest[i]->is_actual));
        i++;
    }
    return (cat);
}

void save_quests(all_var *all, char *file_game)
{
    int fd = open (my_strcat(file_game, "/var_quest"),
    O_WRONLY | O_CREAT | O_TRUNC, 0777);
    char *cat;
    int i = 0;
    while (all->game->quest_list->prev != NULL)
        all->game->quest_list = all->game->quest_list->prev;
    quest_t *quest = all->game->quest_list;

    while (quest->str != NULL) {
        i = 0;
        cat = "";
        cat = save_quests_2(quest, cat);
        write(fd, my_strcat(cat, "\n"), my_strlen(cat) + 1);
        quest = quest->next;
    }
    close(fd);
}
