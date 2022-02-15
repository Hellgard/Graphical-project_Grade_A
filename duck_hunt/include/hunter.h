#include <stddef.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <unistd.h>

    #define WIDTH 1200
    #define HEIGHT 700

void draw_sprite_main(sfRenderWindow* window, sfSprite *dog, sfSprite *back_sprite);
void mainwindow_view(sfRenderWindow *mainWindow, sfSprite *back_sprite, sfSprite *dog);
void main_event(sfRenderWindow *window);
void change_dog (sfIntRect *select_dog);
void clock_sprite_main(sfTime time, sfClock *clock, sfIntRect *select_dog);
sfSprite *sprite_move_dog(sfSprite *dog, sfIntRect select_dog, sfRenderWindow* window, sfSprite *back_sprite);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int event_one(sfVector2i mouse_pos, sfVector2f pos_sprite, int j, sfSprite *duck);
sfSprite *create_swan();
sfSprite *create_dog(char *pathname);
sfRenderWindow *create_window(sfRenderWindow* window);
sfSprite *create_background(char *Path_name);
void change_duck (sfIntRect *select_duck);
sfSprite *create_duck();
int event_basics(sfSprite *duck, sfSprite *swan, sfRenderWindow *window, int j);
void clock_sprite(sfTime time, sfClock *clock, sfIntRect *select_duck);
void draw_sprite_Part_one(sfRenderWindow* window, sfSprite *duck, sfSprite *dog, sfSprite *back_sprite);
void sprite_position_duck(sfSprite *duck);
int sprite_move_duck(sfSprite *duck, sfIntRect select_duck, int x, int i, int y);
void Part_one();
void Part_two();
void main_menu();
