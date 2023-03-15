/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** history header
*/

#ifndef __HISTORY_H__
#define __HISTORY_H__

typedef struct list_history_s list_history_t;

struct list_history_s {
    int index;
    char *hour;
    char *command;
    list_history_t *next;
};

#include <minishell.h>

// int do_command_history(list_history_t *history, char *command);
char *do_command_exclamation(char *command, list_history_t *history);
// char *do_command_exclamation(char *command, list_history_t *history);
void free_history(shell_t *shell);

#endif /* !HISTORY */
