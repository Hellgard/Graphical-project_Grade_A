#include "hunter.h"

void sprite_position_duck(sfSprite *duck)
{
    int x = -110;
    int y  = 0;
    sfVector2f vector = {x, y};
    sfSprite_setPosition(duck, vector);
}

int sprite_move_duck(sfSprite *duck, sfIntRect select_duck, int x, int i, int y)
{
    x = x + y;
    sfVector2f move = {x, 0};
    sfSprite_move(duck, move);

    if (sfSprite_getPosition(duck).x > 1200) {
        i += 1;
        int p = -110;
        int j = (rand() % 400 - 4) + 5;
        sfVector2f vector = {p, j};
        sfSprite_setPosition(duck, vector);
    }
    sfSprite_setTextureRect(duck, select_duck);
    return i;
}

int event_basics(sfSprite *duck, sfSprite *swan, sfRenderWindow *window, int j)
{
    sfEvent event;
    sfVector2i mouse_pos;
    sfVector2f pos_sprite;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            main_menu();
        }
        if (event.type == sfEvtMouseButtonPressed) {
            mouse_pos = sfMouse_getPositionRenderWindow(window);
            pos_sprite = sfSprite_getPosition(duck);
            j = event_one(mouse_pos, pos_sprite, j, duck);
        }
    }
    return j;
}

sfSprite *create_dog(char *pathname)
{
    sfTexture *Dog_texture = sfTexture_createFromFile(pathname,NULL);
    sfSprite *Dog_Sprite = sfSprite_create();
    sfSprite_setTexture(Dog_Sprite, Dog_texture, 0);
    sfVector2f scale = {3, 3};
    sfSprite_setScale(Dog_Sprite, scale);
    return (Dog_Sprite);

}

void Part_one()
{
    sfRenderWindow* window;
    sfIntRect select_duck = {0,0,110,110};
    sfClock *clock = sfClock_create();
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    sfSprite *back_sprite = create_background("Images/back.png");
    sfSprite *duck = create_duck();
    sfSprite *dog = create_dog("Images/dog_hunt.png");
    sprite_position_duck(duck);
    sfVector2f vector = {500, 530};
    sfVector2f Scale = {0.4, 0.4};
    sfSprite_setPosition(dog, vector);
    sfSprite_setScale(dog, Scale);
    window = create_window(window);
    sfSprite *swan;
    int x = 5;
    int y = 0;
    int i = 0;
    int p = 0;

    if (window != NULL) {
        while (sfRenderWindow_isOpen(window)) {
            sfRenderWindow_display(window);
            y = event_basics(duck, swan, window, y);
            clock_sprite(time, clock, &select_duck);
            i = sprite_move_duck(duck, select_duck, x, i, y);
            if (i == 1) {
                x = 5;
                y = 0;
                i = 0;
                p++;
            } if (p >= 3) {
                sfRenderWindow_close(window);
                main_menu();
            }
            sfRenderWindow_clear(window, sfBlack);
            draw_sprite_Part_one(window, duck, dog, back_sprite);
            sfRenderWindow_setFramerateLimit(window, 60);
        }
        sfRenderWindow_destroy(window);
    }
}
