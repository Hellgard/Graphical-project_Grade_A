/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "rpg.h"

sfSprite *create_spr(char *path)
{
    sfTexture *texture = sfTexture_createFromFile
    (path, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    return (sprite);
}

void ini_struct_sprites4(all_var  *all)
{
    all->sprites->pause_page = csfml_create_sprite_from_file
    ("./image/menu/pause_page.png");
    all->sprites->msg_choose_player = csfml_create_sprite_from_file
    ("./image/menu/msg_choose_player.png");
    all->sprites->delete_confirmation = csfml_create_sprite_from_file
    ("./image/menu/delete_confirmation.png");
    all->sprites->reaction_battle = csfml_create_sprite_from_file
    ("./image/Selected_Overlay.png");
    all->sprites->character_rotation = malloc(sizeof(sfSprite *) * 3);
    all->sprites->character_rotation[0] = csfml_create_sprite_from_file
    ("./image/menu/character_rotation1.png");
    all->sprites->character_rotation[1] = csfml_create_sprite_from_file
    ("./image/menu/character_rotation2.png");
    all->sprites->character_rotation[2] = csfml_create_sprite_from_file
    ("./image/menu/character_rotation3.png");
    all->sprites->page_mainmenu = csfml_create_sprite_from_file(
    "./image/menu/mainmenu.png");
    all->sprites->page_settings = csfml_create_sprite_from_file(
    "./image/menu/settings.png");
    ini_struct_sprites5(all);

}

void ini_struct_sprites3(all_var  *all)
{
    all->sprites->page_levels = csfml_create_sprite_from_file
    ("./image/menu/levels.png");
    all->sprites->page_portada = csfml_create_sprite_from_file
    ("./image/menu/portada.png");
    all->sprites->button_delete_equip = csfml_create_sprite_from_file
    ("./image/menu/delete_equip.png");
    all->sprites->button_unequip = csfml_create_sprite_from_file
    ("./image/menu/unequip.png");
    all->sprites->reaction_inventory = csfml_create_sprite_from_file
    ("./image/menu/reaction_inventory.png");
    all->sprites->reaction_big_button = csfml_create_sprite_from_file
    ("./image/menu/reaction_big_button.png");
    all->sprites->reaction_giant_button = csfml_create_sprite_from_file
    ("./image/menu/reaction_giant_button.png");
    all->sprites->reaction_small_button = csfml_create_sprite_from_file
    ("./image/menu/reaction_small_button_2.png");
    all->sprites->reaction_small_button_2 = csfml_create_sprite_from_file
    ("./image/menu/reaction_small_button_2.png");
    ini_struct_sprites4(all);
}

void ini_struct_sprites2(all_var  *all)
{
    all->sprites->inventory_items = malloc(sizeof(sfSprite **) * 9);
    all->sprites->inventory_items[4] = NULL;
    for (int i = 0; i < 4; i++)
        all->sprites->inventory_items[i] = malloc(sizeof(sfSprite *) * 10);
     all->sprites->inventory_items[0][0] = csfml_create_sprite_from_file
    ("./image/menu/items/sword_0.png");
    all->sprites->inventory_items[0][1] = csfml_create_sprite_from_file
    ("./image/menu/items/sword_1.png");
    all->sprites->inventory_items[0][2] = csfml_create_sprite_from_file
    ("./image/menu/items/sword_2.png");
    all->sprites->inventory_items[0][3] = csfml_create_sprite_from_file
    ("./image/menu/items/axe_0.png");
    all->sprites->inventory_items[0][4] = csfml_create_sprite_from_file
    ("./image/menu/items/axe_1.png");
    all->sprites->inventory_items[0][5] = csfml_create_sprite_from_file
    ("./image/menu/items/axe_0.png");
    all->sprites->inventory_items[0][6] = NULL;
    all->sprites->inventory_items[1][0] = csfml_create_sprite_from_file
    ("./image/menu/items/shield_0.png");
    all->sprites->inventory_items[1][1] = csfml_create_sprite_from_file
    ("./image/menu/items/shield_1.png");
    ini_struct_sprites3(all);
}

void ini_struct_sprites(all_var  *all)
{
    all->sprites->inventory = csfml_create_sprite_from_file
    ("./image/menu/inventory.png");
    all->sprites->health_bar = csfml_create_sprite_from_file
    ("./image/menu/health_bar.png");
    all->sprites->shield_bar = csfml_create_sprite_from_file
    ("./image/menu/shield_bar.png");
    all->sprites->armour_bar = csfml_create_sprite_from_file
    ("./image/menu/armour_bar.png");
    all->sprites->game_health_bar = csfml_create_sprite_from_file
    ("./image/menu/game_health_bar.png");
    all->sprites->game_shield_bar = csfml_create_sprite_from_file
    ("./image/menu/game_shield_bar.png");
    all->sprites->game_armour_bar = csfml_create_sprite_from_file
    ("./image/menu/game_armour_bar.png");
    all->sprites->improve_bar = csfml_create_sprite_from_file
    ("./image/menu/improve_bar.png");
    all->sprites->book_killed = csfml_create_sprite_from_file("./image/menu/book_killed.png");
    ini_struct_sprites2(all);
}
