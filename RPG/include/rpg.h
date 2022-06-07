/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** header
*/

#ifndef MY_H_
    #define MY_H_
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <ctype.h>
    #include "structs.h"
    #include "my_library.h"
    #include <math.h>
    #include <limits.h>
    #include <stdbool.h>

    void print_book(all_var *all);
    void analyse_events(all_var *all, int page);
    void get_key(all_var *all);
    void ini_struct_sprites5(all_var  *all);
    void print_element_inventory_inuse(all_var *all, t_info_inventory *tmp);
    void print_inventory_bars(all_var *all);
    void move_credit_sprite(credit_t *ending);
    void valid_boss(all_var *all, obj_t *boss);
    void display_game_information(all_var *all);
    void display_game_quest(all_var *all);
    int check_main_quest(all_var *all);
    void enemy_attack_text(all_var *all, int i, int life_taken);
    void print_info_combat(all_var *all);
    int check_collision(char ind, obj_t *obj);
    void set_item(all_var *all, sfVector2f pos2, t_info_inventory *tmp);
    void check_quest_valid(quest_t *quest_list, obj_t **event, obj_t **quest
    , obj_t **boss);
    void check_boss(all_var *all, obj_t *obj);
    void add_to_list(quest_t *quest_list, obj_t *obj);
    void add_to_quest(quest_t *quest_list, obj_t *obj);
    void check_quest_loot(all_var *all, obj_t *obj);
    void check_quest(all_var *all, obj_t *obj);
    void equip_delete_selected(all_var *all);
    void print_page_portada(all_var *all);
    void create_linked_inventory(all_var *all);
    void print_soldier(all_var *all, obj_t *obj, int x, int y);
    char *save_text(int fd, char *filepath);
    int compare_char(char c, char d);
    char *my_strcat(char *dest, char *src);
    char *my_return_char(int nb);
    void free_str_arr(char **arr);
    void easteregg_inventory_page(all_var *all);
    void buttons_save(all_var *all);
    void buttons_confirmation(all_var *all);
    void buttons_mainmenu(all_var *all);
    void buttons_levels(all_var *all);
    void buttons_selection_player(all_var *all);
    void buttons_settings(all_var *all);
    void buttons_inventory(all_var *all);
    void buttons_game(all_var *all);
    void buttons_pause(all_var *all);
    void buttons_prev_battle(all_var *all);
    void buttons_battle(all_var *all);
    void free_arr_sprites(sfSprite **arr_sprite);
    void print_inventory_buttons(all_var *all, t_info_inventory *tmp);
    void modify_competences_2(all_var *all, int competence, int increment);

    void change_sound(all_var *all);
//ACTIONS BUTTONS
    void buttons_book(all_var *all);
    void buttons_mainmenu_actions(all_var *all,  int *next_page, int i);
    void buttons_battle_actions(all_var *all, int i);
    void buttons_confirmation_actions(all_var *all, int i);
    void buttons_inventory_actions(all_var *all, int inv_page, int i);
    void buttons_pause_actions(all_var *all, int *next_page, int i);
    void buttons_prevbattle_actions(all_var *all, int *next_page, int i);
    void buttons_save_actions(all_var *all, int *next_page, int i);
    void buttons_settings_actions(all_var *all, int *action, int i);
// SAVE FUNC
    void save_inventory(all_var *all, char *file_game);
    void save_var(all_var *all, char *file_game);
    void save_quests(all_var *all, char *file_game);
    void save_all(all_var *all);
    void save_general(all_var *all);

// LOAD FUNC
    void load_all(all_var *all);
    void load_general(all_var *all);
    char ***get_info(char *filepath, char sep_1, char sep_2);
    void load_inventory(all_var *all, char *file_game);
    void load_var(all_var *all, char *file_game);
    void load_quest(all_var *all, char *file_game);
    void check_boss_load(all_var *all, combat_t **enemy);

//DELETE FUNC
    void delete_all(all_var *all);

//CSFML_FUNCTION
    void csfml_print_text(all_var *all, int size, sfVector2f pos, char *text);
    void csfml_print_num(all_var *all, int size, sfVector2f pos, int num);
    void csfml_print_sprites(all_var *all, sfSprite *sprite, sfVector2f pos);
    void csfml_print_sprites_area(all_var *all, sfSprite *sprite
    , sfVector2f pos, sfIntRect rectangle);
    sfSprite *csfml_create_sprite_from_file(char *filepath);

//BUTTONS
    int is_button_pressed3(new_button *button, all_var *all, sfSprite *sprite,
    sfVector2f vector);
    void buttons_inventory2(all_var *all);
    void get_skill_selected(all_var *all);
    void get_item_selected(all_var *all);
    void equip_delete_selected(all_var *all);
    new_button *create_button(int x, int y, int size_x, int size_y);

//FREE FUNCTIONS
    void free_inventory(all_var *all);
    void free_arr_arr_sprites(sfSprite ***arr_sprite);
    void free_arr_sprites(sfSprite **arr_sprite);
    void destroy_all(all_var *all);
    void free_all(all_var *all);
    void free_str_arr(char **arr);

//CREATE FUNC
    void create_msg(all_var *all);
    void create_clocks(all_var *all);
    void create_sounds(all_var *all);
    void create_positions(all_var *all);

//CHANGE SPRITE SELECTION
    void change_health(all_var *all);
    void change_strength(all_var *all);
    void change_armour(all_var *all);
    void change_rotation_character(sfIntRect *rect, int direction);
    void change_rect_bar(all_var *all, int value);

//PRINT PAGES
    void print_bars_battle(all_var *all);
    void print_confirmation(all_var *all);
    void manage_pages(all_var *all);
    void print_page_charge(all_var *all);
    void print_page_mainmenu(all_var *all);
    void print_page_settings(all_var *all);
    void print_page_levels(all_var *all);
    void print_page_selection_player(all_var *all);
    void print_inventory(all_var *all);
    void print_page_save(all_var *all);
    int start(all_var *all);
    void print_game(all_var *all);
    void print_pause(all_var *all);
    void print_prev_battle(all_var *all);
    void print_battle(all_var *all);
    void draw_prev_battle(all_var *all);
//ATTACK
    void attack(comp_t *competencies, combat_t *enemy, all_var *all);

//INVENTORY
    void create_list_inventory(t_info_inventory *file);
    sfVector2f get_inventory_pos(int num);
    t_info_inventory *get_slot_inventory(all_var *all);
    void add_element_inventory(all_var *all, char *filepath, int quantity);
    void show_item_properties(all_var *all);
    void unequip_element_inventory(all_var *all);
    void equip_element_inventory(all_var *all);
    void delete_element_inventory(all_var *all);
    int *get_element_file(char *filepath);
    t_info_inventory *get_pointer_inventory(all_var *all, char *filename
    , int quantity);

//STR WORD ARRAY
    char **save_word(char *arraytext, char separator, char *filepath);


// WINDOW FUNCTIONS
    sfRenderWindow *my_window(all_var *all);
    void close_game(all_var *all);

// INI STRUCT
    void reset_game(all_var  *all);
    void scale_images(all_var *all);
    void scale_enemies_book(all_var *all);
    void scale_reset_enemies_book(all_var *all);
    all_var *init_struct_all(void);
    void ini_struc_var(all_var *all);
    void ini_all_start(all_var *all, int ini);
    void ini_struct_sprites(all_var  *all);
    t_info_inventory *init_linked_inventory(int i);
    t_info_inventory **init_struct_inventory(void);

//FILL SCENE
    void fill_Game(all_var *all);
    void fill_scene(char *parse, scene_t *scene);
    void fill_perms(char **parse, int i, scene_t *scene);
    char *open_read_file(char *path);
    char **my_str_to_array(char *str, char sep);
    char **parse_elem(char **Elements, char ind, int i);
    char **parse_info(char *to_get, char sep, char **config);
    Combat_ambiance_t *parse_ambiance();
    void fill_perms(char **parse, int i, scene_t *scene);
    obj_t *fill_elem_gen(char *Elements, char ind, obj_t *elem);
    obj_t **malloc_elem(char *ind, char **how_many);
    combat_t **parse_enemy();
    player_t *parse_player();

//Check LOGIC GAME
    void key_check(all_var *all);
    void check_elem(obj_t **obj, scene_t *scene);
    void check_elem_text(obj_t **obj, scene_t *scene);
    void check_draw(all_var *all, obj_t **obj);
    void check_teleport(all_var *all, obj_t **obj, int x, int y);
    void check_draw_text(all_var *all, obj_t **obj);
    void teleport_check(all_var *all);
    void attack_check(all_var *all);
    int check_id(quest_t *quest_list, char *id);
    void check_idel(scene_t *scene, obj_t **obj);
    void check_elem_gen(obj_t **obj, char *Elements, char ind);
    int is_in_zone(obj_t *obj, scene_t *Scene);

//DRAW CREATE
    int arr_lenght_sep(char **arr, char sep, int i);
    sfSprite *obj_create(int j, int k, char *path);
    void create_txt (int x, int y, obj_t *obj);
    void create_texte(scene_t *Scene);
    void create_sprite(all_var *all, scene_t *Scene);
    void draw_text(all_var *all);
    void draw_elem(all_var *all);
    void print_entire_scene(scene_t *scene);
    void free_scene(scene_t *scene);
    scene_t *create_scene(all_var *all, char *id, char **parse);
    void draw_attacks(all_var *all, sfRenderWindow *window);
    void fade_in(all_var *all);
    void credit(sfRenderWindow *window);
    char *my_strdup(char *str);
    int my_getnbr(char *str);
    void get_text(obj_t *elem, char **player);
    particle_t **init_particles(all_var *all, int nb_particles);
    void autosave(all_var *all);
    void particle_system(all_var *all, particle_t **particle);
    void chose_char_color(all_var *all);
    void close_game(all_var *all);

//EVENT
    void move_this_elem(int y, int x, scene_t *scene, char *str);
    void movable_check(all_var *all);
    void event_combat(all_var *all);
    void event_text(scene_t *scene, char event);
    void print_quest(quest_t *quest_list);
    void secret_event(all_var *all, obj_t *obj, char event);
    int compare_ind(char ind, elem_t *elems, scene_t *Scene);
    void change_perm(Game_t *Game, obj_t *obj);

#endif
