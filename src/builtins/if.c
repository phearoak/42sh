/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** if command
*/

#include <my.h>
#include <minishell.h>

void execute_if_echo(shell_t *shell)
{
    (void) shell;
}

int do_if(shell_t *shell, char *line)
{
    int value = 0;

    if (!line)
        return (0);
    value = parse_conditions(shell, line);
    if (value == -1) {
        my_putstr_error("Invalid parenthesis!\n");
        return (0);
    }
    return (0);
}