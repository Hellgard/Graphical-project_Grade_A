/*
** EPITECH PROJECT, 2022
** move.c
** File description:
** Function that manage keys input
*/

#include "rpg.h"

void check_idel(scene_t *scene, obj_t **obj)
{
    for (int i = 0; obj[i]; i++) {
        if (obj[i]->pos_target.x == obj[i]->pos.x &&
        obj[i]->pos_target.y == obj[i]->pos.y)
            scene->select_character.top = 0;
    }
}

void loop_evolution(all_var *all)
{
    while (all->game->player->xp >= all->game->player->palier) {
        all->game->player->xp -= all->game->player->palier;
        all->game->player->level += 1;
        all->game->player->palier += 5;
        all->game->player->attack += 5;
        all->game->player->defense += 5;
        all->game->player->speed += 5;
        all->game->player->max_life += 3;
        all->game->player->life = all->game->player->max_life;
        if (all->game->player->level % 3 == 0)
            all->game->player->point += 1;
    }
}

void add_loots(all_var *all)
{
    int i;
    int rand_loots = 10;
    int random;

    for (i = 0; all->game->enemy[all->game->attack_id]->loots[i + 2]; i++) {
        random = rand () % rand_loots;
        add_element_inventory(all,
        all->game->enemy[all->game->attack_id]->loots[i], random);
        rand_loots -= 1;
    }
    add_element_inventory(all,
    all->game->enemy[all->game->attack_id]->loots[i], 1);
    i++;
    random = rand () % 100;
    if (random < 4) {
        add_element_inventory(all,
        all->game->enemy[all->game->attack_id]->loots[i], 1);
    }
}

void Enemy_dead(all_var *all)
{
    int i = 0;

    if (all->game->enemy[all->game->attack_id]->life <= 0) {
        i = all->game->enemy[all->game->attack_id]->gaved_xp;
        all->game->player->xp += i;
        loop_evolution(all);
        add_loots(all);
        all->game->on_attack = 0;
        if (all->game->enemy[all->game->attack_id]->isBoss != 1) {
            i = all->game->enemy[all->game->attack_id]->li;
            all->game->enemy[all->game->attack_id]->life = i;
        }
        sfClock_restart(all->game->clock);
        all->var->page = PAGE_GAME;
        free(all->game->Combat_ambiance->combat_infos);
    }
}

void event_combat(all_var *all)
{
    Enemy_dead(all);
    int i = 0;

    if (all->game->player->life <= 0) {
        sfRenderWindow_setMouseCursorVisible(all->windows->window, sfTrue);
        all->game->player->life = all->game->player->max_life / 3;
        all->game->player->xp = 0;
        all->game->on_attack = 0;
        i = all->game->enemy[all->game->attack_id]->li;
        all->game->enemy[all->game->attack_id]->life = i;
        sfClock_restart(all->game->clock);
        all->var->page = PAGE_GAME;
        free(all->game->Combat_ambiance->combat_infos);
    }
}
