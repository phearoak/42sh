/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** check if there is an error in exec
*/

#include <minishell.h>

int check_incompatible_binary(char *path, int status)
{
    if (status == -1) {
        exec_failed(path);
        return (84);
    }
    return (0);
}

int check_segfault(int status, int waiting)
{
    if (status != 0) {
        if (handle_segfault_binary(status, waiting) != 0)
            return (84);
    }
    return (0);
}