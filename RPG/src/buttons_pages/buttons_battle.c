/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_prevbuttons_battle_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 4);
    buttons[0] = create_button(1170, 670, 380, 125);
    buttons[1] = create_button(1550, 670, 380, 125);
    buttons[2] = create_button(1170, 840, 380, 125);
    buttons[3] = create_button(1550, 840, 380, 125);
    return (buttons);
}

sfVector2f *get_prevbuttons_battle_button_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 4);
    buttons[0] = (sfVector2f){1200, 717};
    buttons[1] = (sfVector2f){1540, 717};
    buttons[2] = (sfVector2f){1200, 877};
    buttons[3] = (sfVector2f){1540, 877};
    return (buttons);
}

sfSprite **reaction_prevbuttons_battle_button(all_var *all)
{
    sfSprite **reaction = malloc(sizeof(sfSprite *) * 4);
    reaction[0] = all->sprites->reaction_battle;
    reaction[1] = all->sprites->reaction_battle;
    reaction[2] = all->sprites->reaction_battle;
    reaction[3] = all->sprites->reaction_battle;
    return (reaction);
}

void attack(comp_t *comp, combat_t *enemy, all_var *all)
{
    char *str = malloc(sizeof(char) * 4);
    intToStr(comp->attacks_damages[comp->actual_attack] +
    (all->game->player->attack / 10), str, 0);
    enemy->life -= comp->attacks_damages[comp->actual_attack];
    all->game->Combat_ambiance->combat_infos =
    my_strcat(all->game->Combat_ambiance->combat_infos, "You attacked with ");
    all->game->Combat_ambiance->combat_infos =
    my_strcat(all->game->Combat_ambiance->combat_infos,
    comp->attacks_name[comp->actual_attack]);
    all->game->Combat_ambiance->combat_infos =
    my_strcat(all->game->Combat_ambiance->combat_infos, "\n");
    all->game->Combat_ambiance->combat_infos =
    my_strcat(all->game->Combat_ambiance->combat_infos, "The enemy lose ");
    all->game->Combat_ambiance->combat_infos =
    my_strcat(all->game->Combat_ambiance->combat_infos, str);
    all->game->Combat_ambiance->combat_infos =
    my_strcat(all->game->Combat_ambiance->combat_infos, "hp\n");
}

void buttons_battle(all_var *all)
{
    int res;
    int i = 0;
    new_button **buttons = get_prevbuttons_battle_button(all);
    sfVector2f *pos = get_prevbuttons_battle_button_pos(all);
    sfSprite **reaction = reaction_prevbuttons_battle_button(all);

    while (i < 4) {
        res = is_button_pressed3(buttons[i], all, reaction[i], pos[i]);
        if (res == 2)
            buttons_battle_actions(all, i);
        i++;
    }
    free(buttons);
    free(pos);
    free(reaction);
}
