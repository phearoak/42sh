/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** check_globbing
*/

#include <stdio.h>
#include <minishell.h>

int is_there_a_globbing(char *str, int open)
{
    if (str[0] == '\0') {
        return (0);
    }
    if (str[0] == '*' || str[0] == '?') {
        return (1);
    }
    if (str[0] == '[') {
        open = 1;
    }
    if (str[0] == ']' && open == 1) {
        return (1);
    }
    return (is_there_a_globbing(str + 1, open));
}

int check_is_globbing(char **av)
{
    for (int i = 0; av[i]; i++) {
        if (is_there_a_globbing(av[i], 0) == 1)
            return (1);
    }
    return (0);
}