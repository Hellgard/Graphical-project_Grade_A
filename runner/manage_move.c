/*
** EPITECH PROJECT, 2021
** background_info.c
** File description:
** back
*/

#include "game.h"

player_s *move_player(player_s *player, sfRenderWindow *window, sfClock *Clock)
{
    if (sfClock_getElapsedTime(Clock).microseconds > player->clock) {
        player->rect.left += 200;
        sfClock_restart(Clock);
    } if (player->rect.left >= 600 && player->jump == 0) {
        player->rect.left = 0;
    } if (player->jump == 1)
        player_jump_glitch(player);
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    return (player);
}

void move_backgrounds(sfRenderWindow *window, backs_s *back)
{
    long int i = 0;

    while (back->prev != NULL)
        back = back->prev;
    for (;(back); back = back->next) {
        back->pos.x = back->pos.x - i;
        back->pos2.x = back->pos2.x - i;
        if (back->pos.x <= -1920)
            back->pos.x = 1920;
        if (back->pos2.x <= -1920)
            back->pos2.x = 1920;
        sfSprite_setPosition(back->sprite, back->pos);
        sfSprite_setPosition(back->sprite2, back->pos);
        sfSprite_setTexture(back->sprite, back->texture, sfFalse);
        sfSprite_setTexture(back->sprite2, back->texture, sfFalse);
        sfRenderWindow_drawSprite(window, back->sprite, NULL);
        sfRenderWindow_drawSprite(window, back->sprite2, NULL);
        i += 1;
    }
}

char *get_string(int i)
{
    char *string = malloc(sizeof(char ) * 3);
    string[0] = '0';
    string[1] = '0' + i;
    string[2] = '\0';
    return string;
}

void move_enemy(sfClock *clock, sfRenderWindow *window, enemy_s *enemy, int i)
{
    score_s *score = malloc(sizeof(score_s));
    score_s *point = malloc(sizeof(score_s));
    char *string = get_string(i);

    while (enemy->prev != NULL)
        enemy = enemy->prev;
    if (sfClock_getElapsedTime(clock).microseconds > 10000) {
        while (enemy->next != NULL) {
            enemy->pos.x -= 4;
            enemy = enemy->next;
        }
        enemy->pos.x -= 60;
    }
    put_score(score);
    put_point(point, string);
    draw_enemy_sprite(enemy, window);
    sfRenderWindow_drawText(window, score->Text, NULL);
    sfRenderWindow_drawText(window, point->Text, NULL);
}
