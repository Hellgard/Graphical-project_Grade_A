/*
** EPITECH PROJECT, 2021
** manage_info.c
** File description:
** manage
*/

#include "game.h"
#include <stdio.h>

int enemy_count(char *buff)
{
    int enemy = 0;

    for (int i = 0; buff[i]; i++) {
        if (buff[i] == '2')
            enemy++;
    }
    return (enemy);
}

void add_en(char *map, int enemy_count, enemy_s *enemy)
{
    int i = 0;

    for (int count = 0; count < enemy_count; i++) {
        if (map[i] == '2') {
            enemy->pos.y = 860;
            enemy->pos.x = i * 100;
            enemy->sprite = sfSprite_create();
            enemy->texture = sfTexture_createFromFile("image/enemy.png", NULL);
            count++;
        }
        if (map[i] == '2' && enemy->next) {
            enemy = enemy->next;
            enemy->pos.x = i * 100;
        }
    }
}

enemy_s *add_enemy(char *map, int enemy_count, enemy_s *enemy)
{
    int i = 0;

    for (enemy->prev = NULL; i < enemy_count - 1; i++) {
        enemy->next = malloc(sizeof(enemy_s));
        enemy->next->prev = enemy;
        enemy = enemy->next;
    }
    enemy->next = NULL;
    while (enemy->prev != NULL)
        enemy = enemy->prev;
    add_en(map, enemy_count, enemy);
    return enemy;
}

int check_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '2')
            return (1);
        i++;
    }
    return (0);
}

enemy_s *manage_enemy(FILE *fd)
{
    char *line = NULL;
    size_t size;
    int enemy_counter;
    enemy_s *enemy = malloc(sizeof(enemy_s));

    getline(&line, &size, fd);
    while (check_str(line) == 0)
        getline(&line, &size, fd);
    enemy_counter = enemy_count(line);
    enemy = add_enemy(line, enemy_counter, enemy);
    return enemy;
}
