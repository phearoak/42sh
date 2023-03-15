/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** get alias
*/

#include <minishell.h>
#include <my.h>

void do_spe_alias(char *name, shell_t *shell)
{
    char *tmp = get_alias_command(name, shell->alias);
    list_sh_t *list;

    if (tmp)
        do_line_before(&list, shell, tmp);
}

char *get_alias_command(char *name, alias_t *alias)
{
    while (alias) {
        if (my_strcmp(name, alias->name) == 0)
            return (alias->value);
        alias = alias->next;
    }
    return (NULL);
}

void add_alias_argv(char *val, char **tab, char *ref)
{
    if (val == NULL) {
        *tab = my_strncat_dup(*tab, " ", 1);
        *tab = my_strncat_dup(*tab, ref, my_strlen(ref));
        return;
    }
    if (val[0] == '(' && val[my_strlen(val) - 1] == ')') {
        val = val + 1;
        val[my_strlen(val) - 1] = 0;
    }
    *tab = my_strncat_dup(*tab, " ", 1);
    *tab = my_strncat_dup(*tab, val, my_strlen(val));
}

void get_value_alias(char *str, alias_t *list, char **tab, int *ch)
{
    char *val = NULL;

    while (list) {
        if (my_strcmp(list->name, str) == 0) {
            val = my_strdup(list->value);
            *ch = 1;
        }
        list = list->next;
    }
    add_alias_argv(val, tab, str);
}

char *get_alias(char *argv, shell_t *shell)
{
    char **tab = my_split(argv, ' ');
    char *new_str = "";
    int ii = 0;
    int check = 1;

    for (; ii < 20 && check == 1; ii++) {
        if (new_str && new_str[strlen(new_str) - 1] == '\n')
            new_str[strlen(new_str) - 1] = 0;
        if (ii > 0) {
            tab = my_split(new_str, ' ');
            new_str = "";
        }
        check = 0;
        for (int i = 0; tab[i]; i++)
            get_value_alias(tab[i], shell->alias, &new_str, &check);
    }
    if (ii == 20) {
        my_putstr_error("Alias loop.\n");
        return (NULL);
    }
    return (new_str);
}