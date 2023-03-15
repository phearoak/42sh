/*
** EPITECH PROJECT, 2021
** setenv
** File description:
** setenv
*/

#include <my.h>
#include <minishell.h>

void replace_env(char **argv, char ***env)
{
    char *var = my_strncat_dup(argv[1], "=", 1);
    char *value = NULL;
    char *str = NULL;

    if (count_str(argv) > 2)
        value = argv[2];
    else
        value = "";
    str = my_strncat_dup(var, value, my_strlen(value));
    for (int i = 0; (*env)[i]; i++) {
        if (my_strncmp(var, (*env)[i], my_strlen(var)) == 0) {
            (*env)[i] = str;
        }
    }
}

void create_env(char **argv, char ***env)
{
    int size = count_str(*env);
    char **array = malloc(sizeof(char *) * (size + 2));
    char *var = my_strncat_dup(argv[1], "=", 1);
    char *value = NULL;

    if (count_str(argv) > 2)
        value = argv[2];
    else
        value = "";
    array[size + 1] = NULL;
    array[size] = my_strncat_dup(var, value, my_strlen(value));
    for (int i = 0; i < size; i++) {
        array[i] = (*env)[i];
    }
    *env = array;
}

int env_exist(char *var, char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(var, env[i], my_strlen(var)) == 0) {
            return (1);
        }
    }
    return (0);
}

int check_alpha_num(char *str, int max, int type)
{
    int valid = 1;

    for (int i = 0; str[i] && i < max + 1; i++) {
        if (!(str[i] >= '0' && str[i] <= '9' && type == 0) &&
        !(str[i] >= 'A' && str[i] <= 'Z') &&
        !(str[i] >= 'a' && str[i] <= 'z'))
            valid = 0;
    }
    if (valid == 0 && type == 0)
        my_putstr_error(
        "setenv: Variable name must contain alphanumeric characters.\n");
    if (valid == 0 && type == 1)
        my_putstr_error(
        "setenv: Variable name must begin with a letter.\n");
    if (valid == 0)
        return (84);
    return (0);
}

int do_command_setenv(char **argv, char ***env)
{
    if (count_str(argv) > 3) {
        my_putstr_error("setenv: Too many arguments.\n");
        return (84);
    }
    if (count_str(argv) == 1) {
        do_command_env(*env);
        return (0);
    }
    if (check_alpha_num(argv[1], strlen(argv[1]), 0) == 84 || \
    check_alpha_num(argv[1], 0, 1) == 84)
        return (84);
    if (env_exist(my_strncat_dup(argv[1], "=", 1), *env) == 1)
        replace_env(argv, env);
    else
        create_env(argv, env);
    if (my_strcmp("HOME", argv[1]) == 0)
        get_home(0, NULL, *env);
    return (0);
}