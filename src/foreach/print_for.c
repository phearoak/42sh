/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** foreach
*/

#include <minishell.h>
#include <my.h>

void print_for(void)
{
    if (isatty(0) != 0) {
        printf("foreach? ");
        fflush(stdout);
    }
}