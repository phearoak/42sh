/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** get history len
*/

#include <minishell.h>
#include <my.h>

int get_history_len(shell_t *shell)
{
    list_history_t *tmp = shell->history;
    int len = 0;

    while (tmp) {
        len++;
        tmp = tmp->next;
    }
    return (len);
}

char *get_history_at_pos(shell_t *shell, int index)
{
    list_history_t *tmp = shell->history;
    int i = 0;

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
    return (my_strdup(tmp->command));
}