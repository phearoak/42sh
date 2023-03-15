/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** arrow handling
*/

#include <minishell.h>
#include <my.h>

int move_in_line(int key, int *pos, int max_pos, shell_t *shell)
{
    if (key == KEY_RIGHT) {
        if (*pos < max_pos)
            (*pos)++;
        else
            ring_bell(shell);
        return (1);
    }
    if (key == KEY_LEFT) {
        if (*pos > 0)
            (*pos)--;
        else
            ring_bell(shell);
        return (1);
    }
    return (0);
}

int arrow_down(int key, shell_t *shell, int *hist_pos, char **str)
{
    int max_pos = get_history_len(shell);

    if (key == KEY_DOWN) {
        if (*hist_pos < max_pos) {
            (*hist_pos)++;
        } else {
            ring_bell(shell);
            return (1);
        }
        if (*hist_pos == max_pos)
            *str = my_strdup(shell->save);
        else
            *str = get_history_at_pos(shell, (*hist_pos));
        return (2);
    }
    return (0);
}

int arrow_up(int key, shell_t *shell, int *hist_pos, char **str)
{
    int max_pos = get_history_len(shell);

    if (*hist_pos == max_pos)
        shell->save = my_strdup((*str));
    if (key == KEY_UP) {
        if (*hist_pos > 0) {
            (*hist_pos)--;
            *str = get_history_at_pos(shell, (*hist_pos));
            return (2);
        } else
            ring_bell(shell);
        return (1);
    }
    return (arrow_down(key, shell, hist_pos, str));
}