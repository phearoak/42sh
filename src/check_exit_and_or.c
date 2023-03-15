/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** check if which next separator is next and do action
*/

#include <minishell.h>

int check_exit_and_or(int *check, int *check_exit, list_sh_t **list)
{
    if (*check == 777) {
        *check = 0;
        *check_exit = 1;
    }
    if (*check == 0 && (*list)->separator == 6)
        jump_command_until_semicolon(list);
    if (*check != 0 && (*list)->separator == 7) {
        jump_command_until_semicolon(list);
    }
    return (0);
}