/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** check if invalid null command with pipes
*/

#include <minishell.h>
#include <my.h>

int check_wrong_pipes(char **array)
{
    int pipes = 0;

    for (int i = 0; array[i]; i++) {
        if (i == 0 && array[i][0] == '|' && array[i][1] == '\0') {
            my_putstr_error("Invalid null command.\n");
            return (-1);
        }
        if (array[i][0] == '|' && array[i][1] == '\0')
            pipes += 1;
        if (!(array[i][0] == '|' && array[i][1] == '\0'))
            pipes = 0;
        if (pipes == 2 || (pipes == 1 && array[i + 1] == NULL)) {
            my_putstr_error("Invalid null command.\n");
            return (-1);
        }
    }
    return (0);
}