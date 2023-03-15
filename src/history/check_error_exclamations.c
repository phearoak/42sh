/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** history
*/

#include <my.h>
#include <minishell.h>

void event_not_found(shell_t *shell)
{
    printf("%s: Event not found.\n", shell->unavailable + 1);
}