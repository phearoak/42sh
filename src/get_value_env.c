/*
** EPITECH PROJECT, 2021
** get value env
** File description:
** get value env
*/

#include <my.h>
#include <minishell.h>

char *get_value_env(char *var, char **env)
{
    char *value = NULL;

    var = my_strncat_dup(var, "=", 1);
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(var, env[i], my_strlen(var)) == 0) {
            value = env[i];
            value = value + my_strlen(var);
            return (value);
        }
    }
    return (NULL);
}