#include "hunter.h"

sfRenderWindow *create_window(sfRenderWindow* window)
{
    sfVideoMode mode = { WIDTH, HEIGHT, 32};
    window = sfRenderWindow_create(mode, "Duck Hunt", sfDefaultStyle, NULL);
    return window;
}

sfSprite *create_background(char *Path_name)
{
    sfTexture *Back_texture = sfTexture_createFromFile(Path_name,NULL);
    sfSprite *Back_Sprite = sfSprite_create();
    sfSprite_setTexture(Back_Sprite, Back_texture, sfFalse);
    return (Back_Sprite);
}

void change_duck(sfIntRect *select_duck)
{
    select_duck -> left += 110;
    if (select_duck -> left >= 330)
        select_duck -> left = 0;
}
sfSprite *create_duck()
{
    sfTexture *duck_texture = sfTexture_createFromFile("Images/duck_anim.png",NULL);
    sfSprite *duck_Sprite = sfSprite_create();
    sfSprite_setTexture(duck_Sprite, duck_texture, sfFalse);
    return (duck_Sprite);
}

sfSprite *create_swan()
{
    sfTexture *swan_texture = sfTexture_createFromFile("Images/gooseking.png",NULL);
    sfSprite *swan_Sprite = sfSprite_create();
    sfSprite_setTexture(swan_Sprite, swan_texture, sfFalse);
    return (swan_Sprite);
}
