/*
** EPITECH PROJECT, 2021
** show env
** File description:
** show env
*/

#include <my.h>
#include <minishell.h>

int do_command_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return (0);
}