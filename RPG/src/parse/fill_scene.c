/*
** EPITECH PROJECT, 2021
** fill_scene.c
** File description:
** fill
*/

#include "rpg.h"

obj_t *fill_elem_gen(char *Elements, char ind, obj_t *elem)
{
    char **player = my_str_to_array(Elements, ':');
    int pos_x;
    int pos_y;
    elem->id = ind;
    elem->is = my_getnbr(player[1]);
    elem->texture = my_strdup(player[2]);

    if (my_strcmp(player[4], "none") != 0) {
        elem->x = my_getnbr(player[4]);
        elem->y = my_getnbr(player[5]);
    }
    elem->linked_id = my_strdup(player[6]);
    elem->linked_id_2 = my_strdup(player[7]);
    elem->loot = my_strdup(player[8]);
    get_text(elem, player);
}

void check_elem_gen(obj_t **obj, char *Elements, char ind)
{
    if (Elements[0] == ind) {
        fill_elem_gen(Elements, ind, obj[obj[0]->i]);
        obj[0]->i += 1;
    }
}

void malloc_all_elem(scene_t *scene, char **how_many)
{
    scene->elems->player = malloc_elem("P", how_many);
    scene->elems->pet = malloc_elem("S", how_many);
    scene->elems->event = malloc_elem("2", how_many);
    scene->elems->collision = malloc_elem("1", how_many);
    scene->elems->movable = malloc_elem("4", how_many);
    scene->elems->portal = malloc_elem("#", how_many);
    scene->elems->cutscene = malloc_elem("C", how_many);
    scene->elems->enemy = malloc_elem("3", how_many);
    scene->elems->boss = malloc_elem("B", how_many);
    scene->elems->quest = malloc_elem("Q", how_many);
}

void fill_elem(scene_t *scene, char **Elements)
{
    sfSprite_setScale(scene->sprite,
    (sfVector2f){scene->scale_1, scene->scale_2});
    char **how_many = my_str_to_array(Elements[0], ':');
    malloc_all_elem(scene, how_many);
    for (int i = 1; Elements[i]; i++) {
        check_elem_gen(scene->elems->player, Elements[i], 'P');
        check_elem_gen(scene->elems->pet, Elements[i], 'S');
        check_elem_gen(scene->elems->event, Elements[i], '2');
        check_elem_gen(scene->elems->collision, Elements[i], '1');
        check_elem_gen(scene->elems->movable, Elements[i], '4');
        check_elem_gen(scene->elems->portal, Elements[i], '#');
        check_elem_gen(scene->elems->cutscene, Elements[i], 'C');
        check_elem_gen(scene->elems->enemy, Elements[i], '3');
        check_elem_gen(scene->elems->boss, Elements[i], 'B');
        check_elem_gen(scene->elems->quest, Elements[i], 'Q');
    }
}

void fill_scene(char *parse, scene_t *scene)
{
    scene->elems = malloc(sizeof(elem_t));
    char **info = my_str_to_array(parse, ':');
    char **config = my_str_to_array(open_read_file(info[2]), '\n');
    char **map_size = parse_info("map_size", '-', config);
    char **tile_size = parse_info("tile_size", '-', config);
    char **Elements = parse_info("Elements", '-', config);
    scene->texture = my_strdup(info[1]);
    scene->ambiance = sfMusic_createFromFile(info[3]);
    scene->Combat_ambiance = obj_create(0, 0, info[4]);
    scene->sprite = obj_create(0, 0, scene->texture);
    scene->id = my_strdup(info[0]);
    scene->map_size_x = my_getnbr(map_size[0]);
    scene->map_size_y = my_getnbr(map_size[1]);
    scene->tile_size_x = my_getnbr(tile_size[0]);
    scene->tile_size_y = my_getnbr(tile_size[1]);
    scene->Collision_M =  parse_info("Collision", '-', config);
    scene->Event_M =  parse_info("Event", '-', config);
    scene->scale_1 = ((float)1920 / scene->map_size_x);
    scene->scale_2 = ((float)1080 / scene->map_size_y);
    sfMusic_play(scene->ambiance);
    fill_elem(scene, Elements);
}
