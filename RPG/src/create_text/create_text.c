/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "rpg.h"

void create_msg(all_var *all)
{
    all->texts->font = sfFont_createFromFile("./fonts/Ground_Castle.otf");
    all->texts->font2 = sfFont_createFromFile("./fonts/arial.ttf");
    all->texts->text = sfText_create();
    sfText_setFont(all->texts->text, all->texts->font);
    sfText_setCharacterSize(all->texts->text, 30);
}
