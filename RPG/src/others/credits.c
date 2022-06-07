/*
** EPITECH PROJECT, 2021
** credits.c
** File description:
** credits
*/

#include "rpg.h"
#include "structs.h"

char **set_up_values(char **arr, credit_t *ending)
{
    arr[0] = "image/Map001.png";
    arr[1] = "image/Map002.png";
    arr[2] = "image/Map003.png";
    arr[3] = "image/Map004.png";
    arr[4] = "image/Map005.png";
    arr[5] = "image/Map006.png";
    arr[6] = "image/Map007.png";
    arr[7] = "image/Map008.png";
    arr[8] = "image/Map009.png";
    arr[9] = "image/Map011.png";
    arr[10] = "image/Map010.png";
    arr[11] = NULL;
    ending->i = 0;
    ending->j = 1;
    ending->y = 0;
    return (arr);
}

void set_up_credit_scales(credit_t *ending)
{
    ending->scale_down.x = 0.9993;
    ending->scale_down.y = 0.9993;
    ending->scale_up.x = 1.0007;
    ending->scale_up.y = 1.0007;
    ending->zoom.x = -1.00002;
    ending->zoom.y = -1.00007;
    ending->scale_resize.x = 3.07;
    ending->scale_resize.y = 2.25;
    ending->offset.x = 0;
    ending->offset.y = 20;
}

void scale_credit_back(credit_t *ending, char **arr)
{
    float x_pos[11] = {3.07, 1.77, 2.28, 4, 2.16, 4, 2, 4, 2.42, 4, 3.2};
    float y_pos[11] = {2.25, 1, 1.5, 2.81, 1.28, 2.81, 1.21, 2.81, 1.61};

    if (ending->i > 600) {
        ending->back = obj_create(0, 0, arr[ending->j]);
        ending->scale_resize.x = x_pos[ending->j];
        ending->scale_resize.y = y_pos[ending->j];
        sfSprite_scale(ending->back, ending->scale_resize);
        ending->i = 0;
        ending->j += 1;
        if (ending->j == 9)
            ending->j = 0;
    }
    if (ending->i < 300)
        move_credit_sprite(ending);
    if (ending->i > 300)
        move_credit_sprite(ending);
}

void display_credit(sfRenderWindow *window, credit_t *ending)
{
    if (ending->y > 100) {
        sfSprite_move(ending->text, ending->offset);
        ending->y = 0;
    }
    sfRenderWindow_drawSprite(window, ending->back, NULL);
    sfRenderWindow_drawSprite(window, ending->filter, NULL);
    sfRenderWindow_drawSprite(window, ending->text, NULL);
    sfRenderWindow_display(window);
}

void credit(sfRenderWindow *window)
{
    char **arr = malloc(sizeof(char *) * 12);
    credit_t *ending = malloc(sizeof(credit_t));
    arr = set_up_values(arr, ending);
    set_up_credit_scales(ending);
    ending->back = obj_create(0, 0, arr[0]);
    ending->filter = obj_create(0, 0, "image/opac_back.png");
    sfSprite_scale(ending->back, ending->scale_resize);
    ending->text = obj_create(700, -350, "image/credit_end.png");

    while (1) {
        ending->info_pos = sfSprite_getPosition(ending->text);
        if (ending->info_pos.y > 1000)
            break;
        scale_credit_back(ending, arr);
        display_credit(window, ending);
        ending->i += 1;
        ending->y += 1;
    }
    free(ending);
    free(arr);
}
