/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "rpg.h"

void print_page_levels(all_var *all)
{
    csfml_print_sprites(all, all->sprites->background_menu,
    all->vectors->pos_origin);
    buttons_levels(all);
    csfml_print_sprites(all, all->sprites->page_levels,
    all->vectors->pos_origin);
}

void print_page_mainmenu(all_var *all)
{
    csfml_print_sprites(all, all->sprites->background_menu,
    all->vectors->pos_origin);
    buttons_mainmenu(all);
    csfml_print_sprites(all, all->sprites->page_mainmenu,
    all->vectors->pos_origin);
    if (all->var->show_msg == true)
        csfml_print_sprites(all, all->sprites->msg_choose_player,
        (sfVector2f){0, 0});
}

char *get_player_name(all_var *all, char *player_name)
{
    char temp[] = "0";
    sfKeyCode key = 1;

    all->clocks->time_player_name =
    sfClock_getElapsedTime(all->clocks->clock_player_name);
    for (int i = 0; i < 26; i++) {
        key = i;
        if (sfKeyboard_isKeyPressed(key) == sfTrue &&
        sfTime_asSeconds(all->clocks->time_player_name) > 0.1) {
            temp[0] = (char)(i + 97);
            player_name = my_strcat(player_name, temp);
            sfClock_restart(all->clocks->clock_player_name);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyBackSlash) == sfTrue &&
    sfTime_asSeconds(all->clocks->time_player_name) > 0.1) {
        player_name[my_strlen(player_name) - 1] = '\0';
        sfClock_restart(all->clocks->clock_player_name);
    }
    return (player_name);
}

void print_page_portada(all_var *all)
{
    static char *player_name = "";
    csfml_print_sprites(all, all->sprites->background_menu,
    all->vectors->pos_origin);
    sfText_setColor(all->texts->text, sfBlack);
    sfText_setCharacterSize(all->texts->text, 100);
    sfText_setString(all->texts->text, "THE ETERNAL RETURN");
    sfText_setPosition(all->texts->text, (sfVector2f) {500, 250});
    sfRenderWindow_drawText(all->windows->window, all->texts->text, NULL);
    sfText_setCharacterSize(all->texts->text, 70);
    sfText_setPosition(all->texts->text, (sfVector2f) {650, 550});
    player_name = get_player_name(all, player_name);
    sfText_setString(all->texts->text, player_name);
    if (my_strlen(player_name) == 0)
        sfText_setString(all->texts->text, "Introduce your name");
    sfRenderWindow_drawText(all->windows->window, all->texts->text, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && my_strlen(
    player_name) > 3) {
        all->var->player_name = my_strdup(player_name);
        all->var->page = 2;
    }
}

void print_page_charge(all_var *all)
{
    csfml_print_sprites(all, all->sprites->charge, (sfVector2f){0, 0});
    sfRenderWindow_display(all->windows->window);
}
