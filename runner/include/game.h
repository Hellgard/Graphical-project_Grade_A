/*
** EPITECH PROJECT, 2021
** game.h
** File description:
** header
*/

#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Text.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <unistd.h>
    #include <math.h>

typedef struct backs_s {
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    sfSprite *sprite2;
    sfVector2f pos;
    sfVector2f pos2;
    struct backs_s *next;
    struct backs_s *prev;
}backs_s;

typedef struct enemy_s {
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    struct enemy_s *next;
    struct enemy_s *prev;
}enemy_s;

typedef struct sound_t {
    sfSoundBuffer *buffer;
    sfSound *sound;
}sound_s;

typedef struct player_s {
    int i;
    int jump;
    sound_s jump_sound;
    int mode;
    int clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
}player_s;

typedef struct score_s {
    char *str;
    sfText *Text;
    sfFont *Font;
    sfVector2f pos;

}score_s;

void put_point(score_s *point, char *string);
void put_score(score_s *score);
void start_game(FILE *fd, sfEvent event, sfRenderWindow *window,\
player_s *player);
void do_event(FILE *fd, sfRenderWindow *window, player_s *player, sfEvent event);
void main_menu(FILE *fd, sfRenderWindow *window, player_s *player);
void main_event(FILE *fd, sfRenderWindow *window, player_s *player);
sound_s manage_sound(void);
void print_h(void);
void player_jump_glitch(player_s *player);
int my_putstr(char const *str);
player_s *player_info(int bool);
backs_s *back_info(backs_s *back, int i);
backs_s *manage_back_info(void);
player_s *move_player(player_s *player, sfRenderWindow *window, sfClock *Clock);
void move_backgrounds(sfRenderWindow *window, backs_s *back);
void move_enemy(sfClock *clock, sfRenderWindow *window, enemy_s *enemy, int i);
int player_hit(enemy_s *enemy, player_s *player);
void draw_enemy_sprite(enemy_s *enemy, sfRenderWindow *window);
enemy_s *manage_enemy(FILE *fd);

#endif
