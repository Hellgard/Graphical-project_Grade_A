/*
** EPITECH PROJECT, 2017
** tools.c
** File description:
** tools
*/

#include "rpg.h"

int my_getnbr(char *str)
{
    int nb = 0;
    int isneg = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            isneg = isneg * -1;
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i = i + 1;
        }
        else
            return (nb * isneg);
    }
    return (nb * isneg);
}

sfSprite *obj_create(int j, int k, char *path)
{
    sfTexture *obj_text;
    obj_text = sfTexture_createFromFile(path, NULL);
    sfSprite *obj_Sprite = sfSprite_create();
    sfSprite_setTexture(obj_Sprite, obj_text, sfFalse);
    sfVector2f obj_pos = {j, k};
    sfSprite_setPosition(obj_Sprite, obj_pos);
    return obj_Sprite;
}

int is_in_zone(obj_t *obj, scene_t *Scene)
{
    int p_x = Scene->elems->player[0]->x;
    int p_y = Scene->elems->player[0]->y;
    int x = obj->x;
    int y = obj->y;

    if (p_x >= (x - 2) && p_x <= (x + 2) &&
    p_y >= (y - 2) && p_y <= (y + 2))
        return 1;
    return 0;
}

int arr_lenght_sep(char **arr, char sep, int i)
{
    int count;
    for (count = 0; arr[i][0] != sep; i++)
        count++;
    return count;
}
