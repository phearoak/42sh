/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** rmsatr
*/

#include <minishell.h>
#include <my.h>

char *check_rmstar(char *str, shell_t *shell)
{
    int key = 0;

    if (my_strcmp(str, "rm *") == 0 && variable_is_set(shell, "rmstar") == 1) {
        printf("Do you really want to delete all files? [N/y] ");
        fflush(stdout);
        key = getchar();
        if (key == 'y' || key == 'Y')
            return (str);
        else
            return ("");
        shell->tab = 1;
    }
    return (str);
}