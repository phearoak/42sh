/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** delete slash
*/

#include <my.h>
#include <stdlib.h>

char *delete_slash(char *str)
{
    int len = 0;
    char *new = NULL;
    int index = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != '\\')
            len++;
    }
    new = my_malloc(sizeof(char) * (len + 1));
    my_memset(new, '\0', len + 1);
    for (int i = 0; str[i]; i++) {
        if (str[i] != '\\') {
            new[index] = str[i];
            index++;
        }
    }
    return (new);
}