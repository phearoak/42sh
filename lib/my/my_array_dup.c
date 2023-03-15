/*
** EPITECH PROJECT, 2021
** Gameoflife
** File description:
** dup an array (char **)
*/

#include <my.h>
#include <string.h>
#include <stdlib.h>

int get_size_array(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}

char **my_array_dup(char **map)
{
    int size = get_size_array(map);
    char **copy = malloc(sizeof(char *) * (size + 1));

    if (copy == NULL)
        return (NULL);
    for (int i = 0; map[i]; i++) {
        copy[i] = strdup(map[i]);
        if (copy[i] == NULL)
            return (NULL);
    }
    copy[size] = NULL;
    return (copy);
}
