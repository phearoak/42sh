/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** variables
*/

#ifndef __VARIABLES_H__
#define __VARIABLES_H__

#include <minishell.h>

int do_variables(char **argv, shell_t *shell);
char **split_var(char *str);
void print_all_vars(shell_t *shell);
void pushback_var(char *name, char *value, var_t **list);
int variable_is_set(shell_t *shell, char *ref);
int unset_variable(shell_t *shell, char **argv);
char *variable_value(shell_t *shell, char *ref);
char **get_variables(char **argv, shell_t *shell);
int char_is_alpha_num(char c);
int char_is_alpha(char c);
int str_is_alpha_num(char *str);
int str_is_num(char *str);
int char_is_num(char c);
char *delete_slash(char *str);
void init_variables(shell_t *s);
int is_equal(char *str);
int var_equal(char *str, shell_t *shell);
int var_normal(char **argv, shell_t *shell, int *i);
int make_var(char **argv, shell_t *shell);

#endif /* !__VARIABLES_H__ */