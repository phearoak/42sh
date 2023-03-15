/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** builtins
*/

#ifndef __BUILTINS_H__
#define __BUILTINS_H__

#include <minishell.h>

int do_builtins(void);
int do_exec(shell_t *shell, char **argv);
int do_glob(shell_t *shell, char **argv);
int do_printenv(shell_t *shell, char **argv);
int do_repeat(shell_t *shell, char **argv);
int do_where(shell_t *shell, char **argv);
int do_which(shell_t *shell, char **argv);

#endif /* !__BUILTINS_H__ */