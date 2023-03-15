/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** do alias
*/

#include <minishell.h>
#include <my.h>

void make_unalias(shell_t *shell, char *ref)
{
    alias_t *tmp = shell->alias;

    if (!tmp)
        return;
    if (my_strcmp(tmp->name, ref) == 0) {
        shell->alias = shell->alias->next;
        return;
    }
    while (tmp->next) {
        if (my_strcmp(tmp->next->name, ref) == 0) {
            tmp->next = tmp->next->next;
            return;
        }
        tmp = tmp->next;
    }
}

int do_unalias(char **argv, shell_t *shell)
{
    int len = count_str(argv);

    if (len == 1) {
        my_putstr_error("unalias: Too few arguments.\n");
        return (1);
    }
    for (int i = 1; argv[i]; i++)
        make_unalias(shell, argv[i]);
    return (0);
}