/*
** EPITECH PROJECT, 2021
** create.c
** File description:
** create
*/

#include "rpg.h"

void create_txt (int x, int y, obj_t *obj)
{
    int i = 0;
    for (i = 0; obj->texts[i]; i++);
    obj->Text = malloc(sizeof(sfText *) * (i + 1));

    for (i = 0; obj->texts[i]; i++) {
        sfFont *font = sfFont_createFromFile("image/front1.otf");
        obj->Text[i] = sfText_create();
        sfText_setColor(obj->Text[i], sfBlack);
        sfText_setFont(obj->Text[i], font);
        sfText_setCharacterSize(obj->Text[i], 60);
        sfText_setString(obj->Text[i], obj->texts[i]);
        sfVector2f pos = {x, y};
        sfText_setPosition(obj->Text[i], pos);
    }
    obj->Text[i] = NULL;
}

void create_texte(scene_t *Scene)
{
    check_elem_text(Scene->elems->player, Scene);
    check_elem_text(Scene->elems->pet, Scene);
    check_elem_text(Scene->elems->event, Scene);
    check_elem_text(Scene->elems->collision, Scene);
    check_elem_text(Scene->elems->enemy, Scene);
    check_elem_text(Scene->elems->movable, Scene);
    check_elem_text(Scene->elems->portal, Scene);
    check_elem_text(Scene->elems->cutscene, Scene);
    check_elem_text(Scene->elems->boss, Scene);
    check_elem_text(Scene->elems->quest, Scene);
}

void create_sprite(all_var *all, scene_t *Scene)
{
    check_elem(Scene->elems->player, Scene);
    check_elem(Scene->elems->pet, Scene);
    check_elem(Scene->elems->event, Scene);
    check_elem(Scene->elems->collision, Scene);
    check_elem(Scene->elems->enemy, Scene);
    check_elem(Scene->elems->movable, Scene);
    check_elem(Scene->elems->portal, Scene);
    check_elem(Scene->elems->cutscene, Scene);
    check_elem(Scene->elems->boss, Scene);
    check_elem(Scene->elems->quest, Scene);
    all->var->player_prev = -1;
}
