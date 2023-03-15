/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** builtins
*/

#include <my.h>
#include <minishell.h>

char *get_value_alias_w(char *str, alias_t *list)
{
    while (list) {
        if (my_strcmp(list->name, str) == 0)
            return (list->value);
        list = list->next;
    }
    return (NULL);
}

void get_alias_w(shell_t *shell, char *str)
{
    char *val = NULL;

    if (!shell->alias)
        return;
    val = get_value_alias_w(str, shell->alias);
    if (val[0] == '(') {
        val = val + 1;
        val[my_strlen(val) - 1] = 0;
    }
    if (val) {
        my_putstr(str);
        my_putstr(" is aliased to ");
        my_putstr(val);
        my_putchar('\n');
    }
}

void get_builtin_w(char *str)
{
    char **tab = my_split("alias builtins cd chdir echo exec exit glob history\
    printenv repeat set unalias unset where which", ' ');

    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], str) == 0) {
            printf("%s is a shell built-in\n", tab[i]);
            return;
        }
    }
}

void get_paths_w(shell_t *shell, char *str)
{
    char **all_paths = get_path(shell->env);
    char *tmp = "";

    for (int i = 0; all_paths[i]; i++) {
        tmp = my_strncat_dup(all_paths[i], "/", 1);
        tmp = my_strncat_dup(tmp, str, my_strlen(str));
        if (access(tmp, F_OK) == 0) {
            printf("%s\n", tmp);
        }
    }
}

int do_where(shell_t *shell, char **argv)
{
    int len = count_str(argv);

    if (len == 1) {
        my_putstr_error("where: Too few arguments.\n");
        return (1);
    }
    for (int i = 1; argv[i]; i++) {
        get_alias_w(shell, argv[i]);
        get_builtin_w(argv[i]);
        get_paths_w(shell, argv[i]);
    }
    return (0);
}