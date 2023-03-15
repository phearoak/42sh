/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** check backtick
*/

#include <minishell.h>

int check_backtick(char c, int check)
{
    if (c == '`')
        return (check + 1);
    return (check);
}