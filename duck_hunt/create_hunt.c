#include "hunter.h"

int event_one(sfVector2i mouse_pos, sfVector2f pos_sprite, int j, sfSprite *duck)
{
    int y;

    if ((mouse_pos.x > (pos_sprite.x - 10) && mouse_pos.x < (pos_sprite.x + 110))
        && (mouse_pos.y > (pos_sprite.y - 10) && mouse_pos.y < (pos_sprite.y + 110))) {
        y = (rand() % 400 - 4) + 5;
        sfVector2f new_pos = {-110, y};
        j++;
        sfSprite_setPosition(duck, new_pos);
    }
    return j;
}

void change_dog (sfIntRect *select_dog)
{
    select_dog -> left += 60;
    if (select_dog -> left >= 300)
        select_dog -> left = 0;
}

void clock_sprite_main(sfTime time, sfClock *clock, sfIntRect *select_dog)
{
    time = sfClock_getElapsedTime(clock);

    if (sfTime_asSeconds(time) > 0.2) {
        change_dog(select_dog);
        sfClock_restart(clock);
    }
}

sfSprite *sprite_move_dog(sfSprite *dog, sfIntRect select_dog, sfRenderWindow* window, sfSprite *back_sprite)
{
    sfVector2f move = {5, 0};
    sfSprite_move(dog, move);

    if (sfSprite_getPosition(dog).x >= 500) {
        back_sprite = create_background("Images/mainpage.png");
        sfVector2f vector = {-1200, -1200};
        sfSprite_setPosition(dog, vector);
    } else {
        sfSprite_setTextureRect(dog, select_dog);
    }
    if (sfSprite_getPosition(dog).y >= -1200 && sfSprite_getPosition(dog).y <= -1200) {
        sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        main_event(window);
    }
    return back_sprite;
}
