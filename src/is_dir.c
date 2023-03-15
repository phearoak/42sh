/*
** EPITECH PROJECT, 2021
** is dir
** File description:
** is dir
*/

#include <my.h>
#include <minishell.h>

int is_dir(char *path)
{
    struct stat sb;

    if (stat(path, &sb) != 0) {
        my_putstr_error(path);
        my_putstr_error(": No such file or directory.\n");
        return (84);
    }
    if (S_ISDIR(sb.st_mode) == 0) {
        my_putstr_error(path);
        my_putstr_error(": Not a directory.\n");
        return (84);
    }
    return (0);
}