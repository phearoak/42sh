/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** add at index
*/

#include <minishell.h>
#include <my.h>

char *add_at_index(char *str, int index, char c)
{
    int len = my_strlen(str) + 2;
    char *new = malloc(sizeof(char) * len);
    int c_i = 0;

    my_memset(new, '\0', len);
    for (; str[c_i] && c_i < index; c_i++)
        new[c_i] = str[c_i];
    new[c_i] = c;
    for (int i = c_i + 1; str[c_i]; c_i++, i++)
        new[i] = str[c_i];
    return (new);
}

char *remove_at_index(char *str, int index)
{
    int len = my_strlen(str);
    char *new = malloc(sizeof(char) * len);
    int c_i = 0;

    my_memset(new, '\0', len);
    for (; str[c_i] && c_i < index; c_i++)
        new[c_i] = str[c_i];
    c_i++;
    for (int i = c_i - 1; str[c_i]; c_i++, i++)
        new[i] = str[c_i];
    return (new);
}