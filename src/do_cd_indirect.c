/*
** EPITECH PROJECT, 2021
** do cd indirect
** File description:
** do cd indirect
*/

#include <my.h>
#include <minishell.h>

int do_cd_indirect(char *path, char ***env)
{
    char *pwd = get_value_env("PWD", *env);
    char *old = pwd;
    char get_pwd[1024];

    pwd = my_strncat_dup(pwd, "/", 1);
    pwd = my_strncat_dup(pwd, path, my_strlen(path));
    if (is_dir(path) == 84)
        return (1);
    if (chdir(path) == -1) {
        my_putstr_error(path);
        my_putstr_error(": Permission denied.\n");
        return (84);
    }
    getcwd(get_pwd, 1024);
    cd_to_setenv("OLDPWD", old, env);
    cd_to_setenv("PWD", get_pwd, env);
    return (0);
}