/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** unset variables
*/

#include <minishell.h>
#include <my.h>

void make_unset(shell_t *shell, char *ref)
{
    var_t *tmp = shell->vars;

    if (!tmp)
        return;
    if (my_strcmp(tmp->name, ref) == 0) {
        shell->vars = shell->vars->next;
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

int unset_variable(shell_t *shell, char **argv)
{
    if (count_str(argv) == 1) {
        my_putstr_error("unset: Too few arguments.\n");
        return (1);
    }
    for (int i = 1; argv[i]; i++)
        make_unset(shell, argv[i]);
    return (0);
}