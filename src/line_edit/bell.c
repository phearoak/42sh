/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** bell ring
*/

#include <minishell.h>
#include <my.h>

void ring_bell(shell_t *shell)
{
    do_spe_alias("beepcmd", shell);
    if (variable_is_set(shell, "visiblebell") == 1) {
        flash();
        return;
    }
    if (variable_is_set(shell, "nobeep") == 0)
        write(1, "\a", 1);
}