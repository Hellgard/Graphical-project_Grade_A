/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "rpg.h"

void reset_game(all_var  *all)
{
    all->game->scene = create_scene(all, "1", all->game->parse);
    all->game->player->level = 1;
    all->game->player->life = 15;
    all->game->player->defense = 15;
    all->game->player->attack = 15;
    all->game->scene->elems->player[0]->x = 21;
    all->game->scene->elems->player[0]->y = 9;
    all->game->scene->elems->player[0]->pos.x =
    ((all->game->scene->elems->player[0]->x) * (all->game->scene->map_size_x /
    all->game->scene->tile_size_x) * all->game->scene->scale_1);
    all->game->scene->elems->player[0]->pos.y =
    ((all->game->scene->elems->player[0]->y) * (all->game->scene->map_size_y /
    all->game->scene->tile_size_y) * all->game->scene->scale_2);
    all->game->scene->elems->player[0]->pos_target =
    all->game->scene->elems->player[0]->pos;
    sfSprite_setPosition(all->game->scene->elems->player[0]->sprite,
    all->game->scene->elems->player[0]->pos);
    all->var->player = -1;
    all->var->item_selected = -1;
    all->var->improve = 0;
    all->var->prev_improve = 0;
    all->var->prev_armour = 0;
    all->var->prev_health = 0;
    all->var->prev_strength = 0;
    all->var->animation_equiped = 8;
    all->var->weapon = 0;
    all->var->shield = 0;
    all->var->animation_equiped = 8;
}

void ini_struc_var2(all_var *all)
{
    all->var->book_page = 0;
    all->var->prev_strength = 0;
    all->var->actual_id = "1";
    all->var->weapon = 0;
    all->var->shield = 0;
    all->var->prev_id_map = NULL;
    all->var->animation_equiped = 8;
    all->var->autosave = true;
    load_general(all);
    fill_Game(all);
    all->game->parse = my_str_to_array(open_read_file("config.txt"), '\n');
    all->game->scene = create_scene(all, "1", all->game->parse);
    all->game->quest_list = malloc(sizeof(quest_t));
    all->game->quest_list->str = NULL;
    all->game->quest_list->prev = NULL;
    all->game->clock = sfClock_create();
    all->var->inventory_page = 0;
}

void ini_struc_var(all_var *all)
{
    all->var->list_saved = malloc(sizeof(int) * 3);
    all->var->list_name_saved = malloc(sizeof(char *) * 4);
    all->var->list_name_saved[0] = malloc(sizeof(char) * 15);
    all->var->list_name_saved[1] = malloc(sizeof(char) * 15);
    all->var->list_name_saved[2] = malloc(sizeof(char) * 15);
    all->var->list_name_saved[3] = NULL;
    all->var->current_game = -1;
    all->var->page = PAGE_PORTADA;
    all->var->level = -1;
    all->var->player = -1;
    all->var->player_prev = -1;
    all->var->item_selected = -1;
    all->var->prev_fps = 30;
    all->var->improve = 0;
    all->var->prev_improve = 0;
    all->var->armour = 10;
    all->var->prev_armour = 0;
    all->var->health = 10;
    all->var->prev_health = 0;
    all->var->strength = 10;
    ini_struc_var2(all);
}

void ini_all_start(all_var *all, int ini)
{
    if (ini == 0) {
        create_linked_inventory(all);
        create_clocks(all);
        create_positions(all);
        ini_struct_sprites(all);
        scale_images(all);
        create_msg(all);
    }
}
