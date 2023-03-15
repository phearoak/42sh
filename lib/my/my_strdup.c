/*
** EPITECH PROJECT, 2020
** str_dup
** File description:
** str_dup
*/

#include <stdlib.h>

char *my_strdup_target(char *str, int min, int max)
{
    int i = min;
    char *dup = NULL;

    for (; i <= max && str[i]; i++);
    dup = malloc(i + 1 - min);
    if (!dup)
        return (NULL);
    for (int j = 0; j+min < i; j++)
        dup[j] = str[j+min];
    dup[i-min] = 0;
    return (dup);
}

char *my_strdup(char *str)
{
    int i = 0;
    char *dup = NULL;

    for (; str[i]; i++);
    dup = malloc(i + 1);
    dup[i] = 0;
    for (int j = 0; j < i; j++)
        dup[j] = str[j];
    return (dup);
}