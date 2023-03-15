/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** jump command until semicolon
*/

#include <minishell.h>

void jump_command_until_semicolon(list_sh_t **list)
{
    list_sh_t *node = *list;

    while (node->separator != 0 && node->next != NULL) {
        node = node->next;
    }
    *list = node;
}