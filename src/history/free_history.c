/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** history
*/

#include <my.h>
#include <minishell.h>

void free_history(shell_t *shell)
{
    if (shell->history == NULL || shell->reverse == NULL) {
        return ;
    }
    list_history_t *tmp;
    list_history_t *tmp_two;
    for (tmp = shell->history; tmp != NULL; tmp = tmp->next) {
        free(tmp);
    }
    shell->history = NULL;
    for (tmp_two = shell->reverse; tmp_two != NULL; tmp_two = tmp_two->next)
        free(tmp_two);
    shell->reverse = NULL;
}