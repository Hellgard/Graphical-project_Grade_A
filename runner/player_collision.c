/*
** EPITECH PROJECT, 2019
** player_collision.c
** File description:
** check the collision between player and enemy
*/

#include "game.h"

void draw_enemy_sprite(enemy_s *enemy, sfRenderWindow *window)
{
    while (enemy->prev != NULL)
        enemy = enemy->prev;
    while (enemy->next != NULL) {
        if (enemy->pos.x < 1920) {
            sfSprite_setPosition(enemy->sprite, enemy->pos);
            sfSprite_setTexture(enemy->sprite, enemy->texture, sfFalse);
            sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
            enemy = enemy->next;
        } else
            enemy = enemy->next;
    }
}

int check_hit(enemy_s *enemy, player_s *player)
{
    if (player->pos.x >= enemy->pos.x && player->pos.x <= enemy->pos.x) {
        if (player->pos.y + 30 >= enemy->pos.y)
            return (1);
    }
    return (0);
}

int player_hit(enemy_s *enemy, player_s *player)
{
    while (enemy->prev != NULL)
        enemy = enemy->prev;
    while (enemy->next != NULL) {
        if (check_hit(enemy, player) == 1)
            return (1);
        else
            enemy = enemy->next;
    }
    return (0);
}

void do_event(FILE *fd, sfRenderWindow *window, player_s *player, sfEvent event)
{
    sfVector2i mouse_pos;
    mouse_pos = sfMouse_getPositionRenderWindow(window);

    if ((mouse_pos.x > 1000 && mouse_pos.x < 1300) && mouse_pos.y > 500) {
        player = player_info(0);
        start_game(fd, event, window, player);
    } else if ((mouse_pos.x > 1400 ) && (mouse_pos.y > 500)) {
        player = player_info(1);
        start_game(fd, event, window, player);
    }
}
