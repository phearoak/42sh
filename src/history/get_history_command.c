/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** history
*/

#include <my.h>
#include <minishell.h>

int get_command_positif(list_history_t *history, shell_t *shell, int index)
{
    for (list_history_t *tmp = history; tmp != NULL; tmp = tmp->next) {
        if (index == tmp->index) {
            shell->to_swap_cmd = tmp->command;
            return (1);
        }
    }
    return (0);
}

int get_command_negatif(list_history_t *reverse, shell_t *shell, int index)
{
    for (list_history_t *tmp = reverse; tmp != NULL; tmp = tmp->next) {
        if (reverse->index + index + 1 == tmp->index) {
            shell->to_swap_cmd = tmp->command;
            return (1);
        }
    }
    return (0);
}

int get_command_str(list_history_t *reverse, shell_t *shell, char *cmd)
{
    for (list_history_t *tmp = reverse; tmp != NULL; tmp = tmp->next) {
        if (strncmp(cmd, tmp->command, strlen(cmd))  == 0) {
            shell->to_swap_cmd = tmp->command;
            return (1);
        }
    }
    return (0);
}

int get_command_global(list_history_t *reverse, shell_t *shell, char *cmd)
{
    char *str = NULL;

    for (list_history_t *tmp = reverse; tmp != NULL; tmp = tmp->next) {
        if ((str = strstr(my_strdup(tmp->command), cmd)) != NULL) {
            shell->to_swap_cmd = tmp->command;
            return (1);
        }
    }
    return (0);
}