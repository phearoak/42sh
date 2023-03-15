/*
** EPITECH PROJECT, 2021
** do cd
** File description:
** do cd
*/

#include <my.h>
#include <minishell.h>

void cd_to_setenv(char *var, char *value, char ***env)
{
    char *array[4] = {"setenv", var, value, 0};

    do_command_setenv(array, env);
}

int do_cd_no_parameter(char ***env)
{
    char *home = NULL;

    home = get_value_env("HOME", *env);
    if (home == NULL || my_strcmp("", home) == 0) {
        if (get_home(1, "cd: No home directory.\n", *env) == NULL)
            return (84);
    }
    if (env_exist("PWD", *env) == 1)
        cd_to_setenv("OLDPWD", get_value_env("PWD", *env), env);
    cd_to_setenv("PWD", home, env);
    if (chdir(home) == -1) {
        my_putstr_error(home);
        my_putstr_error(": Permission denied.\n");
        return (84);
    }
    return (0);
}

int do_cd_minus(char ***env)
{
    char *old = NULL;
    char pwd[1024];

    old = get_value_env("OLDPWD", *env);
    if (old == NULL || my_strcmp("", old) == 0) {
        my_putstr_error(": No such file or directory.\n");
        return (84);
    }
    getcwd(pwd, 1024);
    cd_to_setenv("OLDPWD", pwd, env);
    cd_to_setenv("PWD", old, env);
    if (chdir(old) == -1) {
        my_putstr_error(old);
        my_putstr_error(": Permission denied.\n");
        return (84);
    }
    return (0);
}

int do_cd_direct(char *path, char ***env)
{
    int check = is_dir(path);
    char *pwd = NULL;

    if (check == 84)
        return (84);
    pwd = get_value_env("PWD", *env);
    cd_to_setenv("OLDPWD", pwd, env);
    cd_to_setenv("PWD", path, env);
    if (chdir(path) == -1) {
        my_putstr_error(path);
        my_putstr_error(": Permission denied.\n");
        return (84);
    }
    return (0);
}

int do_command_cd(char **argv, char ***env)
{
    int size = count_str(argv);

    if (size > 2) {
        my_putstr_error("cd: Too many arguments.\n");
        return (84);
    }
    if (size == 1)
        return (do_cd_no_parameter(env));
    if (my_strcmp(argv[1], "-") == 0)
        return (do_cd_minus(env));
    if (my_strncmp(argv[1], "/", 1) == 0)
        return (do_cd_direct(argv[1], env));
    return (do_cd_indirect(argv[1], env));
}