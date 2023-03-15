/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** do alias
*/

#include <minishell.h>
#include <my.h>

void pushback_alias(char *name, char *value, alias_t **list)
{
    if (*list) {
        if (my_strcmp((*list)->name, name) == 0) {
            (*list)->value = my_strdup(value);
            return;
        }
        pushback_alias(name, value, &((*list)->next));
        return;
    }
    *list = my_malloc(sizeof(alias_t));
    (*list)->next = NULL;
    (*list)->name = delete_slash(name);
    (*list)->value = delete_slash(value);
}

void print_all_alias(alias_t *alias)
{
    while (alias) {
        printf("%s\t%s\n", alias->name, alias->value);
        alias = alias->next;
    }
}

void make_alias(char **argv, shell_t *shell, int len)
{
    char *value = "(";

    if (len == 3) {
        pushback_alias(argv[1], argv[2], &shell->alias);
        return;
    }
    for (int i = 2; argv[i]; i++) {
        if (i > 2)
            value = my_strncat_dup(value, " ", 1);
        value = my_strncat_dup(value, argv[i], my_strlen(argv[i]));
    }
    value = my_strncat_dup(value, ")", 1);
    pushback_alias(argv[1], value, &shell->alias);
}

int do_alias(char **argv, shell_t *shell)
{
    int len = count_str(argv);

    if (len == 1) {
        print_all_alias(shell->alias);
        return (0);
    }
    if (len == 2)
        return (0);
    make_alias(argv, shell, len);
    return (0);
}