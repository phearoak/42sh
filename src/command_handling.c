/*
** EPITECH PROJECT, 2021
** command handling
** File description:
** command handling
*/

#include <my.h>
#include <minishell.h>

int command_handling3(char *command)
{
    if (my_strcmp("if", command) == 0)
        return (1);
    return (0);
}

int command_handling2(char *command)
{
    if (my_strcmp("set", command) == 0)
        return (1);
    if (my_strcmp("unset", command) == 0)
        return (1);
    if (my_strcmp("alias", command) == 0)
        return (1);
    if (my_strcmp("unalias", command) == 0)
        return (1);
    if (my_strcmp("exec", command) == 0)
        return (1);
    if (my_strcmp("glob", command) == 0)
        return (1);
    if (my_strcmp("printenv", command) == 0)
        return (1);
    if (my_strcmp("repeat", command) == 0)
        return (1);
    if (my_strcmp("where", command) == 0 || my_strcmp("which", command) == 0)
        return (1);
    return (command_handling3(command));
}

int command_handling(char *command)
{
    if (my_strcmp("cd", command) == 0 || my_strcmp("chdir", command) == 0)
        return (1);
    if (my_strcmp("setenv", command) == 0)
        return (1);
    if (my_strcmp("unsetenv", command) == 0)
        return (1);
    if (my_strcmp("env", command) == 0)
        return (1);
    if (my_strcmp("echo", command) == 0)
        return (1);
    if (my_strncmp("./", command, 2) == 0)
        return (1);
    if (command[0] == '(')
        return (1);
    if (my_strcmp("history", command) == 0)
        return (1);
    if (my_strcmp("builtins", command) == 0)
        return (1);
    return (command_handling2(command));
}