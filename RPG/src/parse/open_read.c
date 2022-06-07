/*
** EPITECH PROJECT, 2021
** parsing.c
** File description:
** parse
*/

#include "rpg.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int nb_cages (char *str, char sep)
{
    int num = 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == sep)
            num++;
    return (num);
}

char **my_str_to_array(char *str, char sep)
{
    int num = nb_cages (str, sep);
    char **result = malloc((num + 1) * sizeof(char *));
    int j = 0, z = 0, x = 0, i = 0;

    while (j < num) {
        x = 0;
        while (str[x + z] != '\0' && (str[x + z] != sep))
            x++;
        result[j] = malloc(x + 1);
        for (i = 0; i < x; i++) {
            result[j][i] = str[z];
            z++;
        }
        result[j][i] = '\0';
        z++;
        i = 0;
        j++;
    }
    result[j] = NULL;
    return (result);
}

char *open_read_file(char *path)
{
    struct stat st;
    stat (path, &st);
    int fd = open (path, O_RDONLY);
    int sz = st.st_size;

    if (fd == -1)
        return ("you need to put a file on paramater");
    char *buff = malloc (sz + 1);
    int rd = read (fd, buff, sz);
    if (rd == -1)
        return ("read failed");
    buff [sz] = '\0';
    close (fd);
    return (buff);
}
