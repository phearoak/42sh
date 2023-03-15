/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** backticks
*/

#ifndef __BACKTICKS_H__
#define __BACKTICKS_H__

#include <minishell.h>

char **do_backticks(char **argv, shell_t *shell);
int check_backtick(char c, int check);
char **get_exec(char *command, char **tab);

#endif /* !__BACKTICKS_H__ */