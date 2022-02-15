#include "hunter.h"


void draw_sprite_main(sfRenderWindow* window, sfSprite *dog, sfSprite *back_sprite)
{
    sfRenderWindow_drawSprite(window, back_sprite, NULL);
    sfRenderWindow_drawSprite(window, dog, NULL);
}

void sprite_position_dog(sfSprite *dog)
{
    int x = -110;
    int y = 540;
    sfVector2f vector = {x, y};

    sfSprite_setPosition(dog, vector);
}

void main_event(sfRenderWindow *window)
{
    sfEvent event;
    sfVector2i mouse_pos;
    sfVector2f pos_sprite = {400, 600};

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed) {
            mouse_pos = sfMouse_getPositionRenderWindow(window);
            if ((mouse_pos.x > (pos_sprite.x) && (mouse_pos.x < (pos_sprite.x + 300))
            && (mouse_pos.y > (pos_sprite.y) && (mouse_pos.y < (pos_sprite.y + 200))))) {
                sfRenderWindow_close(window);
                Part_one();
            }
            if ((mouse_pos.x > (pos_sprite.x + 400) ) && (mouse_pos.y > (pos_sprite.y))) {
                sfRenderWindow_close(window);
                Part_two();
            }
        }
    }
}

void main_menu()
{
    sfRenderWindow* mainWindow;
    sfIntRect select_dog = {0,0,60,49};
    sfClock *clock = sfClock_create();
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    sfSprite *dog = create_dog("Images/dog_anim.png");
    sfSprite *back_sprite = create_background("Images/back.png");
    sprite_position_dog(dog);
    mainWindow = create_window(mainWindow);
    sfRenderWindow_setMouseCursorVisible(mainWindow, sfFalse);

    if (mainWindow != NULL) {
        while (sfRenderWindow_isOpen(mainWindow)) {
            sfRenderWindow_display(mainWindow);
            clock_sprite_main(time, clock, &select_dog);
            back_sprite = sprite_move_dog(dog, select_dog, mainWindow, back_sprite);
            mainwindow_view(mainWindow, back_sprite, dog);
        }
        sfRenderWindow_destroy(mainWindow);
    }
}

int main(int ac, char **av)
{
    if (ac < 1)
        return 84;
    else if (ac > 1){
      if (av[1][0] == '-' && av[1][1] == 'h') {
         my_putstr("Usage : ./my_hunter [no options needed]\0");
         return (0);
      }
    } else
        main_menu();
    return 0;
}
