/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** if parser
*/

#include <my.h>
#include <minishell.h>

static int has_endif(char **script, int *y)
{
    int start = *y;

    for (; script[(*y) + 1]; (*y)++)
        if (my_strcmp(script[(*y)], "endif") == 0) {
            *y = start;
            return (1);
        }
    return (0);
}

int parse_if(shell_t *shell, char **script, int *y)
{
    if (my_strcmp(script[(*y)] + my_strlen(script[(*y)]) - 4, "then") != 0) {
        do_if(shell, script[(*y)]);
        return (1);
    }
    if (!has_endif(script, y)) {
        my_putstr_error("then: then/endif not found.\n");
        return (1);
    }
    do_if(shell, script[(*y)]);
    for (; script[(*y)+1] && my_strcmp(script[(*y)], "endif") != 0; (*y)++);
    return (1);
}