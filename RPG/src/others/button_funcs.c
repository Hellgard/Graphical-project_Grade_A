/*
** EPITECH PROJECT, 2021
** button_funcs.c
** File description:
** button_funcs
*/

#include "rpg.h"

void is_button_pressed_ext(all_var *all, new_button *button)
{
    sfVector2u size = sfRenderWindow_getSize(all->windows->window);

    button->but.x = size.x * button->but.x / 1920;
    button->size.x = size.x * button->size.x / 1920;
    button->but.y = size.y * button->but.y / 1080;
    button->size.y = size.y * button->size.y / 1080;
}

int is_button_pressed3(new_button *button, all_var *all, sfSprite *sprite,
sfVector2f vector)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->windows->window);
    is_button_pressed_ext(all, button);

    all->clocks->time_button = sfClock_getElapsedTime(
    all->clocks->clock_button);
    if ((mouse.x > button->but.x && mouse.x < (button->but.x + button->size.x))
    && (mouse.y > button->but.y && mouse.y < (button->but.y +
    button->size.y))) {
        if (sprite != NULL) {
            sfSprite_setPosition(sprite, vector);
            sfRenderWindow_drawSprite(all->windows->window, sprite, NULL);
        }
        if (all->windows->event->type == sfEvtMouseButtonPressed &&
        sfTime_asSeconds(all->clocks->time_button) > 0.3) {
            sfClock_restart(all->clocks->clock_button);
            return (2);
        }
        return (1);
    }
    return (0);
}

new_button *create_button(int x, int y, int size_x, int size_y)
{
    new_button *temp = malloc(sizeof(new_button));

    temp->but = (sfVector2i){x, y + 65};
    temp->size = (sfVector2i){size_x, size_y};
    return (temp);
}

void get_item_selected(all_var *all)
{
    int inv_page = all->var->inventory_page;
    t_info_inventory *tmp = all->inventory[inv_page]->next;
    sfVector2f pos;
    sfVector2f pos2;
    int res = -1;

    while (tmp != NULL) {
        pos = get_inventory_pos(tmp->num_slot);
        pos2 = pos;
        pos2.x -= 15;
        pos2.y += 43;
        res = is_button_pressed3(create_button(pos.x, pos.y, 120, 120),
        all, all->sprites->reaction_inventory, pos2);
        if (res == 2 || all->var->item_selected == tmp->num_slot) {
            set_item(all, pos2, tmp);
        }
        tmp = tmp->next;
    }
}

void get_positions_print(all_var *all)
{
    int i = 0;
    int j = 0;

    while (i < 5) {
        j = 0;
        while (j < 4) {
            j++;
        }
        i++;
    }
}
