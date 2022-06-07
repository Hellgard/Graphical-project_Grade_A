/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void csfml_print_text(all_var *all, int size, sfVector2f pos,
char *text)
{
    sfText_setCharacterSize(all->texts->text, size);
    sfText_setColor(all->texts->text, sfWhite);
    sfText_setPosition(all->texts->text, pos);
    sfText_setString(all->texts->text, text);
    sfRenderWindow_drawText(all->windows->window,
    all->texts->text, NULL);
}

void csfml_print_num(all_var *all, int size, sfVector2f pos,
int num)
{
    sfText_setCharacterSize(all->texts->text, size);
    sfText_setColor(all->texts->text, sfWhite);
    sfText_setPosition(all->texts->text, pos);
    sfText_setString(all->texts->text, my_return_char(num));
    sfRenderWindow_drawText(all->windows->window,
    all->texts->text, NULL);
}

void csfml_print_sprites(all_var *all, sfSprite *sprite, sfVector2f pos)
{
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(all->windows->window, sprite, NULL);
}

void csfml_print_sprites_area(all_var *all, sfSprite *sprite, sfVector2f pos,
sfIntRect rectangle)
{
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTextureRect(sprite, rectangle);
    sfRenderWindow_drawSprite(all->windows->window, sprite, NULL);
}

sfSprite *csfml_create_sprite_from_file(char *filepath)
{
    sfTexture *texture_bend = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite_bend = sfSprite_create();
    sfSprite_setTexture(sprite_bend, texture_bend, 0);
    return (sprite_bend);
}
