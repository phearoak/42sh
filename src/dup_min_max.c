/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** dup min max
*/

#include <minishell.h>

char *dup_min_max(char *str, int start, int end)
{
    char *dest = malloc(end - start + 1);
    int index = 0;

    for (int i = start; i < end; i++) {
        dest[index] = str[i];
        index++;
    }
    dest[index] = '\0';
    return (dest);
}