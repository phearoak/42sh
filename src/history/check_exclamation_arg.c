/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** history
*/

#include <my.h>
#include <minishell.h>

int check_exclamation_number(list_history_t *history, \
list_history_t *reverse, shell_t *shell, int index)
{
    if (index > 0) {
        if (get_command_positif(history, shell, index)) {
            shell->exclamation_use = 1;
            return (1);
        }
    }
    if (index < 0) {
        if (get_command_negatif(reverse, shell, index)) {
            shell->exclamation_use = 1;
            return (1);
        }
    }
    return (0);
}

int check_exclamation_str(list_history_t *reverse, shell_t *shell, char *cmd)
{
    if (cmd[0] != '\0' && cmd[0] != '?' && cmd[0] != '!') {
        if (get_command_str(reverse, shell, cmd)) {
            shell->exclamation_use = 1;
            return (1);
        }
    }
    return (0);
}

int check_exclamation_global(list_history_t *rev, shell_t *shell, char *cmd)
{
    if (cmd[0] == '?' && cmd[strlen(cmd) - 1] == '?') {
        cmd[strlen(cmd) - 1] = '\0';
        cmd++;
        if (get_command_global(rev, shell, cmd)) {
            shell->exclamation_use = 1;
            return (1);
        }
    }
    return (0);
}

int check_exclamation_double(list_history_t *rev, shell_t *shell, char *cmd)
{
    if (cmd[0] != '\0' && cmd[0] == '!') {
        if (rev == NULL) {
            shell->unavailable = "0";
            return (0);
        }
        shell->to_swap_cmd = rev->command;
        shell->exclamation_use = 1;
        return (1);
    }
    return (0);
}