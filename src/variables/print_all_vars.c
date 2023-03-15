/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** print all vars
*/

#include <minishell.h>
#include <my.h>

void print_all_vars(shell_t *shell)
{
    var_t *tmp = shell->vars;

    while (tmp) {
        if (!tmp->value || my_strcmp(tmp->value, "") != 0)
            printf("%s\t%s\n", tmp->name, tmp->value);
        else
            printf("%s\n", tmp->name);
        tmp = tmp->next;
    }
}