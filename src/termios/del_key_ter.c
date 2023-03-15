/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** del key
*/

#include <minishell.h>
#include <my.h>

int del_key_ter(int key, int *pos, char **str, shell_t *shell)
{
    int max = my_strlen(*str);

    if (key == 126) {
        if (*pos == max) {
            ring_bell(shell);
            return (1);
        }
        *str = remove_at_index(my_strdup(*str), *pos);
        return (1);
    }
    return (back_key(key, pos, str, shell));
}

int back_key_ter(int key, int *pos, char **str, shell_t *shell)
{
    if (key == 127) {
        if (*pos == 0) {
            ring_bell(shell);
            return (1);
        }
        *str = remove_at_index(my_strdup(*str), *pos - 1);
        (*pos)--;
        return (1);
    }
    return (0);
}