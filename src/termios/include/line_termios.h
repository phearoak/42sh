/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** line termios
*/

#ifndef __LINE_TERMIOS_H__
#define __LINE_TERMIOS_H__

#define cursleft(x) printf("\033[%dD", x); fflush(stdout)
#define cursright(x) printf("\033[%dC", x); fflush(stdout)

#include <minishell.h>

typedef struct my_ter_s my_ter_t;

struct my_ter_s
{
    int pos;
    int max_pos;
    int spe;
    int key;
    int hist_pos;
    char *str;
};

char *line_termios(shell_t *shell);
int move_in_line_t(int key, int *pos, int max_pos, shell_t *shell);
int del_key_ter(int key, int *pos, char **str, shell_t *shell);
int back_key_ter(int key, int *pos, char **str, shell_t *shell);
int end_key_ter(int key, int *pos, int max);
int arrow_up_t(int key, shell_t *shell, int *hist_pos, char **str);
int arrow_down_t(int key, shell_t *shell, int *hist_pos, char **str);
void print_prompt_ter(char *str, int pos, int max_pos, shell_t *shell);
char *check_rmstar(char *str, shell_t *shell);

#endif /* !__LINE_TERMIOS_H__ */