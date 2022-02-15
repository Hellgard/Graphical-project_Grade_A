#include "hunter.h"

void clock_sprite(sfTime time, sfClock *clock, sfIntRect *select_duck)
{
    time = sfClock_getElapsedTime(clock);

    if (sfTime_asSeconds(time) > 0.2) {
        change_duck(select_duck);
        sfClock_restart(clock);
    }
}

void draw_sprite_Part_one(sfRenderWindow* window, sfSprite *duck, sfSprite *dog, sfSprite *back_sprite)
{
    sfRenderWindow_drawSprite(window, back_sprite, NULL);
    sfRenderWindow_drawSprite(window, duck, NULL);
    sfRenderWindow_drawSprite(window, dog, NULL);
}

void draw_sprite_Part_two(sfRenderWindow* window, sfSprite *swan, int i)
{
    sfRenderWindow_drawSprite(window, swan, NULL);
}

void sprite_position_swan(sfSprite *swan)
{
    int x = 700;
    int y  = 140;
    sfVector2f vector = {x, y};

    sfSprite_setPosition(swan, vector);
}

void Part_two()
{
    sfRenderWindow* window;
    sfIntRect select_duck = {0,0,110,110};
    sfClock *clock = sfClock_create();
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    sfSprite *back_sprite = create_background("Images/back.png");
    sfSprite *duck = create_duck();
    sfSprite *swan = create_swan();
    sfSprite *dog = create_dog("Images/dog_hunt.png");
    sprite_position_duck(duck);
    sfVector2f vector = {500, 530};
    sfVector2f Scale = {0.4, 0.4};
    sfSprite_setPosition(dog, vector);
    sfSprite_setScale(dog, Scale);
    window = create_window(window);
    int x = 5;
    int y = 0;
    int i = 0;
    int p;
    int k;

    if (window != NULL) {
        while (sfRenderWindow_isOpen(window)) {
            sfRenderWindow_display(window);
            y = event_basics(duck, swan, window, y);
            p = y;
            clock_sprite(time, clock, &select_duck);
            i = sprite_move_duck(duck, select_duck, x, i, y);
            if (i == 1) {
                x = 5;
                y = 0;
                i = 0;
                k++;
            } if (k >= 3) {
                sfRenderWindow_close(window);
                main_menu();
            }
            sfRenderWindow_clear(window, sfBlack);
            draw_sprite_Part_one(window, duck, dog, back_sprite);
            if (p % 6 == 0 && p != 0) {
                draw_sprite_Part_two(window, swan, p);
                x = (rand() % 30 - 4) + p;
                swan = create_swan();
                sprite_position_swan(swan);
            }
            sfRenderWindow_setFramerateLimit(window, 60);
        }
        sfRenderWindow_destroy(window);
    }
}
