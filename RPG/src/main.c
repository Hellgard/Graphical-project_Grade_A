/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "rpg.h"

scene_t *create_scene(all_var *all, char *id, char **parse)
{
    scene_t *scene = malloc(sizeof(scene_t));
    int i = 0;
    char **info;

    for (int j = 0; my_strcmp(parse[j], "Perms") != 0; j++) {
        info = my_str_to_array(parse[j], ':');
        if (my_strcmp(info[0], id) == 0)
            i = j;
    }
    fill_scene(parse[i], scene);
    while (my_strcmp(parse[i], "Perms") != 0)
        i++;
    fill_perms(parse, ++i, scene);
    create_sprite(all, scene);
    create_texte(scene);
    scene->select_character = (sfIntRect) {0, 0, 300, 400};
    scene->movemnt_clock = sfClock_create();
    return scene;
}

void draw_attacks(all_var *all, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, comb_amb->fight_first, NULL);
    sfRenderWindow_drawSprite(window, comb_amb->fight_second, NULL);
    sfRenderWindow_drawSprite(window, comb_amb->fight_third, NULL);
    sfRenderWindow_drawSprite(window, comb_amb->fight_fourth, NULL);
    sfRenderWindow_drawSprite(window,
    first_comp->attack_sprite[first_comp->actual_attack], NULL);
    sfRenderWindow_drawSprite(window,
    second_comp->attack_sprite[second_comp->actual_attack], NULL);
    sfRenderWindow_drawSprite(window,
    third_comp->attack_sprite[third_comp->actual_attack], NULL);
    sfRenderWindow_drawSprite(window,
    fourth_comp->attack_sprite[fourth_comp->actual_attack], NULL);
}

void draw_prev_battle(all_var *all)
{
    sfRenderWindow_drawSprite(all->windows->window, comb_amb->fight, NULL);
    sfRenderWindow_drawSprite(all->windows->window, comb_amb->inventory, NULL);
    sfRenderWindow_drawSprite(all->windows->window, comb_amb->escape, NULL);
}

void fill_Game(all_var *all)
{
    all->game->Combat_ambiance = parse_ambiance();
    all->game->enemy = parse_enemy();
    all->game->player = parse_player();
    all->game->trans_scene = sfMusic_createFromFile("music/zone_switch.ogg");
    all->game->collision = sfMusic_createFromFile("music/collision.ogg");
    all->game->battle = sfMusic_createFromFile("music/battle_starter.ogg");
    sfMusic_setVolume(all->game->collision, 60);
    sfMusic_setVolume(all->game->battle, 60);
    all->game->text = obj_create(0, 840, "image/text_zone.png");
    all->game->bul_text = obj_create(0, 0, "image/bulle_text.png");
    all->game->on_attack = 0;
    all->game->attack_id = 2;
    all->game->last_x = 0;
    all->game->last_y = 0;
}

int main(int ac, char **av)
{
    srand(0);
    all_var *all = init_struct_all();
    all->windows->video_mode = (sfVideoMode){1920, 1080, 64};
    all->windows->window = sfRenderWindow_create(all->windows->video_mode,
    "MY_RPG_GAME", sfDefaultStyle, NULL);
    ini_struc_var(all);
    sfImage *image = sfImage_createFromFile("image/Icono.png");
    all->sprites->charge =
    csfml_create_sprite_from_file("./image/menu/loading.png");
    sfRenderWindow_setIcon(all->windows->window, sfImage_getSize(image).x
    , sfImage_getSize(image).y, sfImage_getPixelsPtr(image));
    all->clocks->clock_loading = sfClock_create();
    my_window(all);
    save_general(all);
    destroy_all(all);
    //free_all(all);
    sfRenderWindow_destroy(all->windows->window);
    return 0;
}
