/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** builtins
*/

#include <my.h>
#include <minishell.h>

char *get_value_alias_wi(char *str, alias_t *list)
{
    while (list) {
        if (my_strcmp(list->name, str) == 0)
            return (list->value);
        list = list->next;
    }
    return (NULL);
}

int get_alias_wi(shell_t *shell, char *str)
{
    char *val = NULL;

    if (!shell->alias)
        return (0);
    val = get_value_alias_wi(str, shell->alias);
    if (val[0] == '(') {
        val = val + 1;
        val[my_strlen(val) - 1] = 0;
    }
    if (val) {
        printf("%s: \t aliased to %s\n", str, val);
        return (1);
    }
    return (0);
}

int get_builtin_wi(char *str)
{
    char **tab = my_split("alias builtins cd chdir echo exec exit glob history\
    printenv repeat set unalias unset where which", ' ');

    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], str) == 0) {
            printf("%s: shell built-in command.\n", tab[i]);
            return (1);
        }
    }
    return (0);
}

int get_paths_wi(shell_t *shell, char *str)
{
    char **all_paths = get_path(shell->env);
    char *tmp = "";

    for (int i = 0; all_paths[i]; i++) {
        tmp = my_strncat_dup(all_paths[i], "/", 1);
        tmp = my_strncat_dup(tmp, str, my_strlen(str));
        if (access(tmp, F_OK) == 0) {
            printf("%s\n", tmp);
            return (1);
        }
    }
    return (0);
}

int do_which(shell_t *shell, char **argv)
{
    int len = count_str(argv);
    int check = 0;

    if (len == 1) {
        my_putstr_error("which: Too few arguments.\n");
        return (1);
    }
    for (int i = 1; argv[i]; i++) {
        check = get_alias_wi(shell, argv[i]);
        if (check == 0)
            check = get_builtin_wi(argv[i]);
        if (check == 0)
            check = get_paths_wi(shell, argv[i]);
        if (check == 0)
            printf("%s: Command not found.\n", argv[i]);
    }
    return (0);
}