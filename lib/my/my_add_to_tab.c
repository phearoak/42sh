/*
** EPITECH PROJECT, 2021
** add to tab
** File description:
** add to tab
*/

#include <stdio.h>
#include <stdlib.h>
#include <my.h>

int get_len_tab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return (0);
    for (; tab[i]; i++);
    return (i);
}

char **my_add_to_tab(char **tab, char *str)
{
    int len = get_len_tab(tab);
    char **new_tab = my_malloc(sizeof(char *) * (len + 2));
    int index = 0;

    new_tab[len + 1] = NULL;
    for (; tab != NULL && tab[index]; index++)
        new_tab[index] = tab[index];
    new_tab[index] = my_strdup(str);
    return (new_tab);
}
