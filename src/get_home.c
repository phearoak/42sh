/*
** EPITECH PROJECT, 2021
** get home
** File description:
** get home
*/

#include <my.h>
#include <minishell.h>

char *get_home(int i, char *error, char **env)
{
    static char *home = NULL;

    if (i == 0) {
        home = get_value_env("HOME", env);
        if (home == NULL)
            return (NULL);
        if (my_strcmp(home, "") == 0)
            home = NULL;
        return (home);
    }
    if (home == NULL) {
        my_putstr_error(error);
        return (NULL);
    }
    return (home);
}