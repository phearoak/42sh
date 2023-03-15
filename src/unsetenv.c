/*
** EPITECH PROJECT, 2021
** unsetenv
** File description:
** unsetenv
*/

#include <my.h>
#include <minishell.h>

void remove_env(char *var, char ***env)
{
    int size = count_str(*env);
    char **array = malloc(sizeof(char *) * size);
    int i = 0;
    var = my_strncat_dup(var, "=", 1);

    array[size - 1] = NULL;
    for (int j = 0; j < size; j++) {
        if (my_strncmp(var, (*env)[j], my_strlen(var)) != 0) {
            array[i] = (*env)[j];
            i++;
        }
    }
    *env = array;
}

int do_command_unsetenv(char **argv, char ***env)
{
    if (count_str(argv) == 1) {
        my_putstr_error("unsetenv: Too few arguments.\n");
        return (84);
    }
    for (int i = 1; argv[i]; i++) {
        if (env_exist(my_strncat_dup(argv[i], "=", 1), *env) == 1) {
            remove_env(argv[i], env);
        }
    }
    return (0);
}