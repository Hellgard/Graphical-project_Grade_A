/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** destroy and free
*/

#include "rpg.h"

new_button **get_book_button(all_var *all)
{
    new_button **buttons = malloc(sizeof(new_button *) * 2);
    buttons[0] = create_button(220, 785, 100, 150);
    buttons[1] = create_button(1592, 785, 100, 150);
    return (buttons);
}

sfVector2f *get_book_button_pos(all_var *all)
{
    sfVector2f *buttons = malloc(sizeof(sfVector2f) * 2);
    buttons[0] = (sfVector2f){1200, 717};
    buttons[1] = (sfVector2f){1540, 717};
    return (buttons);
}

void buttons_book(all_var *all)
{
    int res;
    int i = 0;
    new_button **buttons = get_book_button(all);
    sfVector2f *pos = get_book_button_pos(all);

    while (i < 2) {
        res = is_button_pressed3(buttons[i], all, NULL, pos[i]);
        if (res == 2 && i == 0 && all->var->book_page > 1)
            all->var->book_page -= 2;
        if (res == 2 && i == 1 && all->var->book_page < 10)
            all->var->book_page += 2;
        i++;
    }
    free(buttons);
    free(pos);
}
