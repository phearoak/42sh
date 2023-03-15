/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** variables is set
*/

#include <minishell.h>
#include <my.h>

int variable_is_set(shell_t *shell, char *ref)
{
    var_t *tmp = shell->vars;

    while (tmp) {
        if (my_strcmp(tmp->name, ref) == 0)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

char *variable_value(shell_t *shell, char *ref)
{
    var_t *tmp = shell->vars;
    char *tmp_env = get_value_env(ref, shell->env);

    if (tmp_env)
        return (tmp_env);
    while (tmp) {
        if (my_strcmp(tmp->name, ref) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }
    my_putstr_error(ref);
    my_putstr_error(": Undefined variable\n");
    return (NULL);
}