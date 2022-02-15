/*
** EPITECH PROJECT, 2021
** player_info.c
** File description:
** player
*/

#include "game.h"

player_s *player_info(int bool)
{
    player_s *player = malloc(sizeof(player_s));

    player->i = 0;
    player->jump = 0;
    player->pos.x = 40;
    player->pos.y = 840;
    player->rect.width = 200;
    player->rect.height = 200;
    player->clock = 100000;
    if (bool == 0)
        player->texture = sfTexture_createFromFile("image/Player.png", NULL);
    else
        player->texture = sfTexture_createFromFile("image/mario_paper.png"\
        , NULL);
    player->sprite = sfSprite_create();

    return (player);
}

backs_s *back_info(backs_s *back, int i)
{
    back->sprite = sfSprite_create();
    back->sprite2 = sfSprite_create();
    back->rect.width = 1920;
    back->rect.height = 1080;

    if (i == 1)
        back->texture = sfTexture_createFromFile("image/back4.png", NULL);
    else if (i == 2)
        back->texture = sfTexture_createFromFile("image/back3.png", NULL);
    else {
        if (i == 3)
            back->texture = sfTexture_createFromFile("image/back2.png", NULL);
        else
            back->texture = sfTexture_createFromFile("image/back.jpg", NULL);
    }
    return (back);
}

backs_s *manage_back_info(void)
{
    backs_s *back = malloc(sizeof(backs_s));
    back->prev = NULL;

    for (int i = 0; i < 4; i++) {
        back = back_info(back, i);
        back->pos.x = 0;
        back->pos.y = 0;
        back->pos2.x = 1920;
        back->pos2.y = 0;
        if (i == 3)
            break;
        back->next = malloc(sizeof(backs_s));
        back->next->prev = back;
        back = back->next;
    }
    back->next = NULL;
    return (back);
}

void print_h(void)
{
    my_putstr("Welcome in the usage:\n");
    my_putstr("this is a pshychedelic runner\n");
    my_putstr("you are toad or mario, you eat something a bit out of date\n");
    my_putstr("you need to survive in this pshy and glitched world\n");
    my_putstr("warning about the big shrooms they are dangerous, carefull");
    my_putstr("of the glitched world\n");
    my_putstr("to play, use the key space\n");
    my_putstr("you can also quit the game using Esc or clicking on the Xr\n\0");
}

sound_s manage_sound(void)
{
    sound_s *jumping = malloc(sizeof(sound_s));
    jumping->buffer = sfSoundBuffer_createFromFile("image/Glitch.wav");
    jumping->sound = sfSound_create();
    sfSound_setBuffer(jumping->sound, jumping->buffer);
    sfSound_setVolume(jumping->sound, 60);
    return (*jumping);
}
