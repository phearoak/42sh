/*
** EPITECH PROJECT, 2021
** count str
** File description:
** count str
*/

#include <my.h>
#include <minishell.h>

int count_str(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}