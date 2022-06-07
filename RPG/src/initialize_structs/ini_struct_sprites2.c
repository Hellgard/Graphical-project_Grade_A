/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "rpg.h"

void ini_struct_sprites7(all_var  *all)
{
    all->sprites->reaction_game_selected = csfml_create_sprite_from_file
    ("./image/menu/game_selected.png");
    all->sprites->mouse = csfml_create_sprite_from_file
    ("./image/menu/mouse.png");
    all->sprites->settings_check = csfml_create_sprite_from_file
    ("./image/menu/settings_check.png");
    all->sprites->slots = csfml_create_sprite_from_file
    ("./image/menu/slots.png");
    all->sprites->trash = csfml_create_sprite_from_file
    ("./image/menu/trash.png");
    all->sprites->slots_skills = csfml_create_sprite_from_file
    ("./image/menu/skills.png");
    all->sprites->reaction_skills = csfml_create_sprite_from_file
    ("./image/menu/reaction_skills.png");
    all->sprites->pause_button = csfml_create_sprite_from_file
    ("./image/menu/pause_button.png");
    all->sprites->inventory_items[1][2] = csfml_create_sprite_from_file
    ("./image/menu/items/shield_2.png");
    all->sprites->inventory_items[1][3] = csfml_create_sprite_from_file
    ("./image/menu/items/shield_3.png");
    all->sprites->inventory_items[1][4] = NULL;
}

void ini_struct_sprites6(all_var  *all)
{
    all->sprites->inventory_items[2][0] = csfml_create_sprite_from_file
    ("./image/menu/apple.png");
    all->sprites->inventory_items[2][1] = csfml_create_sprite_from_file
    ("./image/menu/items/potion_0.png");
    all->sprites->inventory_items[2][2] = csfml_create_sprite_from_file
    ("./image/menu/items/potion_1.png");
    all->sprites->inventory_items[2][3] = csfml_create_sprite_from_file
    ("./image/menu/items/meat.png");
    all->sprites->inventory_items[2][4] = csfml_create_sprite_from_file
    ("./image/menu/items/tabaco.png");
    all->sprites->inventory_items[2][5] = NULL;
    all->sprites->inventory_items[3][0] = NULL;
    all->sprites->msg_save_game = csfml_create_sprite_from_file
    ("./image/menu/msg_save_game.png");
    all->sprites->page_save = csfml_create_sprite_from_file
    ("./image/menu/page_save.png");
    all->sprites->background_menu = csfml_create_sprite_from_file
    ("./image/menu/background_menu.png");
    ini_struct_sprites7(all);
}

void ini_struct_sprites5(all_var  *all)
{
    all->sprites->inventory_page_selected = malloc(sizeof(sfSprite *) * 5);
    all->sprites->inventory_page_selected[0] = csfml_create_sprite_from_file
    ("./image/menu/weapons_inventory.png");
    all->sprites->inventory_page_selected[1] = csfml_create_sprite_from_file
    ("./image/menu/shield_inventory.png");
    all->sprites->inventory_page_selected[2] = csfml_create_sprite_from_file
    ("./image/menu/health_inventory.png");
    all->sprites->inventory_page_selected[3] = csfml_create_sprite_from_file
    ("./image/menu/skills_inventory.png");
    all->sprites->inventory_page_selected[4] = NULL;
    all->sprites->book = csfml_create_sprite_from_file("./image/menu/book.png");
    all->sprites->page_selection_player = csfml_create_sprite_from_file
    ("./image/menu/selection_player.png");
    ini_struct_sprites6(all);
}
