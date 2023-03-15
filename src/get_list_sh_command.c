/*
** EPITECH PROJECT, 2021
** Minishell2
** File description:
** get list of sh command
*/

#include <minishell.h>
#include <my.h>

int add_command_redirect_right(char **array, int *i, list_sh_t **list)
{
    if (array[*i + 1][0] == '>' && array[*i + 1][1] == '\0') {
        if (array[*i + 2]) {
            list_sh_push_back(list, array[*i], 2, array[*i + 2]);
            *i = *i + 2;
            return (1);
        }
    }
    if (array[*i + 1][0] == '>' && array[*i + 1][1] == '>' &&
    array[*i + 1][2] == '\0') {
        if (array[*i + 2]) {
            list_sh_push_back(list, array[*i], 3, array[*i + 2]);
            *i = *i + 2;
            return (1);
        }
    }
    return (0);
}

int add_command_redirect_left(char **array, int *i, list_sh_t **list)
{
    if (array[*i + 1][0] == '<' && array[*i + 1][1] == '\0') {
        list_sh_push_back(list, array[*i], 4, NULL);
        return (1);
    }
    if (array[*i + 1][0] == '<' && array[*i + 1][1] == '<' &&
    array[*i + 1][2] == '\0') {
        list_sh_push_back(list, array[*i], 5, NULL);
        return (1);
    }
    return (0);
}

void add_command_in_list(char **array, int *i, list_sh_t **list)
{
    if (array[*i + 1] == NULL || (array[*i + 1][0] == ';' &&
    array[*i + 1][1] == '\0')) {
        list_sh_push_back(list, array[*i], 0, NULL);
        return;
    }
    if (array[*i + 1][0] == '|' && array[*i + 1][1] == '\0')
        list_sh_push_back(list,  array[*i], 1, NULL);
    if (add_command_redirect_right(array, i, list) == 1)
        return;
    if (add_command_redirect_left(array, i, list) == 1)
        return;
    if (array[*i + 1][0] == '|' && array[*i + 1][1] == '|' &&
    array[*i + 1][2] == '\0') {
        list_sh_push_back(list, array[*i], 6, NULL);
        return;
    }
    if (array[*i + 1][0] == '&' && array[*i + 1][1] == '&' &&
    array[*i + 1][2] == '\0')
        list_sh_push_back(list, array[*i], 7, NULL);
}

list_sh_t *fill_list_sh_command(char **array)
{
    list_sh_t *list = NULL;

    for (int i = 0; array[i]; i++) {
        if (check_if_command(array[i][0]) == 0 ||\
        check_space_before_redirect(array, i) == 0) {
            add_command_in_list(array, &i, &list);
        }
    }
    return (list);
}

int get_list_sh_command(char *line, list_sh_t **list)
{
    char **array = NULL;

    array = split_sh_command(line);
    if (array == NULL) {
        *list = NULL;
        return (0);
    }
    if (check_wrong_pipes(array) == -1)
        return (-1);
    sort_sh_command(array);
    *list = fill_list_sh_command(array);
    return (0);
}