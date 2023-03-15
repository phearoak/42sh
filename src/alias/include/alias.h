/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** alias
*/

#ifndef __ALIAS_H__
#define __ALIAS_H__

#include <minishell.h>

int do_alias(char **argv, shell_t *shell);
int do_unalias(char **argv, shell_t *shell);
char *get_alias(char *argv, shell_t *shell);
char *get_alias_command(char *name, alias_t *alias);
void do_spe_alias(char *name, shell_t *shell);

#endif /* !__ALIAS_H__ */