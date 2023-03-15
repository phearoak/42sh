/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** scroll_keys
*/

#include <minishell.h>
#include <my.h>

int scroll_key(int key, shell_t *shell)
{
    if (key == 258) {
        ring_bell(shell);
        printf("\eD");
        fflush(stdout);
        return (1);
    }
    if (key == 259) {
        ring_bell(shell);
        printf("\eM");
        fflush(stdout);
        return (1);
    }
    return (0);
}