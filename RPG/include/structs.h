/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** fgfghgf
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

//MACROS
    //KEYS
    #define KEY_INVENTORY 'i'
    #define KEY_PAUSE 'p'
    #define KEY_ADD_INVENTORY 'a'
    #define KEY_MSG 'f'
     #define KEY_BOOK 'b'
    //PAGES
    #define PAGE_PORTADA 1
    #define PAGE_MAINMENU 2
    #define PAGE_SETTINGS 3
    #define PAGE_LEVELS 4
    #define PAGE_SELECTION_PLAYER 5
    #define PAGE_GAME 6
    #define PAGE_SAVE 7
    #define PAGE_INVENTORY 8
    #define PAGE_PAUSE 9
    #define PAGE_CONFIRMATION 10
    #define PAGE_PREV_BATTLE 11
    #define PAGE_BATTLE 12
    #define PAGE_BOOK 13
    //others
    #define first_comp all->game->player->competencies->first
    #define second_comp all->game->player->competencies->second
    #define third_comp all->game->player->competencies->third
    #define fourth_comp all->game->player->competencies->fourth
    #define map_x all->game->scene->map_size_x
    #define map_y all->game->scene->map_size_y
    #define tile_x all->game->scene->tile_size_x
    #define tile_y all->game->scene->tile_size_y
    #define scl_1 all->game->scene->scale_1
    #define scl_2 all->game->scene->scale_2
    #define player_struct all->game->scene->elems->player[0]
    #define comb_amb all->game->Combat_ambiance

    typedef struct particle_s {
        sfVector2f size;
        sfVector2f pos;
        sfVector2f speed;
        sfColor color;
        sfSprite *sprite;
    } particle_t;

    typedef struct credit_s {
        int i;
        int j;
        int y;
        sfSprite *back;
        sfSprite *text;
        sfSprite *filter;
        sfVector2f scale_up;
        sfVector2f scale_down;
        sfVector2f scale_resize;
        sfVector2f zoom;
        sfVector2f offset;
        sfVector2f info_pos;
        float *x_pos;
        float *y_pos;
    }credit_t;

    typedef struct permissions_s {
        int Text;
        int Texture;
        int Animation;
        int CanMove;
        int CanGoOver;
        int CanInteractWith;
        int linked_id;
        int CanAttack;
        int Teleport;
        int isBoss;
        int isQuest;
        int linked_id_2;
    }perm_t;

    typedef struct object_s {
        perm_t *perm;
        char id;
        char *name;
        int is;
        int x;
        int y;
        char *texture;
        sfSprite *sprite;
        sfText **Text;
        int level;
        char **texts;
        char *linked_id;
        char *linked_id_2;
        char *loot;
        int i;
        sfVector2f pos;
        sfVector2f pos_target;
    }obj_t;

    typedef struct elements_s {
        obj_t **player;
        obj_t **pet;
        obj_t **event;
        obj_t **collision;
        obj_t **enemy;
        obj_t **movable;
        obj_t **portal;
        obj_t **cutscene;
        obj_t **boss;
        obj_t **quest;
    }elem_t;

    typedef struct scene_s {
        char *id;
        char *texture;
        sfMusic *ambiance;
        sfSprite *sprite;
        int map_size_x;
        int map_size_y;
        int tile_size_x;
        int tile_size_y;
        float scale_1;
        float scale_2;
        char **Collision_M;
        char **Event_M;
        sfSprite *Combat_ambiance;
        elem_t *elems;
        sfIntRect select_character;
        sfClock *movemnt_clock;
        sfTime movemnt_time;
    }scene_t;

    typedef struct Combat_s {
        char *id;
        sfSprite *sprite;
        int level;
        int li;
        int life;
        int speed;
        int how_many_comp;
        char **competencies;
        char **loots;
        int gaved_xp;
        int isBoss;
        char **attacks_damages;
        char **attacks;
    }combat_t;

    typedef struct comp_s {
        char **attacks;
        sfSprite **attack_sprite;
        int how_many;
        int actual_attack;
        int *attacks_damages;
        char **attacks_name;
    }comp_t;

    typedef struct competencies_s {
        comp_t *first;
        comp_t *second;
        comp_t *third;
        comp_t *fourth;
    }competencies_t;

    typedef struct player_s {
        int level;
        int max_life;
        int xp;
        int palier;
        int point;
        int life;
        int attack;
        int defense;
        int speed;
        competencies_t *competencies;
    }player_t;

    typedef struct elem_quest_s {
        char *id;
        char *quest_id;
        int is_actual;
    }elem_quest_t;

    typedef struct quest_s {
        char *id;
        char *str;
        int how_many;
        int is_actual;
        int state;
        int i;
        elem_quest_t **elem_quest;
        struct quest_s *prev;
        struct quest_s *next;
    }quest_t;

    typedef struct rectangle_s {
        int *x_pos;
        int *y_pos;
        sfRectangleShape *rects;
        sfVector2f offset;
    }rectangle_t;

    typedef struct Combat_ambiance_s {
        sfSprite *fight;
        sfSprite *inventory;
        sfSprite *escape;
        char *combat_infos;
        sfSprite *fight_first;
        sfSprite *fight_second;
        sfSprite *fight_third;
        sfSprite *fight_fourth;
    }Combat_ambiance_t;

    typedef struct Game_s {
        scene_t *scene;
        player_t *player;
        quest_t *quest_list;
        sfSprite *text;
        sfSprite *bul_text;
        Combat_ambiance_t *Combat_ambiance;
        rectangle_t **fade_in;
        int turn_combat;
        sfClock *clock_combat;
        int pos_x;
        int pos_y;
        char **parse;
        int last_x;
        int last_y;
        combat_t **enemy;
        sfMusic *trans_scene;
        sfMusic *collision;
        sfMusic *battle;
        int on_attack;
        int attack_id;
        sfClock *clock;
        sfTime Time;
    }Game_t;

    //STRUCT SPRITES
    typedef struct s_sprites_var {
        sfSprite *inventory;
        sfSprite *health_bar;
        sfSprite *shield_bar;
        sfSprite *armour_bar;
        sfSprite *game_health_bar;
        sfSprite *game_shield_bar;
        sfSprite *game_armour_bar;
        sfSprite *improve_bar;
        sfSprite ***inventory_items;
        sfSprite *page_portada;
        sfSprite *background_menu;
        sfSprite *page_mainmenu;
        sfSprite *page_settings;
        sfSprite *page_levels;
        sfSprite *page_selection_player;
        sfSprite *page_save;
        sfSprite *button_delete_equip;
        sfSprite *button_unequip;
        sfSprite *reaction_inventory;
        sfSprite *reaction_big_button;
        sfSprite *reaction_small_button;
        sfSprite *reaction_small_button_2;
        sfSprite *reaction_giant_button;
        sfSprite *reaction_game_selected;
        sfSprite *reaction_battle;
        sfSprite *mouse;
        sfSprite *settings_check;
        sfSprite *select_game;
        sfSprite **inventory_page_selected;
        sfSprite *slots;
        sfSprite **character_rotation;
        sfSprite *msg_save_game;
        sfSprite *trash;
        sfSprite *slots_skills;
        sfSprite *reaction_skills;
        sfSprite *pause_button;
        sfSprite *pause_page;
        sfSprite *msg_choose_player;
        sfSprite *delete_confirmation;
        sfSprite *charge;
        sfSprite *book;
        sfSprite *book_killed;
    } sprites_var;

    //STRUCT CLOCKS
    typedef struct s_clocks_var {
        sfClock *clock_loading;
        sfClock *clock_button;
        sfClock *clock_animation_equiped;
        sfClock *clock_show;
        sfClock *clock_key;
        sfClock *clock_event;
        sfClock *clock_player_name;
        sfTime time_loading;
        sfTime time_key;
        sfTime time_show;
        sfTime time_button;
        sfTime time_animation;
        sfTime time_event;
        sfTime time_player_name;
    } clocks_var;

    //STRUCT SOUNDS
    typedef struct s_sound_var {
        sfMusic *music_game;
        sfSoundBuffer *buffer;
    } sound_var;

    //STRUCT WINDOW
    typedef struct s_window_var {
        sfVideoMode video_mode;
        sfRenderWindow *window;
        sfEvent *event;
    } window_var;

    //STRUCT VECTORS
    typedef struct s_vectors_var {
        sfVector2f pos_origin;
        sfIntRect select_health;
        sfIntRect select_strength;
        sfIntRect select_armour;
        sfIntRect select_improve;
        sfIntRect select_char_rotation;
    } vectors_var;

    //STRUCT TEXTS
    typedef struct s_texts_var {
        sfFont *font;
        sfFont *font2;
        sfText *text;
    } texts_var;

    //STRUCT VAR
    typedef struct s_var {
        int easteregg_inventory_page;
        int book_page;
        bool show_msg;
        int player;
        int player_prev;
        int item_selected;
        int page;
        int prevpage;
        int sound_on;
        int sound_on_prev;
        int fps;
        int prev_fps;
        int quality;
        int level;
        int improve;
        int health;
        int strength;
        int armour;
        int prev_health;
        int prev_strength;
        int prev_armour;
        int prev_improve;
        int shield;
        int weapon;
        int animation_equiped;
        int inventory_page;
        int *list_saved;
        sfKeyCode key;
        char **list_name_saved;
        int current_game;
        int item_to_delete;
        char *prev_id_map;
        bool autosave;
        char **item_propeties;
        char *actual_id;
        char *player_name;
    } t_var;

    typedef struct s_info_inventory {
        int num_slot;
        sfVector2f pos;
        sfVector2f pos_quant;
        char *filepath;
        int in_use;
        int quantity;
        int type;
        struct s_info_inventory *next;
    } t_info_inventory;

    typedef struct s_info_saved {
        int num_slot;
        char *name;
        int saved;
        struct s_info_saved *next;
    } t_info_saved;

    //STRUCT ALL
    typedef struct s_all_var {
        struct Game_s *game;
        struct s_info_inventory **inventory;
        struct s_sound_var *sounds;
        struct s_sprites_var *sprites;
        struct s_vectors_var *vectors;
        struct s_clocks_var *clocks;
        struct s_window_var *windows;
        struct s_texts_var *texts;
        struct s_var *var;
    } all_var;

    //STRUCT BUTTONS
    typedef struct s_button {
        sfVector2i but;
        sfVector2i size;
    } new_button;

    //Function pointers for manage_pages
    typedef struct do_op {
        int op;
        void (*ptr)(all_var *all);
    } struct_pages;

#endif
