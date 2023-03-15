/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** add a string at an index in an array
*/

#include <minishell.h>
#include <my.h>

char **add_str_at_index(char **array, char *str, int index)
{
    char **new_array = malloc((count_str(array) + 2) * sizeof(char *));
    int j = 0;

    for (int i = 0; array[i]; i++, j++) {
        if (i == index) {
            new_array[j] = str;
            j++;
        }
        new_array[j] = array[i];
    }
    new_array[j] = NULL;
    return (new_array);
}