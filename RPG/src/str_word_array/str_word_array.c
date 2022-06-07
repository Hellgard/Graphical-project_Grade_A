/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "rpg.h"

char *save_text(int fd, char *filepath)
{
    int i = 0;
    int size = 0;
    long max_size = 0;
    char *arraytext;

    size = 30000;
    arraytext = my_calloc(size + 1, sizeof(char));
    my_memset(arraytext, '\0', size + 1);
    read(fd, arraytext, size);
    if (my_strlen(arraytext) <= 1)
        return ("");
    return (arraytext);
}

char **save_word(char *arraytext, char separator, char *filepath)
{
    int len = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    char **sentences;

    sentences = my_calloc(quantity_sentences(my_strlen(arraytext),
    arraytext, separator) * 2 + 50, sizeof(char *));
    while (i < my_strlen(arraytext)) {
        len = len_sentence(arraytext, separator, i);
        sentences[j] = my_calloc(len * 2 + 20, sizeof(char));
        k = 0;
        while (arraytext[i] != separator && arraytext[i] != '\0' &&
        arraytext[i] != '\n')
            sentences[j][k++] = arraytext[i++];
        j++;
        i++;
    }
    sentences[j] = NULL;
    return (sentences);
}
