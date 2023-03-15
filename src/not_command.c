/*
** EPITECH PROJECT, 2021
** not command
** File description:
** not command
*/

#include <my.h>
#include <minishell.h>

int is_containing(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (1);
    return (0);
}

int command_not_exist(char *command)
{
    struct stat sb;

    if (command == NULL)
        return (0);
    my_putstr_error(command);
    stat(command, &sb);
    if (is_containing(command, '/') && S_ISDIR(sb.st_mode) == 1) {
        my_putstr_error(": Permission denied.\n");
        return (1);
    }
    my_putstr_error(": Command not found.\n");
    return (1);
}