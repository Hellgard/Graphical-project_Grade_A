/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

void print_prev_battle_ext(all_var *all, int i, int life_taken, sfTime time)
{
    sfRenderWindow_setMouseCursorVisible(all->windows->window, sfFalse);
    draw_prev_battle(all);
    time = sfClock_getElapsedTime(all->game->clock_combat);
    if (sfTime_asSeconds(time) > 3) {
        sfSprite_setPosition(all->game->enemy[all->game->attack_id]->sprite,
        (sfVector2f){800, 300});
        sfRenderWindow_drawSprite(all->windows->window,
        all->game->enemy[all->game->attack_id]->sprite, NULL);
        i = rand() % all->game->enemy[all->game->attack_id]->how_many_comp;
        life_taken = my_getnbr(all->game->enemy[all->game->attack_id]->
        attacks_damages[i]);
        life_taken -= all->game->player->defense / 10;
        enemy_attack_text(all, i, life_taken);
        all->game->player->life -= life_taken;
        all->game->turn_combat = 0;
        sfClock_restart(all->game->clock_combat);
    }
    sfRenderWindow_drawSprite(all->windows->window,
    all->game->enemy[all->game->attack_id]->sprite, NULL);
}

void print_prev_battle(all_var *all)
{
    sfTime time;
    int i = 0;
    int life_taken = 0;

    sfSprite_setPosition(all->game->enemy[all->game->attack_id]->sprite,
    (sfVector2f){1100, 50});
    sfRenderWindow_drawSprite(all->windows->window,
    all->game->scene->Combat_ambiance, NULL);
    if (all->game->turn_combat == 0) {
        sfRenderWindow_setMouseCursorVisible(all->windows->window, sfTrue);
        sfRenderWindow_drawSprite(all->windows->window,
        all->game->enemy[all->game->attack_id]->sprite, NULL);
        draw_prev_battle(all);
        buttons_prev_battle(all);
    } else if (all->game->turn_combat == 1) {
        print_prev_battle_ext(all, i, life_taken, time);
    }
    print_bars_battle(all);
    print_info_combat(all);
    event_combat(all);
}

int check_main_quest(all_var *all)
{
    for (;all->game->quest_list->str != NULL; all->game->quest_list =
    all->game->quest_list->next)
        if (strcmp(all->game->quest_list->id, "0") == 0)
            break;
    if (all->game->quest_list->str != NULL &&
    all->game->quest_list->how_many == all->game->quest_list->state &&
    strcmp(all->game->quest_list->id, "0") == 0) {
        credit(all->windows->window);
        return (1);
    }
    return (0);
}

int check_boss_life(obj_t *obj, all_var *all)
{
    for (int i = 0; all->game->enemy[i]; i++)
        if (strcmp(all->game->enemy[i]->id, obj->linked_id_2) == 0 &&
        all->game->enemy[i]->life <= 0)
            return 0;
    return 1;
}

void valid_boss(all_var *all, obj_t *boss)
{
    int i;
    int count = -1;

    for (i = 0; all->game->quest_list->elem_quest[i]; i++) {
        if (strcmp(all->game->quest_list->elem_quest[i]->id,
        boss->linked_id_2) == 0 && strcmp(
        all->game->quest_list->elem_quest[i]->quest_id, boss->linked_id) == 0)
            break;
        else
            count++;
    }
    if (all->game->quest_list->elem_quest[i] && check_boss_life(boss, all)
    == 0 && i != count && all->game->quest_list->elem_quest[i]->is_actual
    != 1) {
        boss->perm->Text = 0;
        all->game->quest_list->elem_quest[i]->is_actual = 1;
        all->game->quest_list->state += 1;
    }
}
