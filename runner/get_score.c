/*
** EPITECH PROJECT, 2021
** get_score.c
** File description:
** score
*/

#include <game.h>

void put_point(score_s *point, char *string)
{
    point->str = string;
    point->Font = sfFont_createFromFile("image/font.otf");
    point->Text = sfText_create();
    sfText_setCharacterSize(point->Text, 50);
    sfText_setString(point->Text, point->str);
    sfText_setFont(point->Text, point->Font);
    point->pos.x = 120;
    point->pos.y = 30;
    sfText_setPosition(point->Text, point->pos);
}

void put_score(score_s *score)
{
    score->str = "score: ";
    score->Font = sfFont_createFromFile("image/font.otf");
    score->Text = sfText_create();
    sfText_setCharacterSize(score->Text, 50);
    sfText_setString(score->Text, score->str);
    sfText_setFont(score->Text, score->Font);
    score->pos.x = 0;
    score->pos.y = 30;
    sfText_setPosition(score->Text, score->pos);
}
