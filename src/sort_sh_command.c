/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** sort sh command
*/

#include <minishell.h>

void check_reverse_sh_command(char **array, int i)
{
    char *tmp = NULL;

    if (check_if_command(array[i][0]) == -1)
        return;
    if (array[i + 1] && array[i + 1][0] == '<' && array[i + 1][1] == '<' &&
    array[i + 1][2] == '\0') {
        if (array[i + 2]) {
            change_str_command_redirect(&array[i], array[i + 2]);
            tmp = array[i];
            array[i] = array[i + 2];
            array[i + 2] = tmp;
        }
    }
    if (array[i + 1] && array[i + 1][0] == '<' && array[i + 1][1] == '\0') {
        if (array[i + 2]) {
            change_str_command_redirect(&array[i], array[i + 2]);
            tmp = array[i];
            array[i] = array[i + 2];
            array[i + 2] = tmp;
        }
    }
}

void sort_sh_command(char **array)
{
    for (int i = 0; array[i]; i++) {
        check_reverse_sh_command(array, i);
    }
}