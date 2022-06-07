/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** compare two string
*/

int compare_string(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0')
        i++;
    while (s2[j] != '\0')
        j++;
    if (i < j)
        return (-1);
    else if (i == j)
        return (0);
    else
        return (1);
}

int compare_char(char c, char d)
{
    int j = c - d;
    return (j);
}

int compare_string2(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0') {
        if (s1[i] == s2[i])
            i++;
        else
            j = j + compare_char(s1[i], s2[i]);
        return (j);
    }
    return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    if (compare_string(s1, s2) == -1)
        return (-1);
    if (compare_string(s1, s2) == 0) {
        if (compare_string2(s1, s2) < 0)
            return (-1);
        if (compare_string2(s1, s2) == 0)
            return (0);
        if (compare_string2(s1, s2) > 0)
            return (1);
    }
    if (compare_string(s1, s2) > 0)
        return (1);
    return (0);
}
