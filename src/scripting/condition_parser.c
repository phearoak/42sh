/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** condition parser
*/

#include <my.h>
#include <minishell.h>

static int is_valid_condition(char *line, int *type, int *start, int last)
{
    int n_equal = 0;
    int equal = 0;

    for (int i = *start; i <= last; i++)
        if (line[i] == '=') {
            n_equal++;
            equal = i;
            *start = i;
        }
    if (n_equal == 0 || n_equal > 2)
        return (0);
    if (my_strncmp(line + equal - 1, "==", 2) == 0)
        *type = 1;
    else if (my_strncmp(line + equal - 1, "!=", 2) == 0)
        *type = 2;
    if (*type != 0)
        return (1);
    return (0);
}

static int valid_parenthesis(char *line, int *start, int *last)
{
    int n_first = 0;
    int n_second = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '(') {
            *start = i;
            n_first++;
        }
        if (line[i] == ')') {
            *last = i;
            n_second++;
        }
    }
    if (n_first == 0 || n_first > 1 || n_first != n_second)
        return (0);
    return (1);
}

int verify_condition(char *line, int start, int equal_start, int cmd_start)
{
    int value = 0;
    char *operator;
    char *left_side;
    char *right_side;

    operator = my_strdup_target(line, equal_start - 1, equal_start);
    left_side = my_strdup_target(line, start + 1, equal_start - 2);
    right_side = my_strdup_target(line, equal_start + 1, cmd_start - 1);
    if (my_strcmp("==", operator) == 0)
        value = atoi(left_side) == atoi(right_side);
    else if (my_strcmp("!=", operator) == 0)
        value = atoi(left_side) != atoi(right_side);
    free(operator);
    free(left_side);
    free(right_side);
    return (value);
}

int parse_conditions(shell_t *shell, char *line)
{
    int type = 0;
    int start = 0;
    int last = 0;
    int equal_start = 0;
    int cmd_start;
    list_sh_t *list;

    if (!valid_parenthesis(line, &start, &last))
        return (-1);
    cmd_start = last;
    equal_start = start;
    if (!is_valid_condition(line, &type, &equal_start, last))
        return (0);
    if (!verify_condition(line, start, equal_start, cmd_start))
        return (0);
    do_line_before(&list, shell, &line[last + 1]);
    return (1);
}