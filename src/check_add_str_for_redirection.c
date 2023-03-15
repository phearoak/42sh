/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** check add str for redirection
*/

#include <minishell.h>
#include <my.h>

int check_space_before_redirect(char **array, int i)
{
    if (array[i][0] == ' ' && array[i + 1] && (array[i + 1][0] == '<' ||\
    array[i + 1][0] == '>'))
        return (0);
    return (-1);
}

char **check_add_str_for_redirection(char **array)
{
    int tmp = 0;
    int command = -1;

    for (int i = 0; array[i]; i++) {
        tmp = check_if_command(array[i][0]);
        if (tmp == -1 && command == -1 && (array[i][0] == '<' ||\
        array[i][0] == '>')) {
            array = add_str_at_index(array, strdup(" "), i);
            i++;
        }
        command = tmp;
    }
    return (array);
}