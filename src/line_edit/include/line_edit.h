/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** lien edit
*/

#ifndef __LINE_EDIT_H__
#define __LINE_EDIT_H__

#define cursorforward(x) printf("\033[%dC", (x)); fflush(stdout)
#define cursorbackward(x) printf("\033[%dD", (x)); fflush(stdout)

#include <minishell.h>

char *line_ncu(shell_t *shell);
void ring_bell(shell_t *shell);
char *add_at_index(char *str, int index, char c);
char *remove_at_index(char *str, int index);
int end_key(int key, int *pos, int max);
int del_key(int key, int *pos, char **str, shell_t *shell);
int back_key(int key, int *pos, char **str, shell_t *shell);
int move_in_line(int key, int *pos, int max_pos, shell_t *shell);
int arrow_up(int key, shell_t *shell, int *hist_pos, char **str);
int scroll_key(int key, shell_t *shell);
int get_history_len(shell_t *shell);
char *get_history_at_pos(shell_t *shell, int index);
int new_line(int key);
void print_command(char *str, int pos, int max_pos);
void print_first_prompt(void);
int tab_key(int key, shell_t *shell, char **str, int *pos);
void default_case(int key, char **str, int *pos);

#endif /* !__LINE_EDIT_H__ */